# 工作计划：Quote 气泡随源消息 Recall 自动刷新

**方案**：保持 BE 负责 quote 组装；新增「引用关系发现 + 重组装 + FE 就地重写」三段流程，
使得 quote 一条消息后、若源消息被 recall，该 quote 气泡的 preview 自动从
`>原文…` 变为 `>[recalled]`（单行）。

对应需求：之前讨论的 **Q1**（quote 一条消息，源消息「后来」被 recall）。

---

## 1. 目标与非目标

**目标**
- 源消息被 recall（本地 recall 或收到对端 `FRAME_RECALL`）后，所有引用它的 quote 气泡
  的 preview 行自动变为 `>[recalled]`。
- 复用现有 BE 组装逻辑（`S_BUILD_QUOTE_DISP`）与已落地的 Q2 fix
  （`QB_DECIDE` 在源 `MSG_RECALLED` 时输出 `[recalled]`，见 `be_top.sv` 的
  `qb_recalled_byte` / `qb_recalled_q`）。

**非目标（本次不做）**
- 历史区「紧凑重排」：quote 气泡由多行塌成单行后，**不**把后续气泡上移填补空行。
  采用保守策略（见 §6 阶段 4）。可作为后续单独工程。
- 把组装逻辑搬到 FE（纯 FE 渲染）——已评估为更大改动，不在本方案内。

---

## 2. 现状与缺口（带定位）

- quote 的 preview 在**发送时**由 BE 组装成成品文本 `disp_payload_q`，随
  `RENDER_APPEND_*` 发给 FE（`be_top.sv` `S_ENTER_RENDER_LOCAL` ~1427-1429、
  `S_RX_RENDER` ~1459-1461），FE 一次性写进 text_ram 的历史逻辑行。
- recall 只更新**源消息自己**的气泡：`S_RECALL_RENDER` 发
  `RENDER_UPDATE_STATUS{msg_id=源}`（`be_top.sv` ~1475-1482），FE 按
  `{side,msg_id}` 找到对应行改写为 `[recalled]`（`fe_render_decoder.sv` ~1206-1240）。
- **缺口**：引用源消息的 quote 是**另一条 msg_id**，其 preview 文本已 baked，
  recall 不会触达 → preview 保持旧文本。
- FE 无周期性重绘：`REDRAW_ALL`/`SCROLL` 在 FE 仅单周期 latch、移动视窗，
  不重组装气泡（`fe_render_decoder.sv` ~818-825），所以「自然刷新」不存在，
  必须显式推送刷新命令。

**可复用基础**
- QB 组装器已能在源 recalled 时输出 `[recalled]`（Q2 已完成）。
- `fe_render_decoder` 已有 `{side,msg_id} → ring slot` 映射
  （`msg_key_valid_q` / `msg_key_row_q`，~256-257）与「改写某 slot payload 并重画」
  的雏形（recalled 分支 ~1222-1240）。

---

## 3. 方案总览（三支柱）

```
 recall 触发 (本地 / RX)
        │
        ▼
 [A] 引用发现        遍历 store，找出所有引用了「被 recall 消息」的 quote 消息
        │
        ▼
 [B] 重组装          对每个引用者重跑 S_BUILD_QUOTE_DISP（源已 recalled → QB 输出 [recalled]）
        │
        ▼
 [C] FE 就地重写      新 render 命令 RENDER_UPDATE_PAYLOAD：按 {side,msg_id} 找行，
                     写回新 payload、re-parse、重画该气泡行，并清掉变短后的多余旧行
```

---

## 4. 数据结构：如何维护 "quoting message ids"

每条 quote 消息的「被引用 ref」**本来就存在它的 store payload 前 3 字节**里：
`[0]=QUOTE_MARKER(0x01)`、`[1]=quoted_side`、`[2]=quoted_msg_id`
（`chat_pkg.sv` ~424-437）。因此引用关系无需额外持久存储。

**方案 (1)（推荐）— 隐式 + recall 时 O(N) 扫描重建**
- recall 时遍历 `MAX_MSG_NUM`(=64) 个 store slot：对每个 `valid` 且
  `payload[0]==QUOTE_MARKER` 的消息，读前 3 字节，解析出它引用的 `(side,msg_id)`，
  与刚被 recall 的消息比对，命中即为「引用者」。
- 优点：零新增持久状态、无变长 list、不需在 quote 时维护反向表。
- 成本：每次 recall 一次 64-slot 串行扫描（每 slot 读 3 字节，BRAM 1-cycle）。
  recall 是低频操作，可接受。

**方案 (2) — 显式反向索引（备选，不推荐先做）**
- 为每条消息维护「引用它的 quote slot 集合」（定长数组或 64×64 bitmap）。
- 优点：O(1) 定位。缺点：新增存储、上限难定、quote/清屏/ring-wrap 时都要同步维护，
  反而更易出错。

> **结论**：采用方案 (1)。"维护 quoting message ids" 落地为「recall 时按 payload 前缀
> 枚举引用者」，而非常驻反向表。

### ⚠ side 语义坑（必须核对，列为独立任务）
wire payload `[1]` 存的是**接收方视角**的 side（发送前已 invert，见
`chat_pkg.sv` ~426-431）。两类引用者的 `[1]` 含义不同：
- **本地发出的 quote**（store side=LOCAL）：`[1]` = 对端视角 side（已 invert）。
- **对端发来的 quote**（store side=REMOTE）：`[1]` = 我方视角 side（对端发送前已 invert 成我方视角）。

扫描匹配时需按「引用者自身的 side」决定是否把 `[1]` invert 回**本机视角**，
再与被 recall 消息的 `(side,msg_id)` 比对。务必先写一个小的真值表核对四种组合
（{本地/远端引用者} × {引用本地/远端源}）。

---

## 5. recall 的两条入口都要接 fanout
- **本地 recall**：右键菜单 → `S_RECALL_RENDER`（`be_top.sv` ~1475、~1988-1991）。
- **RX recall**：收到 `FRAME_RECALL` → 标记对应 REMOTE 消息 recalled（~1865-1868、~1126）。

> 端到端语义：Alice 本地 recall 自己的消息后会发 `FRAME_RECALL`；Bob 收到后标记其
> REMOTE 副本 recalled，并应同样刷新 Bob 端引用该消息的 quote 气泡。所以**两端、两入口**
> 都要触发 fanout。

---

## 6. 详细任务分解（按阶段）

### 阶段 0 —（已完成）QB recalled 分支
- `QB_DECIDE` 在 `store_ui_rd_status==MSG_RECALLED` 时输出 `[recalled]`。
- 已落地并有 be_top 单测覆盖（`test_local_quote_recalled_source_shows_recalled` 等）。
- 本阶段无需额外工作，后续重组装直接复用。

### 阶段 1 — BE 引用发现 FSM（`be_top.sv`）
- [ ] 新增状态：`S_RECALL_FANOUT_SCAN`（串行 walk slot 0..63）、
      `S_RECALL_FANOUT_FETCH`（读候选前 3 字节，BRAM 1-cycle）、
      `S_RECALL_FANOUT_NEXT`。
- [ ] 在 `S_RECALL_RENDER` 完成后、以及 RX recall 标记完成后，进入扫描，
      并把「刚 recall 的消息」的 `(本机视角 side, msg_id)` 锁存为扫描键。
- [ ] 匹配逻辑：`valid && payload[0]==QUOTE_MARKER` 且解析出的 ref（经 side 归一化）
      == 扫描键 → 记下该引用者 `store_idx / msg_id / side`，转入阶段 2 重组装；
      重组装完回到扫描继续下一个 slot。
- [ ] BRAM 读口仲裁：扫描读口与渲染/组装读口不能冲突（串行化或复用 `rd2`/byte 口）。

### 阶段 2 — BE 重组装（复用 `S_BUILD_QUOTE_DISP`）
- [ ] 以引用者的 wire payload 作为组装输入（载入 `pending_payload_q` 等价物），
      设置 `quoted_side_q/quoted_msg_id_q` = 引用者的 ref。
- [ ] 跑 QB：源此时已 `MSG_RECALLED`，`QB_DECIDE` 自然走 `qb_recalled_byte` →
      产出 `disp_payload_q = ">[recalled]\n" + user`。
- [ ] 注意 `disp_len_q` 在复用后清理（参考已有
      `test_local_send_after_remote_quote_uses_local_payload` 暴露过的 stale 问题）。

### 阶段 3 — 新 render 命令 `RENDER_UPDATE_PAYLOAD`（`chat_pkg.sv` + 两端）
- [ ] `chat_pkg.sv`：`render_cmd_e` 新增枚举值 `RENDER_UPDATE_PAYLOAD`。
- [ ] BE：fanout 对每个引用者发 `RENDER_UPDATE_PAYLOAD{side, msg_id, len, payload}`。
- [ ] FE（`fe_render_decoder.sv`）：`S_IDLE` 收到 →
      用 `msg_key_*` 查到 ring slot（无效则跳过）→ 仿 recalled 路径：
      把新 payload 写回该 slot BRAM、re-parse newlines（更新 `slot_n_lines_q`、
      `ml_offset_q/ml_len_q`）、走 `S_HIST_WRITE` 重画气泡行。

### 阶段 4 — 行高变化处理（难点，保守策略）
- 多行 preview 塌成更短（极端为单行 `[recalled]`）后，旧气泡占用的多余行要清空。
- [ ] **决策（保守）**：重写范围 = 该气泡**原本占用的行数**（用旧
      `slot_n_lines_q`）；新内容更短时尾部行清成空白，**不移动后续气泡**。
- [ ] 复用 recalled 分支已有的「清空残留行」做法（参考 `fe_render_decoder.sv`
      ~1222-1236 与 fe_top 测试 `test_recall_collapses_multiline_to_single_line`
      中 row1/row2 清空的断言模式）。
- 影响：塌缩后下方会留若干空行，但不破坏其它气泡与 scroll。紧凑重排列为后续。

### 阶段 5 — 测试
**be_top（`sim/tb/be_top/sim_main.cpp`）**
- [ ] 本地 recall 源 → 引用它的本地 quote 收到 `RENDER_UPDATE_PAYLOAD`，
      payload == `>[recalled]\nuser`。
- [ ] 多个引用者：两条 quote 引用同一源，recall 后都被刷新。
- [ ] 非引用者不受影响（不应收到 `UPDATE_PAYLOAD`）。
- [ ] RX recall（收到 `FRAME_RECALL`）→ 引用该远端消息的 quote 被刷新。
- [ ] side 归一化真值表四组合各一条用例。
- [ ] 引用者本身已 recalled → 跳过（不重复刷新 / 不崩 FSM）。

**fe_top（`sim/tb/fe_top/sim_main.cpp`）**
- [ ] `RENDER_UPDATE_PAYLOAD` 就地把某气泡从多行 `>原文\nuser` 重写为
      `>[recalled]\nuser`，并验证原多余行被清空（行高保守策略）。
- [ ] LOCAL（右对齐）与 REMOTE（左对齐）各一条。

**chat_top_pair（可选，端到端）**
- [ ] Alice quote Bob 的消息；Bob recall 该消息；验证 Alice 端该 quote 气泡变
      `[recalled]`（双向：Bob 端引用同源的 quote 亦然）。

### 阶段 6 — 回归
- [ ] `make test`：22 个 TB 全绿（重点 be_top / fe_top / chat_top / chat_top_pair）。

---

## 7. 边界情况清单
- 引用者已滚出可视区：仍在 ring 内则照常重写其逻辑行，scroll 回来正确；
  若已被 ring wrap 覆盖（`msg_key` 失效）→ 跳过。
- 一条消息被多条引用 / 一条 quote 引用多源（嵌套）。
- 引用者本身是 quote-of-quote（`> [quoted]` 占位）：组装逻辑已有，照常。
- 引用者本身已被 recall：跳过。
- recall 扫描期间的 store 写 / render 背压：确保扫描不破坏在途写流。

## 8. 风险
| 风险 | 等级 | 缓解 |
|---|---|---|
| 行高变化导致布局错乱 | 中 | 保守策略：不重排，仅清尾部多余行（阶段 4）|
| side 语义匹配错 | 中 | 先写真值表 + 四组合单测（§4 / 阶段 5）|
| BRAM 读口争用（扫描 vs 组装 vs 渲染）| 中 | 串行化 FSM，复用现有读口 |
| FSM 复杂度上升、两条 recall 入口 | 低-中 | 共用同一 fanout 子状态机 |

## 9. 工作量估计
> 假设：单人、熟悉本仓库、含单测；不含紧凑重排。

- 阶段 1+2（BE 发现 + 重组装）：约 **1–1.5 天**（核心 FSM + side 归一化）。
- 阶段 3+4（pkg + FE 就地重写 + 行清理）：约 **1–1.5 天**（FE 流水线 + 行高保守处理）。
- 阶段 5+6（测试 + 回归）：约 **0.5–1 天**。
- **合计：约 2.5–4 天**，主要不确定性在阶段 4（FE 行处理）。

## 10. 里程碑
- **M1**：BE 引用发现可命中（be_top 单测验证扫描找到正确引用者）。
- **M2**：重组装 + `RENDER_UPDATE_PAYLOAD` 在 BE 侧产出正确 payload（be_top 验证）。
- **M3**：FE 就地重写 + 多余行清空（fe_top 验证）。
- **M4**：端到端 + 全量回归通过。
