# 综合性能优化备忘

## 背景

P2 把 `MAX_MSG_LEN = MAX_LINE_LEN = 640` 后,Vivado 2019.2 在 Artix-7
200T 上做 `synth_design` 时:

- RTL Elaboration 阶段 ~4 分钟(此前 ~3 秒)
- 内存峰值 23 GB
- 大量 LUT 用作 distributed RAM 寄存器堆 + 宽 mux,综合后时序紧

回归到 `MAX_MSG_LEN = 128` 把单次 unroll 步数缩到 1/5,elab 时间和内存
预算能回到原来的量级。但如果将来确实需要更长的消息,有两条独立的优化
路径,可以分别落地、组合使用。

---

## 根本原因 / 哪些代码是热点

Vivado RTL elaboration 把 `for i = 0; i < <const>; i++` 的 procedural
loop 完全展开成 `<const>` 份显式 mux 和常量传播。`<const>` 越大代价
越高(不是线性,接近平方):mux 的输入数、信号扇出、常量传播的工作量
都跟着涨。

项目里有 **4 处主要的 unrolled 大循环**,都受 `MAX_MSG_LEN` /
`MAX_LINE_LEN` 直接驱动:

1. `rtl/backend/be_top.sv:665` — `KEY_CHAR` 在 `cursor_pos_q` 插入字符
   的并行右移:`for (int i = 0; i < MAX_LINE_LEN; i++)`。每次迭代构造
   `if (i == cursor_pos)`/`if (i > cursor_pos && i <= len_q)` 等 i 依
   赖条件。
2. `rtl/backend/be_top.sv:685` — `KEY_BACKSPACE` 的并行左移:同形状。
3. `rtl/frontend/fe_render_decoder.sv` `RENDER_INSERT_AT_CURSOR` /
   `RENDER_DELETE_AT_CURSOR` accept 路径里同样的 MAX_LINE_LEN 大循环。
   (BE 和 FE 各持有一份 `line_buf` 镜像。)
4. `rtl/frontend/fe_render_decoder.sv` 里 3 处 newline-parse loop
   `for (int i = 0; i < MAX_MSG_LEN; i++)`(`RENDER_APPEND_*` accept、
   `RENDER_UPDATE_STATUS` accept、`S_INPUT_PARSE` 状态)。

此外 `slot_payload_q [N_HIST_STORED]` 这个 64 × 5120-bit 寄存器堆 +
配套的 640-input dynamic bit slice 也是 LUT 大户,但它不直接占 elab
时间,影响的是综合后 LUT 数和时序。

---

## 路径 A:`slot_payload_q` 改成 BRAM(rolled-out)

### 动机

64 × 640 bytes = 41 KB 的寄存器堆是浪费。Artix-7 有 365 个 BRAM18
(821 KB 总量),挪进 BRAM 大约用 20 块,占 5% 不到。同时:

- 释放大量 LUT(目前作 distributed RAM 用)
- 消除 640-input bit-slice mux(渲染路径)
- 改进综合后时序

### 设计要点

#### 新模块 `rtl/frontend/fe_msg_payload_ram.sv`

仿 `fe_text_ram.sv` 的两套 always_ff 写/读模式。单口写、单口读、读延
迟 1 cycle。地址空间 `{slot, byte_idx}`,所以 `N_HIST_STORED` 必须是
2 的幂(目前 64,满足)。

```systemverilog
module fe_msg_payload_ram
    import chat_pkg::*;
    import fe_pkg::*;
(
    input  logic                                  wr_clk,
    input  logic                                  wr_en,
    input  logic [HIST_W-1:0]                     wr_slot,
    input  logic [$clog2(MAX_MSG_LEN)-1:0]        wr_byte_idx,
    input  byte_t                                 wr_data,

    input  logic                                  rd_clk,
    input  logic [HIST_W-1:0]                     rd_slot,
    input  logic [$clog2(MAX_MSG_LEN)-1:0]        rd_byte_idx,
    output byte_t                                 rd_data
);
    localparam int DEPTH = N_HIST_STORED * MAX_MSG_LEN;
    byte_t mem [DEPTH];

    always_ff @(posedge wr_clk) begin
        if (wr_en) mem[{wr_slot, wr_byte_idx}] <= wr_data;
    end

    byte_t rd_q;
    always_ff @(posedge rd_clk) begin
        rd_q <= mem[{rd_slot, rd_byte_idx}];
    end
    assign rd_data = rd_q;
endmodule
```

#### fe_render_decoder 改动

- 删掉 `slot_payload_q [N_HIST_STORED]` 寄存器声明。
- 保留 `payload_q [MAX_MSG_LEN*8-1:0]` 作为"当前正在渲染的那条消息"
  的工作寄存器(渲染 `S_HIST_WRITE` / `S_UPDATE_STATUS` 的 cell
  lookup 不变)。
- 新增两个 FSM 状态:
  - `S_HIST_STORE`:在 `RENDER_APPEND_*` accept 后进入,逐字节把
    `payload_q[i*8 +: 8]` 写到 BRAM 的 `(hist_wr_row_q, i)`。640 cycle
    × 100 MHz = 6.4 µs。完成后进入 `S_HIST_WRITE` 渲染。
  - `S_HIST_LOAD`:在 `RENDER_UPDATE_STATUS` accept 后进入(替代当前
    的 `payload_q <= slot_payload_q[slot]`),逐字节从 BRAM 读出写到
    `payload_q`。640 cycle。完成后进入 `S_UPDATE_STATUS`。
- 注意 BRAM 读延迟 1 cycle:`rd_addr` 在 cycle N 给出,`rd_data`
  在 cycle N+1 出来。`S_HIST_LOAD` 的字节计数器要管好。

#### 收益预估

- LUT 数:大幅下降(主要是消掉 distributed RAM 和 640-input mux)
- BRAM 用量:~20 个 BRAM18
- elab 时间:**降一半左右**,因为 `slot_payload_q[]` 寄存器堆的展
  开消失了,但路径 B 的 4 个 unrolled for 仍然存在
- 渲染延迟:APPEND / UPDATE_STATUS 多 6.4 µs 预热

### 风险

- BRAM 读 pipeline 的 off-by-one,典型 bug。可以靠 `fe_text_ram.sv`
  的对照(scan 端怎么算 `s0_text_ram_row` 比 `s1_text_ram_row`
  早一拍)。
- 现有 tests 在 wait_ready 之间多等几百 cycle,需要确认 timeout 足够。

---

## 路径 B:把 4 个 unrolled for 改成多 cycle FSM

### 动机

这是 elab 时间膨胀的**主要**原因。只要 `MAX_LINE_LEN` 取大,这 4 个
for 就以平方代价吃 elab。

### 设计要点

#### BE 的 `KEY_CHAR` / `KEY_BACKSPACE`

目前一个 cycle 内并行 shift `line_buf` 整个 640-byte 数组。改成:
- 新增状态 `S_LINE_SHIFT`,带一个字节计数器 `shift_idx_q`
- 每 cycle 移动一个字节:`line_buf[shift_idx_q] <= line_buf[shift_idx_q±1]`
- 走完后回 `S_IDLE`

边界:`KEY_CHAR` 从 `len_q` 向 `cursor_pos_q` 倒序扫;`KEY_BACKSPACE`
从 `cursor_pos_q` 向 `len_q-1` 正序扫。

#### FE 的 INSERT/DELETE 镜像

跟 BE 同型,只是寄存器是 `input_line_q`。

#### FE 的 3 处 newline-parse loop

目前在 1 个 cycle 里扫整个 payload(640 字节)找 `\n`。改成多 cycle
扫描:新增 `S_HIST_PARSE` / `S_INPUT_PARSE`(已有,只是扩成多 cycle):
- `parse_idx_q` 每 cycle +1
- 每 cycle 检查 `payload[parse_idx_q*8 +: 8] == 0x0A`
- 命中时更新 `ml_offset_q[n_lines]` / `ml_len_q[n_lines-1]`,自增
  `n_lines_q`
- 走到 `parse_idx_q == be_render_len` 退出

注意:APPEND 路径目前是"accept 当周期同时(a) latch payload (b) 解析
newline (c) 进入渲染"。解耦成 `accept → S_HIST_PARSE → S_HIST_WRITE`
三段后,APPEND 整体延迟从 ~140 cycle 涨到 ~140 + len cycle(对 640
字节最多 +6.4 µs)。

#### 收益预估

- elab 时间:**回到 < 30 秒**,因为没有任何 `<const>`-iter unroll
  了(loop 只在常量上界看,展开后变成只剩很轻的 mux)
- LUT 用量:小幅下降(消掉宽 mux)
- 综合时序:更松

### 风险

- 多 cycle 解析意味着 PARSE 期间不能响应新的 render 命令;BE 已经在
  等 `be_render_ready`,正确性应该 OK,但要在 fe_top 测试里再验证一
  下 back-to-back 的 APPEND/STATUS 流。
- 多 cycle shift 的 `KEY_CHAR` 让"打字"看起来增加几百 ns 的延迟,
  但用户键盘节奏是 ms 级,看不出来。
- 需要把 sim 里 `wait_ready` 类 helper 的 timeout 调宽。

---

## 推荐组合 + 顺序

如果将来确认要恢复 `MAX_MSG_LEN ≥ 256`,建议:

1. **先做路径 B**(unrolled-for → 多 cycle FSM)。它解决 elab 时间
   主因,而且对硬件无明显资源代价。
2. **再做路径 A**(slot_payload_q → BRAM)。它的主要收益是 LUT 解
   放和综合后时序;elab 时间是次要收益。
3. 两步都做完后,`MAX_MSG_LEN = 640` 应该跟现在 `= 128` 的成本相当。

每步都是 1 个独立 commit,~100-200 行 RTL 改动 + 配套 sim 调整。

---

## 现状(2026-05-16)

`MAX_MSG_LEN = 128` 是当前选择,作为上板验证的"够用且编译够快"
折中。两条路径目前都没启动。
