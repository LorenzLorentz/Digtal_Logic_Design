# FPGA 双端聊天系统

两块 FPGA 通过 UART 链路通信, 各自接 PS/2 键盘、PS/2 鼠标和 HDMI 显示器, 实现一对一聊天。当前实现支持连接握手、断开/重连、消息状态回显、历史滚动、多行输入、引用、撤回、小表情补全、大表情贴纸, 以及从 BaseRAM 读取的背景和头像素材。

目录结构:

```text
rtl/
  pkg/               chat_pkg.sv, fe_pkg.sv     -- 全局类型/参数
  common/            crc16, sync_2ff, debouncer, handshake_fifo
  io/                PS/2 phy + 解码 + 事件 FIFO
  comm/              UART + 帧编解码 + ARQ FSM + 仲裁
  backend/           聊天主控 (连接管理 + 输入/收发/存储)
  frontend/          render decoder + text_ram + scan + glyph_rom + sprite/asset ROM
  chat_top.sv        Verilator/仿真顶层 (无 HDMI 编码)
  chat_top_board.sv  Vivado 板级顶层 (ip_pll + ip_rgb2dvi)
sim/tb/              每个模块的 Verilator testbench
scripts/             run_test.py, gen_font.py, gen_sram_assets.py, gen_big_emoji.py
assets/              SRAM 背景/头像源图, 大表情源图
constraints/         chat_top_board.xdc (Genesys 2 / xc7a200t)
vivado/              build.tcl, ip_repo
```

---

## 1. 系统框图

`chat_top` 在单一 100 MHz 系统时钟下把 io、backend、comm、frontend 四个子系统接成一条闭环: io 把键鼠事件送给 backend, backend 既向 comm 发帧也向 frontend 推渲染命令, comm 通过一根 UART 双工链路与对端交换帧。frontend 的像素扫描另跑在 40 MHz 像素时钟域, 跨时钟量都过 `sync_2ff`。两块板各自是一套完整 `chat_top`, 仅靠 UART 对接:

```mermaid
flowchart LR
    subgraph BOARDA["FPGA A (chat_top)"]
        KBA["PS/2 键盘 + 鼠标"] --> IOA["io_top / io_mouse"]
        IOA -->|"io_key_* / mouse_*"| BEA["be_top<br/>连接 + 聊天 FSM + store"]
        BEA <-->|"be_tx / cm_rx / cm_status"| CMA["comm_top<br/>UART + 帧 + ARQ"]
        BEA -->|"be_render_*"| FEA["fe_top<br/>decoder + scan"]
        FEA -->|"RGB + sync + DE"| HDA["HDMI 显示器"]
    end
    subgraph BOARDB["FPGA B (chat_top)"]
        IOB["io_top / io_mouse"] --> BEB["be_top"]
        CMB["comm_top"] <--> BEB
        BEB --> FEB["fe_top"] --> HDB["HDMI 显示器"]
    end
    CMA <-->|"UART 双工 8N1"| CMB
```

下面用端到端时序说明几条关键路径。

(1) 上电握手 + 聊天 + ESC 断开 + SPACE 重连:

```mermaid
sequenceDiagram
    participant IO as io
    participant BE as backend
    participant FE as frontend
    participant CM as comm
    participant PEER as peer FPGA

    Note over BE: reset → S_BOOT_REDRAW
    BE->>FE: render_cmd RENDER_REDRAW_ALL (boot 屏)
    BE->>CM: be_tx(HELLO, MY_NAME)  (S_TX_HELLO)
    CM->>PEER: HELLO(seq, MY_NAME)
    Note over BE: → S_HANDSHAKE_IDLE

    PEER->>CM: HELLO(seq, peer_name)
    CM->>BE: cm_rx(HELLO, peer_name)
    BE->>BE: 存 peer_name (不同则清空 store)
    BE->>CM: be_tx(USERNAME, MY_NAME)  (S_TX_USERNAME)
    CM->>PEER: USERNAME(seq, MY_NAME)
    Note over BE: → S_RENDER_CONN_CONNECTED → S_IDLE
    BE->>FE: render_cmd RENDER_CONN_STATE (CONNECTED, peer_name)

    IO->>BE: key_event(char)
    BE->>BE: 更新输入行 (cursor insert)
    BE->>FE: render_cmd RENDER_INSERT_AT_CURSOR

    IO->>BE: key_event(enter)
    BE->>BE: 生成本地消息 msg_id, 存 Store=PENDING
    BE->>FE: render_cmd RENDER_APPEND_LOCAL_PENDING
    BE->>CM: be_tx(DATA, msg_id, payload)
    BE->>FE: render_cmd RENDER_UPDATE_INPUT_LINE (len=0)

    CM->>PEER: DATA(seq, payload)
    PEER->>CM: ACK(seq)
    CM->>BE: cm_status(msg_id, SUCCESS)
    BE->>FE: render_cmd RENDER_UPDATE_STATUS

    PEER->>CM: DATA(seq, payload)
    CM->>PEER: ACK(seq)
    CM->>BE: cm_rx(DATA, payload)
    BE->>BE: Store, side=REMOTE
    BE->>FE: render_cmd RENDER_APPEND_REMOTE

    IO->>BE: key_event(esc)
    BE->>CM: be_tx(GOODBYE)  (S_TX_GOODBYE)
    CM->>PEER: GOODBYE(seq)
    Note over BE: → S_RENDER_CONN_DISCONNECTED → S_DISCONNECTED_IDLE
    BE->>FE: render_cmd RENDER_CONN_STATE (DISCONNECTED)

    IO->>BE: key_event(char ' ')  %% SPACE
    Note over BE: → S_TX_HELLO
    BE->>CM: be_tx(HELLO, MY_NAME)
    CM->>PEER: HELLO(seq, MY_NAME)
```

(2) mid-chat 时对方重启的处理 (REHELLO 防循环):

```mermaid
sequenceDiagram
    participant A
    participant B

    Note over A: 处于 S_IDLE
    Note over B: reset → S_BOOT_REDRAW → S_TX_HELLO
    B->>A: HELLO(B_name)
    Note over A: cm_rx HELLO in S_IDLE
    A->>A: 比较 B_name 与 peer_name_q, 不同则全清 store
    A->>B: REHELLO(A_name), S_TX_REHELLO
    Note over A: 状态不变, 仍 S_IDLE

    Note over B: cm_rx REHELLO in S_HANDSHAKE_IDLE
    B->>B: 存 A_name
    B->>A: USERNAME(B_name), S_TX_USERNAME
    Note over B: → S_RENDER_CONN_CONNECTED → S_IDLE
    Note over A: cm_rx USERNAME, 状态不变
```

两块板各自编译, 通过 `MY_NAME_LEN` / `MY_NAME_PACKED` 参数把用户名硬编码进 bitstream. 链路层是单根 UART 双工对接, 上层走 stop-and-wait ARQ.

`chat_top_board.sv` 在 `chat_top.sv` 之上叠了两个 Xilinx IP:

- `ip_pll`: 100 MHz → 40 MHz pixel clock (800×600 @ 60 Hz)
- `ip_rgb2dvi`: RGB888 + sync → HDMI TMDS 差分对

`chat_top.sv` 本身只输出 RGB+sync+DE, 没有 TMDS 编码, 这样 Verilator 能直接 elaborate 整个 chat_top 做集成测试.

### SRAM 上传背景与头像

Xilinx 实验板的 4MB BaseRAM 作为只读视觉素材区使用。图片不进入 bitstream，也不要生成 HDL ROM / `$readmemh` 片上 RAM；否则综合会尝试构造接近 1MB 的片上存储，编译会非常慢甚至失败。先用脚本把图片打包成控制面板可直接写入的 raw binary：

```bash
python3 scripts/gen_sram_assets.py \
  --background path/to/background.png \
  --local-avatar path/to/me.png \
  --remote-avatar path/to/peer.png \
  --out chat_assets.bin
```

然后在实验板控制面板中把 `chat_assets.bin` 从 SRAM 字节地址 `0x0` 写入。替换壁纸或头像时只需要重新生成并写入这个 SRAM 文件，bitstream 仍读取同一套地址布局。控制面板写 SRAM 时会复位实验 FPGA；写完后需要重新下载本工程 bitstream。素材格式和地址布局：

```text
0x000000  800x600 RGB565 background, little-endian, 960000 bytes
0x0EA600  16x16 RGB565 local avatar, little-endian, 512 bytes
0x0EA800  16x16 RGB565 remote avatar, little-endian, 512 bytes
```

前端在 CONNECTED 页面读取 SRAM：聊天历史区背景使用上传背景，远端气泡左侧和本地气泡右侧显示对应头像。标题栏和输入栏仍保留固定配色，保证文字可读。

---

## 2. 子系统 (顶层模块)

| 模块            | 文件                              | 作用                                                  |
| --------------- | --------------------------------- | ----------------------------------------------------- |
| `io_top`        | `rtl/io/io_top.sv`                | PS/2 解码 → key event FIFO                            |
| `io_mouse`      | `rtl/io/io_mouse.sv`              | PS/2 鼠标初始化 + 坐标/滚轮/点击事件                   |
| `be_top`        | `rtl/backend/be_top.sv`           | 连接管理 + 聊天 FSM + 消息存储                         |
| `comm_top`      | `rtl/comm/comm_top.sv`            | UART 收发 + 帧编解码 + ARQ + ACK 仲裁                  |
| `fe_top`        | `rtl/frontend/fe_top.sv`          | render decoder + text_ram + 像素 scan + glyph_rom      |
| `chat_top`      | `rtl/chat_top.sv`                 | 四子系统互联 + reset sync                              |
| `chat_top_board`| `rtl/chat_top_board.sv`           | 板级: ip_pll + chat_top + ip_rgb2dvi                   |

---

## 3. 模块间接口

所有跨模块接口都遵循 `valid / ready` 握手. 类型/常量定义在 `rtl/pkg/chat_pkg.sv`.

### 3.1 `io_top → be_top` (键盘事件)

| 信号                  | 方向          | 含义                              |
| --------------------- | ------------- | --------------------------------- |
| `io_key_valid`        | io → backend  | 有键盘事件                        |
| `io_key_ready`        | backend → io  | backend 可接收                    |
| `io_key_type[2:0]`    | io → backend  | `key_type_e`                      |
| `io_key_ascii[7:0]`   | io → backend  | KEY_CHAR 时的 ASCII; 其他类型忽略 |

`key_type_e` (`chat_pkg.sv`):

```text
KEY_CHAR      = 0    KEY_LEFT     = 3
KEY_ENTER     = 1    KEY_RIGHT    = 4
KEY_BACKSPACE = 2    KEY_ESC      = 5
KEY_UP        = 6    KEY_DOWN     = 7    // 历史/输入滚动
```

方向键事件会把 Shift 状态放在 `io_key_ascii[0]` (`KEY_SHIFT_MASK`)。backend 用这个 sideband 区分普通 Up/Down 历史滚动和 Shift+Up/Shift+Down 输入框滚动。Shift+Enter 被编码成 `KEY_CHAR` + `0x0A`, 用于多行输入; Ctrl+E 被编码成 `KEY_CHAR` + `KEY_CTRL_E(0x05)`, 用于打开大表情贴纸选择器。

### 3.1.1 `io_mouse → be_top / fe_top` (鼠标事件)

`io_mouse` 与键盘一样在 `chat_top` 内实例化。移动坐标直接给 frontend 绘制指针, 点击/滚轮给 backend 做 UI 交互:

| 信号                  | 方向              | 含义                                      |
| --------------------- | ----------------- | ----------------------------------------- |
| `mouse_x/y[9:0]`      | mouse → frontend/backend | 屏幕绝对坐标, clamp 到 800×600       |
| `mouse_scroll_up/down`| mouse → `io_top`  | 滚轮脉冲; 输入区内滚输入框, 否则滚历史     |
| `mouse_left_click`    | mouse → backend   | 左键 press edge; 点击输入区移动光标/点击弹窗 |
| `mouse_right_click`   | mouse → backend   | 右键 press edge; 命中消息气泡时打开菜单     |

### 3.2 `be_top → comm_top` (TX 请求)

发送一帧, 类型可以是 DATA 或控制帧
(HELLO / REHELLO / USERNAME / GOODBYE / RECALL).

| 信号                       | 方向            | 含义                              |
| -------------------------- | --------------- | --------------------------------- |
| `be_tx_valid`              | backend → comm  | backend 要发一帧                  |
| `be_tx_ready`              | comm → backend  | comm 空闲, 可接                   |
| `be_tx_frame_type[2:0]`    | backend → comm  | `frame_type_e`                    |
| `be_tx_msg_id[7:0]`        | backend → comm  | DATA 的业务消息号; RECALL 时为目标消息号 |
| `be_tx_len[15:0]`          | backend → comm  | payload 字节数                    |
| `be_tx_payload[MAX*8-1:0]` | backend → comm  | DATA 内容 / 用户名 / 空           |

`frame_type_e`:

```text
FRAME_DATA     = 0   FRAME_HELLO    = 3
FRAME_ACK      = 1   FRAME_REHELLO  = 4
FRAME_NAK      = 2   FRAME_USERNAME = 5
                     FRAME_GOODBYE  = 6
                     FRAME_RECALL   = 7
```

所有 backend 发出的帧都走 link-level ARQ (重传到 MAX_RETRY=4 次), 但只有 DATA 帧会经由 `cm_status_*` 回报最终结果. 控制帧没有 backend 状态回报; RECALL 是 best-effort UI 事件, payload 为空, 目标消息号放在 `be_tx_msg_id`/wire `SEQ`.

### 3.3 `comm_top → be_top` (RX 帧 + TX 状态)

收到的远端帧:

| 信号                       | 方向            | 含义                       |
| -------------------------- | --------------- | -------------------------- |
| `cm_rx_valid`              | comm → backend  | 收到一帧                   |
| `cm_rx_ready`              | backend → comm  | backend 可消化             |
| `cm_rx_frame_type[2:0]`    | comm → backend  | 与 be_tx_frame_type 同表   |
| `cm_rx_seq[7:0]`           | comm → backend  | wire `SEQ`; DATA/RECALL 时是对端业务 msg_id |
| `cm_rx_len[15:0]`          | comm → backend  | payload 字节数             |
| `cm_rx_payload[MAX*8-1:0]` | comm → backend  | 帧载荷 (长度 ≤ MAX_MSG_LEN)|

ACK / NAK 由 comm 自己消化, 不上送 backend.

DATA 帧的最终发送状态:

| 信号                     | 方向            | 含义                          |
| ------------------------ | --------------- | ----------------------------- |
| `cm_status_valid`        | comm → backend  | 某条 DATA 已收到 ACK 或超时失败 |
| `cm_status_ready`        | backend → comm  | backend 可接                  |
| `cm_status_msg_id[7:0]`  | comm → backend  | 对应 backend 给的 msg_id      |
| `cm_status_code[1:0]`    | comm → backend  | `TX_SUCCESS=0` / `TX_FAIL=1`  |

### 3.4 `be_top → fe_top` (渲染命令)

| 信号                              | 方向                | 含义                                          |
| --------------------------------- | ------------------- | --------------------------------------------- |
| `be_render_valid`                 | backend → frontend  | 有渲染命令                                    |
| `be_render_ready`                 | frontend → backend  | frontend 可接                                 |
| `be_render_cmd[3:0]`              | backend → frontend  | `render_cmd_e`                                |
| `be_render_msg_id[7:0]`           | backend → frontend  | APPEND/UPDATE_STATUS 时用                     |
| `be_render_store_idx[5:0]`        | backend → frontend  | APPEND 时携带 backend store slot, 供鼠标命中回查 |
| `be_render_side[1:0]`             | backend → frontend  | LOCAL / REMOTE / SYSTEM                       |
| `be_render_status[1:0]`           | backend → frontend  | PENDING / SUCCESS / FAIL / RECALLED           |
| `be_render_len[15:0]`             | backend → frontend  | payload 长度                                  |
| `be_render_payload[MAX*8-1:0]`    | backend → frontend  | 消息文本 / 输入行                             |
| `be_render_cursor_pos[15:0]`      | backend → frontend  | 编辑后的光标位置                              |
| `be_render_ascii[7:0]`            | backend → frontend  | INSERT_AT_CURSOR 时刚插入的字符               |
| `be_render_conn_state[1:0]`       | backend → frontend  | `conn_state_e`                                |
| `be_render_peer_name_len[15:0]`   | backend → frontend  | 对端用户名长度                                |
| `be_render_peer_name[NAME*8-1:0]` | backend → frontend  | 对端用户名 (16 字节定长)                      |
| `be_has_quote`                    | backend → frontend  | 当前输入是否已绑定引用, frontend 显示 quote 标记 |

`render_cmd_e`:

```text
RENDER_APPEND_LOCAL_PENDING = 0    RENDER_REDRAW_ALL       = 5
RENDER_APPEND_REMOTE        = 1    RENDER_MOVE_CURSOR      = 6
RENDER_UPDATE_STATUS        = 2    RENDER_INSERT_AT_CURSOR = 7
RENDER_UPDATE_INPUT_LINE    = 3    RENDER_DELETE_AT_CURSOR = 8
RENDER_CLEAR_SCREEN         = 4    RENDER_CONN_STATE       = 9
                                   RENDER_SCROLL_UP        = 10
                                   RENDER_SCROLL_DOWN      = 11
                                   RENDER_INPUT_SCROLL_UP  = 12
                                   RENDER_INPUT_SCROLL_DOWN= 13
```

`conn_state_e`:

```text
CONN_BOOT         = 0   CONN_CONNECTED    = 2
CONN_HANDSHAKE    = 1   CONN_DISCONNECTED = 3
```

鼠标上下文菜单使用 frontend 暴露的历史行 owner 元数据完成 hit-test:
`hist_wr_row_obs` / `scroll_offset_obs` 定位可见历史行, 每个历史物理行再提供
`hist_owner_valid/store_idx/side/width`. backend 右键命中消息气泡后打开
`POPUP_MSG_MENU`; Quote 只设置 backend 的引用状态, 不直接改写输入框, frontend 用 `be_has_quote` 显示引用标记。发送时 wire payload 前缀为 `QUOTE_MARKER, quoted_side, quoted_msg_id`, 本地和对端渲染前再构造 `> ...\n<user text>` 的显示 payload。Recall 只允许从菜单撤回本地消息: backend 先将本机 `LOCAL+msg_id` 记录更新为 `MSG_RECALLED`, 再发送 `FRAME_RECALL(msg_id)`. 对端收到后只查找并撤回 `REMOTE+msg_id`; 找不到时 no-op.

当前实现中, 弹窗和补全列表不是 text_ram 内容, 而是 frontend scan 阶段的 overlay:

| 信号                         | 方向                | 含义                                      |
| ---------------------------- | ------------------- | ----------------------------------------- |
| `ui_popup_active/type/x/y`    | backend → frontend  | 消息菜单或贴纸选择器的位置与类型           |
| `emoji_suggest_active/count`  | backend → frontend  | 小表情补全候选是否显示及候选数             |
| `emoji_suggest_ids[...]`      | backend → frontend  | 候选 token id 列表, frontend 绘制文本+图标  |
| `hist_owner_*_obs`            | frontend → backend  | 可见历史行的 owner 元数据, 用于右键 hit-test |

### 3.5 关键尺寸参数 (`chat_pkg.sv` / `fe_pkg.sv`)

```text
MAX_MSG_LEN  = 128   // 每条消息字节数
MAX_MSG_NUM  = 64    // 历史消息环大小
MAX_LINE_LEN = 128   // 当前输入行长度
MAX_NAME_LEN = 16    // 用户名长度
MAX_RETRY    = 4     // ARQ 最大重传

N_HIST_STORED   = 64 // frontend 历史物理行数
N_HIST_VISIBLE  = 29 // 屏幕可见历史行数
MAX_INPUT_LINES = 16 // 多行输入缓存行数
N_INPUT_VISIBLE = 5  // 屏幕可见输入行数
```

---

## 4. IO 子系统

键盘路径: `io_top` = `io_ps2_phy` → `io_ps2_decoder` → `handshake_fifo` → backend。

鼠标路径: `io_mouse` 直接接 PS/2 mouse 双向引脚, 完成 Intellimouse 初始化, 输出绝对坐标、滚轮脉冲和左右键 press edge。`chat_top` 把滚轮按鼠标所在区域路由到历史区或输入区, 并把鼠标坐标/点击同时送给 frontend/backend。

```mermaid
flowchart LR
    PS2["ps2_clk / ps2_data<br/>async"] --> PHY["io_ps2_phy<br/>2-FF sync + 11-bit shift"]
    PHY -- "byte_valid/data" --> DEC["io_ps2_decoder<br/>scancode → key event"]
    DEC -- "ev_valid/type/ascii" --> MUX{{"merge<br/>键盘优先"}}
    MS["io_mouse 滚轮脉冲<br/>→ KEY_UP/DOWN"] -- "区域 sideband" --> MUX
    MUX --> FIFO["handshake_fifo<br/>WIDTH=11, DEPTH=16"]
    FIFO -- "io_key_*" --> BE["be_top"]
```

`io_top` 把鼠标滚轮脉冲合成成 `KEY_UP/KEY_DOWN` 事件混入同一个 FIFO (键盘事件优先), 并用 `ev_ascii[0]` 携带"滚轮是否落在输入区"的 sideband, 让 backend 区分历史滚动和输入框滚动。

**io_ps2_phy**: PS/2 帧 `start(0) | d0..d7 | parity_odd | stop(1)`. 在 ps2_clk 下降沿采样 ps2_data, 凑齐 11 bit 后做起始位 / 校验 / 停止位检查, 通过则脉冲 `byte_valid`. PS/2 ~10–16 kHz, 输入两个 pin 都先过 `sync_2ff`.

**io_ps2_decoder**: 解释 Set-2 扫描码. 维护这些 sticky / prefix 状态:

- `lshift_held_q` / `rshift_held_q`: 左右 Shift make/release
- `lctrl_held_q` / `rctrl_held_q`: 左右 Ctrl make/release; Ctrl+E 产生 `KEY_CTRL_E`
- `caps_locked_q`: CapsLock make toggle (0x58)
- `seen_e0_q`, `seen_f0_q`: 前缀字节标志
- `prefix_timeout_q`: 前缀 watchdog, 避免丢字节后 E0/F0 状态污染后续按键

字母使用 `shift XOR caps`, 其他键只看 shift. 扩展键当前实现支持 LEFT / RIGHT / UP / DOWN, 并在 `ev_ascii[0]` 携带 Shift sideband。

事件输出表:

| 输入                  | 产生事件         | ASCII             |
| --------------------- | ---------------- | ----------------- |
| 字母 / 数字 / 符号    | `KEY_CHAR`       | 标准 ASCII (含大小写) |
| 0x5A                  | `KEY_ENTER`      | -                 |
| Shift + 0x5A          | `KEY_CHAR`       | `0x0A` 换行       |
| 0x66                  | `KEY_BACKSPACE`  | -                 |
| 0x76                  | `KEY_ESC`        | -                 |
| 0xE0 0x6B / 0x74      | `KEY_LEFT/RIGHT` | -                 |
| 0xE0 0x75 / 0x72      | `KEY_UP/DOWN`    | -                 |
| Ctrl + E              | `KEY_CHAR`       | `0x05`            |

任何 release 序列 (0xF0 ...) 和未映射字节都被静默丢弃.

**io_mouse**: 先发送 `F3 C8, F3 64, F3 50, F2, F4` 使能 Intellimouse 滚轮模式, 再解 3 字节或 4 字节包。坐标从屏幕中心开始, X/Y movement clamp 到 `0..799` / `0..599`; 左/右键输出按下沿单周期脉冲; 滚轮输出 `scroll_up/down`, 有 3 包抑制窗口做简单去抖。

io 状态机非常浅 (phy 是计数+移位, decoder 是 prefix tracker), 整体行为可以总结为:

```mermaid
stateDiagram-v2
    [*] --> WAIT_FALL
    WAIT_FALL --> SHIFT: ps2_clk falling
    SHIFT --> CHECK: bit_idx == 10
    SHIFT --> WAIT_FALL: bit_idx < 10
    CHECK --> EMIT_BYTE: start/parity/stop OK
    CHECK --> FRAME_ERR: 校验失败
    EMIT_BYTE --> DECODE
    FRAME_ERR --> WAIT_FALL
    DECODE --> WAIT_FALL: 前缀 / release / 未映射 → 丢弃
    DECODE --> EMIT_EVENT: make + 映射成功
    EMIT_EVENT --> WAIT_FALL
```

---

## 5. Comm 子系统

`comm_top` 把链路层拆成 RX / TX 两路, 中间靠 ACK 队列连起来.

```mermaid
flowchart LR
    UARTRX[uart_rx] --> DEC[comm_frame_decoder]
    DEC -- frame --> RXFSM[comm_rx_fsm]

    RXFSM -- cm_rx_* --> BE[backend]
    RXFSM -- ack_q_enq --> ACKQ[comm_ack_queue]
    RXFSM -- tx_ack pulse --> TXFSM[comm_tx_fsm]

    BE -- be_tx_* --> TXFSM
    TXFSM -- cm_status_* --> BE

    ACKQ --> ARB[comm_tx_arbiter<br/>ACK 优先]
    TXFSM --> ARB
    ARB --> ENC[comm_frame_encoder]
    ENC --> UARTTX[uart_tx]
```

### 5.1 帧格式

```text
+------+------+------+------+------+----------+--------+--------+
| SOF  | TYPE | SEQ  | LEN_H| LEN_L| PAYLOAD  | CRC_HI | CRC_LO |
+------+------+------+------+------+----------+--------+--------+
 8 bit  8 bit  8 bit  8 bit  8 bit  LEN byte   8 bit    8 bit
```

- `SOF = 0x7E`, 固定起始字节. 无字节填充 (payload 中允许 0x7E, 靠 LEN 定边界).
- `TYPE[7]` 是 link-level ARQ 交替位; `TYPE[2:0]` 是 `frame_type_e`; `TYPE[6:3]` 保留为 0.
- `SEQ[7:0]` 是业务层 `msg_id`, 不是 ARQ 序号. DATA 用它标识消息; RECALL 用它标识要撤回的消息.
- `CRC16` CCITT, 多项式 `0x1021`, 初值 `0xFFFF`, 校验范围 = TYPE..PAYLOAD (不含 SOF 与 CRC 本身), 大端发送.
- 控制帧 (HELLO / REHELLO / USERNAME) 用 payload 携带发送方用户名; ACK / NAK / GOODBYE / RECALL 的 LEN=0, 无 payload.

引用消息仍然是 `FRAME_DATA`, 只是在 payload 内加应用层前缀:

```text
byte 0      QUOTE_MARKER = 0x01
byte 1      quoted_side  // 按接收方视角编码, 发送方会 LOCAL/REMOTE 取反
byte 2      quoted_msg_id
byte 3..N   用户实际输入内容
```

实际输入缓冲只接收可打印 ASCII 和 `0x0A`, 因此 `0x01` 不会和普通输入冲突。frontend 渲染前用这个前缀查本地 message_store, 生成带 `> ` 预览的显示 payload; wire 上不重复携带被引用消息全文。

### 5.2 TX FSM (stop-and-wait, alternating bit)

`comm_tx_fsm` 用 `TYPE[7]` 承载交替位. DATA 收到匹配 ACK 后翻转; DATA 最终 FAIL 时不翻转. 控制帧也等待 ACK/重传, 但成功后不推进 DATA duplicate-filter 的交替位.

```mermaid
stateDiagram-v2
    [*] --> S_IDLE
    S_IDLE --> S_SEND: be_tx_valid
    S_SEND --> S_WAIT_ACK: arbiter 接受帧
    S_WAIT_ACK --> S_REPORT_SUCCESS: ack_match && DATA
    S_WAIT_ACK --> S_IDLE: ack_match && 控制帧
    S_WAIT_ACK --> S_SEND: timeout && retry < MAX_RETRY
    S_WAIT_ACK --> S_REPORT_FAIL: timeout && retry == MAX_RETRY && DATA
    S_WAIT_ACK --> S_IDLE: timeout && retry == MAX_RETRY && 控制帧
    S_REPORT_SUCCESS --> S_IDLE: cm_status_ready
    S_REPORT_FAIL --> S_IDLE: cm_status_ready
```

控制帧成功后不上报 (fire-and-forget), 失败也不上报. HELLO/USERNAME 这类连接控制靠后续握手自然收敛; RECALL 没有应用层 ACK, 因此语义是 link-level best-effort.

`TIMEOUT_CYCLES` 默认 `2_000_000` (100 MHz × 20 ms). testbench 用更小值缩短仿真.

### 5.3 RX FSM

```mermaid
stateDiagram-v2
    [*] --> S_IDLE
    S_IDLE --> S_IDLE: frame_is_ack/nak<br/>(脉冲 tx_ack, 无 FSM 工作)
    S_IDLE --> S_DELIVER_BE: DATA 非 dup, 或控制帧
    S_IDLE --> S_QUEUE_ACK: DATA 是 dup<br/>(seq 与期望不匹配)
    S_DELIVER_BE --> S_QUEUE_ACK: cm_rx_ready
    S_QUEUE_ACK --> S_IDLE: ack_q_ready<br/>(若是新 DATA, 翻转 expected_rx_seq)
```

- DATA 用交替位过滤重复, 同 seq 重复包只补 ACK, 不上送 backend.
- 控制帧不查交替位 (对方可能刚重启, seq 已被复位), 始终上送 + 补 ACK. 由 backend 的"比较 + 存用户名"逻辑保证幂等.
- CRC 错误 / LEN 超限 / 未知 type 都在更早环节静默丢弃 (decoder `drop_pulse` 给 sim 观测).

### 5.4 TX 仲裁

`comm_tx_arbiter` 是纯组合 mux: ack_queue 有内容 → 合成一个 `FRAME_ACK` (LEN=0, payload=0); 否则透传 tx_fsm 的请求. 编码器只在帧边界 (`frame_req_ready` 高) 切换源, 所以不会在帧中途切换.

优先级: ACK > tx_fsm. 这保证 ACK 不会被对端的 DATA 流卡住.

---

## 6. Backend

`be_top` 是核心控制器, 一个多状态 FSM 同时承担:

1. **连接管理** (外层): boot → handshake → connected → disconnected
2. **聊天主循环** (内层, 仅 connected): 光标编辑 / Enter 提交 / 远端消息接收 / TX 状态更新 / 历史滚动 / 输入滚动 / 鼠标菜单
3. **UI 辅助流程**: 多周期行插入/删除、token 编码、引用显示 payload 构造、贴纸提交、小表情补全、鼠标点击坐标换算

### 6.1 状态总图

```mermaid
stateDiagram-v2
    [*] --> S_BOOT_REDRAW
    S_BOOT_REDRAW --> S_TX_HELLO: render_ready (REDRAW_ALL 发出)
    S_TX_HELLO --> S_HANDSHAKE_IDLE: be_tx_ready

    state S_HANDSHAKE_IDLE {
        [*] --> wait
        wait --> [*]: 收到 HELLO/REHELLO/USERNAME
    }

    S_HANDSHAKE_IDLE --> S_TX_USERNAME: 收 HELLO 或 REHELLO
    S_HANDSHAKE_IDLE --> S_RENDER_CONN_CONNECTED: 收 USERNAME
    S_TX_USERNAME --> S_RENDER_CONN_CONNECTED: be_tx_ready
    S_RENDER_CONN_CONNECTED --> S_IDLE: render_ready

    S_IDLE --> S_RENDER_MOVE_CURSOR: LEFT/RIGHT
    S_IDLE --> S_RENDER_INSERT: KEY_CHAR && line_len<MAX
    S_IDLE --> S_RENDER_DELETE: BACKSPACE && cursor>0
    S_IDLE --> S_ENTER_RENDER_LOCAL: ENTER && line_len>0
    S_IDLE --> S_RX_RENDER: cm_rx_valid (DATA)
    S_IDLE --> S_STATUS_RENDER: cm_status_valid
    S_IDLE --> S_TX_REHELLO: cm_rx HELLO (mid-chat)
    S_IDLE --> S_TX_USERNAME: cm_rx REHELLO
    S_IDLE --> S_TX_GOODBYE: ESC
    S_IDLE --> S_RENDER_CONN_DISCONNECTED: cm_rx GOODBYE
    S_IDLE --> S_RENDER_SCROLL_UP: KEY_UP
    S_IDLE --> S_RENDER_SCROLL_DOWN: KEY_DOWN

    S_RENDER_MOVE_CURSOR --> S_IDLE: render_ready
    S_RENDER_INSERT --> S_IDLE: render_ready
    S_RENDER_DELETE --> S_IDLE: render_ready
    S_RX_RENDER --> S_IDLE: render_ready
    S_STATUS_RENDER --> S_IDLE: render_ready
    S_RENDER_SCROLL_UP --> S_IDLE: render_ready
    S_RENDER_SCROLL_DOWN --> S_IDLE: render_ready

    S_ENTER_RENDER_LOCAL --> S_ENTER_SEND_COMM: render_ready
    S_ENTER_SEND_COMM --> S_ENTER_RENDER_INPUT_CLEAR: be_tx_ready
    S_ENTER_RENDER_INPUT_CLEAR --> S_IDLE: render_ready

    S_TX_REHELLO --> S_IDLE: be_tx_ready
    S_TX_GOODBYE --> S_RENDER_CONN_DISCONNECTED: be_tx_ready
    S_RENDER_CONN_DISCONNECTED --> S_DISCONNECTED_IDLE: render_ready

    S_DISCONNECTED_IDLE --> S_TX_HELLO: KEY_CHAR ascii==' '
    S_DISCONNECTED_IDLE --> S_TX_USERNAME: cm_rx HELLO/REHELLO
    S_DISCONNECTED_IDLE --> S_RENDER_CONN_CONNECTED: cm_rx USERNAME
```

图里只展示连接和主聊天路径。当前实现还包含这些多周期 helper 状态:

- `S_LINE_INSERT` / `S_LINE_DELETE`: 逐字节移动 `line_buf`, 避免 Vivado 展开 `MAX_LINE_LEN` 宽移位 mux。
- `S_LINE_ENCODE`: Enter 提交前逐字节扫描输入, 把 `\happy` 等小表情 token 和整行大表情 token 编码成专用字节。
- `S_BUILD_QUOTE_DISP`: 对带 `QUOTE_MARKER` 的消息构造显示 payload, 支持普通引用、嵌套引用占位、已撤回占位和大表情 token 名称回显。
- `S_MOUSE_CLICK`: 把输入区点击的 2D 坐标换算成线性光标位置。
- `S_STICKER_COMMIT` / `S_STICKER_INSERT`: 提交独立大表情, 或在引用模式下把大表情 token 作为普通文字插入。
- `S_EMOJI_COMPLETE_*`: 点击小表情候选后补齐 token 并刷新输入行。
- `S_RECALL_RENDER` / `S_RECALL_SEND_COMM`: 本地撤回渲染和 `FRAME_RECALL` 发送。

### 6.2 事件仲裁优先级 (S_IDLE)

```text
cm_status_valid  >  cm_rx_valid  >  io_key_valid  >  mouse_click
```

同 cycle 多个事件同时来时按上述顺序, 其余事件的 ready 不拉, 等下次轮到。鼠标点击有 latest-wins latch, backend 忙时不会立刻丢掉刚到的点击坐标。

### 6.3 收到帧的反应表

|             | S_BOOT / S_HANDSHAKE                                  | S_CONNECTED (S_IDLE)                                    | S_DISCONNECTED                                       |
| ----------- | ----------------------------------------------------- | ------------------------------------------------------- | ---------------------------------------------------- |
| `HELLO`     | 比较 + 存用户名, 发 USERNAME, → S_RENDER_CONN_CONNECTED | 比较 + 存用户名, 发 REHELLO (S_TX_REHELLO), 状态不变      | 比较 + 存用户名, 发 USERNAME, → S_RENDER_CONN_CONNECTED |
| `REHELLO`   | 比较 + 存用户名, 发 USERNAME, → S_RENDER_CONN_CONNECTED | 比较 + 存用户名, 发 USERNAME (S_TX_USERNAME), 状态不变    | 比较 + 存用户名, 发 USERNAME, → S_RENDER_CONN_CONNECTED |
| `USERNAME`  | 比较 + 存用户名, → S_RENDER_CONN_CONNECTED              | 比较 + 存用户名, 状态不变                                | 比较 + 存用户名, → S_RENDER_CONN_CONNECTED            |
| `GOODBYE`   | 忽略                                                  | → S_RENDER_CONN_DISCONNECTED                            | 忽略                                                 |
| `DATA`      | 忽略                                                  | 进 S_RX_RENDER, 写 store + APPEND_REMOTE                | 忽略                                                 |

**"比较 + 存用户名"** 的语义: 与 `peer_name_q` 比较, 若不同则 `clear_en` 拉一个周期, message_store 全部 valid 清零, `wr_ptr_q` / `next_msg_id_q` 复位; 若相同则只刷新; 首次收到 (`peer_name_valid_q == 0`) 则只存不清.

**REHELLO 的角色**: HELLO 在 mid-chat 时回 USERNAME 不够 (对方不知道我已在 connected 态), 但又不能再回 HELLO (对方又给我 REHELLO, 死循环). REHELLO 是"终止索取链" — 收到 REHELLO 只回 USERNAME, 永不再发 REHELLO/HELLO.

### 6.4 按键事件反应表

| io 事件                            | S_BOOT / S_HANDSHAKE | S_CONNECTED (S_IDLE)        | S_DISCONNECTED      |
| ---------------------------------- | -------------------- | --------------------------- | ------------------- |
| `KEY_CHAR` (非空格)                | 丢弃                  | 光标处插入 (S_RENDER_INSERT) | 丢弃                |
| `KEY_CHAR` ascii=`' '`             | 丢弃                  | 当字符插入                   | → S_TX_HELLO (重连) |
| `KEY_LEFT` / `KEY_RIGHT`           | 丢弃                  | 光标移动 (S_RENDER_MOVE)     | 丢弃                |
| `KEY_BACKSPACE`                    | 丢弃                  | 光标左删 (S_RENDER_DELETE)   | 丢弃                |
| `KEY_ENTER` (line_len > 0)         | 丢弃                  | 三段流水 (LOCAL → COMM → CLR)| 丢弃                |
| Shift+Enter (`KEY_CHAR 0x0A`)      | 丢弃                  | 插入换行, 最多 16 输入行      | 丢弃                |
| `KEY_ESC`                          | 丢弃                  | 发 GOODBYE → DISCONNECTED   | 丢弃                |
| `KEY_ESC` (弹窗/引用 active)        | 丢弃                  | 先关闭弹窗或清引用, 不断开     | 丢弃                |
| `KEY_UP` / `KEY_DOWN`              | 丢弃                  | 滚动历史 (RENDER_SCROLL_*)   | 丢弃                |
| Shift+`KEY_UP/DOWN`                | 丢弃                  | 滚动多行输入窗口              | 丢弃                |
| Ctrl+E                             | 丢弃                  | 打开大表情贴纸选择器          | 丢弃                |

鼠标交互:

| 操作                       | 行为 |
| -------------------------- | ---- |
| 滚轮在历史区               | 发送 `RENDER_SCROLL_UP/DOWN` |
| 滚轮在输入区               | 发送 `RENDER_INPUT_SCROLL_UP/DOWN` |
| 左键点击输入区             | 光标跳到点击位置对应的输入字符 |
| 右键点击消息气泡           | 打开 `POPUP_MSG_MENU` |
| 菜单 Quote                 | 绑定引用状态, 输入栏显示 quote 标记 |
| 菜单 Recall                | 仅本地消息可撤回, 同步发送 `FRAME_RECALL` |
| Ctrl+E 后点击贴纸          | 无引用时提交独立大表情; 有引用时插入 `\Name` 文本 |
| 点击小表情候选             | 自动补齐当前 `\...` token |

### 6.5 数据结构

```text
// 连接
conn_state_q                      // 由当前 FSM 状态隐含, 对外提供 conn_state_obs
peer_name_q   [0..MAX_NAME_LEN-1]
peer_name_len_q
peer_name_valid_q

// 输入行
line_buf      [0..MAX_LINE_LEN-1]
len_q, cursor_pos_q                // cursor_pos ∈ [0, len_q]

// 消息存储 (rtl/backend/be_message_store.sv)
message_store[i] = {valid, msg_id, side, status, len, payload}
wr_ptr_q                           // 循环写指针
next_msg_id_q                      // 单调分配的本地 msg_id
```

消息存储支持原子写 (`wr_en`), 状态-only 更新 (`upd_en` 改 PENDING → SUCCESS/FAIL/RECALLED), 单周期全清 (`clear_en`, 切换对端时), 以及组合 lookup (按 `side+msg_id` 找最低有效行). 切换对端时 wr_ptr / next_msg_id 一并复位.

### 6.6 三段 Enter 提交

```mermaid
sequenceDiagram
    participant BE as be_top
    participant ST as message_store
    participant FE as fe_top
    participant CM as comm_top

    Note over BE: S_IDLE 接到 KEY_ENTER (len > 0)
    BE->>ST: wr_en (msg_id, LOCAL, PENDING, payload)
    BE->>FE: APPEND_LOCAL_PENDING (S_ENTER_RENDER_LOCAL)
    FE-->>BE: render_ready
    BE->>CM: be_tx (FRAME_DATA, msg_id) (S_ENTER_SEND_COMM)
    CM-->>BE: be_tx_ready
    BE->>FE: UPDATE_INPUT_LINE len=0 (S_ENTER_RENDER_INPUT_CLEAR)
    FE-->>BE: render_ready
    Note over BE: 回到 S_IDLE
    CM->>BE: 一段时间后 cm_status (SUCCESS/FAIL)
    BE->>ST: upd_en (msg_id, status)
    BE->>FE: UPDATE_STATUS (S_STATUS_RENDER)
```

---

## 7. Frontend

`fe_top` 是双时钟域设计:

- **chat 域 (`clk`, 100 MHz)**: `fe_render_decoder` 把 backend 的渲染命令翻译成 text_ram 写入, 并把历史 payload 写入 `fe_msg_payload_ram` 以便状态更新时重绘整条气泡。
- **像素域 (`clk_pix`, 40 MHz)**: `fe_video_timing` 产生 (h/v counter, hsync, vsync, de); `fe_scan` 拿坐标 → 读 text_ram → 查 `fe_glyph_rom` / 大表情 ROM / SRAM asset → 输出 RGB. `fe_text_ram` 是双时钟 BRAM, 写口在 chat 域, 读口在像素域.

```mermaid
flowchart LR
    subgraph CHAT [chat clock]
        BE[backend<br/>be_render_*] --> DEC[fe_render_decoder]
        DEC -- wr_en/row/col/code/attr --> RAM[fe_text_ram]
        DEC --> PRAM[fe_msg_payload_ram]
    end
    subgraph PIX [pixel clock]
        VT[fe_video_timing] --> SCAN[fe_scan]
        RAM2[(fe_text_ram<br/>读口 A)] --> SCAN
        GROM[fe_glyph_rom] --> SCAN
        BIG[big emoji ROMs] --> SCAN
        SRAM[BaseRAM assets] --> SCAN
        SCAN --> RGB[(video_red/green/blue<br/>hsync/vsync/de)]
    end
    DEC -. CDC sync_2ff .-> SCAN
    RAM --- RAM2
```

CDC: `conn_state`, `input_cursor`, `hist_wr_row`, `scroll_offset`, 输入滚动、鼠标坐标、popup/emoji overlay 状态等都是慢速控制量, 每 bit 过 `sync_2ff` 进像素域。

### 7.1 text_ram 布局 (`fe_pkg.sv`)

```text
text_ram = 128 行 × 128 列 (一个 cell = 8 bit ASCII / sprite code)

row 0                      titlebar:  "Chat with: <peer_name>"
row 1                      分隔 (空)
rows 2..65 (64 行)         history 环形缓冲; 一条多行消息会占多个物理行
                              cell 低 8 bit 是字符 / sprite / 大表情 tile code
                              attr sideband 标识本地/远端气泡背景
                              hist_owner_* 记录每行归属, 供右键 hit-test
row 66                     分隔
rows 67..82 (16 行)        多行输入缓存; 屏幕只显示其中 5 行
```

屏幕上可见 29 行历史 (`N_HIST_VISIBLE`), 64 行环里的窗口位置由 `hist_wr_row` (写指针) + `scroll_offset` 决定。输入缓存最多 16 行, 屏幕可见 5 行 (`N_INPUT_VISIBLE`), 由 `input_scroll_offset` 选择窗口。所有滚动命令都在 fe 侧 clamp。

### 7.2 渲染命令解码器 FSM

```mermaid
stateDiagram-v2
    [*] --> S_IDLE
    S_IDLE --> S_HIST_CLEAR: REDRAW_ALL
    S_IDLE --> S_TITLEBAR: CONN_STATE (CONNECTED)
    S_IDLE --> S_HIST_STORE: APPEND_LOCAL_PENDING / APPEND_REMOTE
    S_IDLE --> S_HIST_LOAD: UPDATE_STATUS
    S_IDLE --> S_INPUT_LOAD: UPDATE_INPUT_LINE / MOVE_CURSOR
    S_IDLE --> S_INPUT_INSERT: INSERT_AT_CURSOR
    S_IDLE --> S_INPUT_DELETE: DELETE_AT_CURSOR
    S_IDLE --> S_IDLE: SCROLL_UP/DOWN 或 INPUT_SCROLL_UP/DOWN

    S_HIST_CLEAR --> S_IDLE: 全部 history 行清空完
    S_TITLEBAR --> S_IDLE: titlebar 写完
    S_HIST_STORE --> S_HIST_WRITE: payload BRAM 写完 + newline parse 完
    S_HIST_LOAD --> S_UPDATE_STATUS: payload BRAM 读回完成
    S_HIST_WRITE --> S_IDLE: 整条消息 + sprite 写完
    S_UPDATE_STATUS --> S_IDLE: sprite 写完
    S_INPUT_INSERT --> S_INPUT_PARSE: input_line_q 插入完成
    S_INPUT_DELETE --> S_INPUT_PARSE: input_line_q 删除完成
    S_INPUT_LOAD --> S_INPUT_PARSE: input_line_q 全量载入完成
    S_INPUT_PARSE --> S_INPUT_REDRAW: 多行解析完成
    S_INPUT_REDRAW --> S_IDLE: 可见输入窗口重写完成
```

`be_render_ready` 仅在 `S_IDLE` 拉高, 多周期写入/解析状态下 backend 自动等待。

decoder 内部维护一份 `input_line_q[]` 镜像, INSERT/DELETE 和 newline parse 都按字节多周期执行, 避免综合时展开 `MAX_LINE_LEN` 大循环。

REDRAW_ALL 不做实质工作 (text_ram 复位为空格), 只锁存 `conn_state_curr_q`; 非 CONNECTED 时 scan 侧不读 text_ram, 直接显示 splash 图层.

### 7.3 像素 scan 流水线

`fe_scan` 流程, 每像素一拍:

1. 由 `(hdata, vdata)` 算出 `(screen_row, screen_col, gx, gy)`.
2. 把 `screen_row` 映射成 text_ram 物理行:
   - 0 → `TITLE_ROW`
   - 2..30 → history 环窗口 (按 `hist_wr_row` 和 `scroll_offset`)
   - 32..36 → input 多行窗口 (按 `input_scroll_offset`)
   - 1, 31 → 空白分隔
3. 驱动 text_ram 读口; 下一拍拿到 `rd_code`.
4. 普通字符喂 `fe_glyph_rom`; 大表情 tile code 走 `fe_big_emoji_pixel_rom` + palette ROM; CONNECTED 历史背景可从 SRAM 读 RGB565 背景/头像。
5. 选 `gx` 对应的 bit 或大表情 nibble, 混色 (气泡 attr / 状态 / overlay 决定前景背景), 光标 cell 按 `BLINK_FRAMES` 取反。
6. 非 CONNECTED 状态用 splash 图层覆盖; CONNECTED 状态再叠加 popup、emoji suggestion 和鼠标指针。

视频时序 (`fe_video_timing`, 800×600 @ 60 Hz):

```text
H: 0..799 active, 800..839 FP, 840..967 SYNC, 968..1055 BP   pixel clock = 40 MHz
V: 0..599 active, 600..600 FP, 601..604 SYNC, 605..627 BP    HSPP=1, VSPP=1
```

### 7.4 四种屏幕

```text
boot 屏 (conn_state=BOOT):             handshake 屏:
+--------------------------------+    +--------------------------------+
|                                |    |                                |
|       Chat (booting...)        |    |     Connecting to peer...      |
|                                |    |                                |
+--------------------------------+    +--------------------------------+

connected 屏 (主聊天):                 disconnected 屏:
+--------------------------------+    +--------------------------------+
| Chat with: Bob                 |    |                                |
|--------------------------------|    |        Disconnected.           |
| me:   hello              [✓]   |    |   Press SPACE to reconnect.    |
| peer: hi                       |    |                                |
| me:   are you there?     [✗]   |    |                                |
|--------------------------------|    |                                |
| > current typing line _        |    |                                |
+--------------------------------+    +--------------------------------+
```

splash 文字储存在 fe_scan 内的小 ROM (`SPLASH_COLS=32` × 2 行), `(HSIZE − 256) / 2` 居中, 垂直居中.

---

## 8. 表情 / 贴纸 / 视觉素材

### 8.1 小表情 token

backend 在 `S_LINE_ENCODE` 中把小写反斜杠 token 编码成 `0xE0..0xEE` 的单字节 glyph code, frontend 通过 `fe_glyph_rom` 画 8×16 单色小图标:

```text
\happy  \sad   \heart \ok    \laugh
\wink   \angry \star  \fire  \yes
\no     \up    \down  \doge  \mairuo
```

用户输入 `\` 后, backend 维护候选列表并通过 `emoji_suggest_*` 输出给 frontend overlay。点击候选会补齐剩余 token 字符; 如果前缀无匹配, 候选自动关闭。

### 8.2 大表情贴纸

大表情来自 `assets/big_emoji/*.{jpg,png}`, 当前有:

```text
\Heartbroken  \Hissing  \Shrug  \Sweat  \Xiucai
```

大表情 token 只有在“整行正好等于该 token 且没有引用状态”时才编码成一个 anchor byte (`0x80..0xD9` 范围的首 tile)。frontend 把 anchor 展开为 3×6 个字符 cell, 每个 cell 是 8×16 像素, 通过 `fe_big_emoji_pixels.hex` + `fe_big_emoji_palette.hex` 输出 48×48 彩色贴纸。Ctrl+E 打开贴纸选择器; 无引用时点击贴纸会直接提交一条单贴纸消息, 有引用时则把 `\Name` 作为普通文字插入输入框, 让引用仍然走普通 DATA 格式。

重新生成大表情资源:

```bash
python3 scripts/gen_big_emoji.py
```

脚本会更新:

```text
rtl/frontend/fe_big_emoji_pixels.hex
rtl/frontend/fe_big_emoji_palette.hex
rtl/pkg/fe_big_emoji_codes.svh
rtl/backend/be_big_emoji_tokens.svh
sim/tb/common/big_emoji_codes.h
```

### 8.3 SRAM 背景与头像

背景和头像不进入 bitstream, 由 `scripts/gen_sram_assets.py` 打包后写入 BaseRAM。地址布局见前文“SRAM 上传背景与头像”。`chat_top_board` 实例化 `chat_top` 时打开 `ENABLE_SRAM_ASSETS=1`, 仿真顶层默认关闭, 这样 Verilator 不依赖外部 SRAM 内容。

---

## 9. 用户名 / 板子身份

每块 FPGA 的用户名编译期硬编码进 bitstream, 作为 `chat_top` (以及 `chat_top_board`) 的参数:

```systemverilog
parameter int MY_NAME_LEN = 5;
// 小端打包: byte 0 在 [7:0]. 默认 "Alice" = 0x41 0x6c 0x69 0x63 0x65
parameter logic [MAX_NAME_LEN*8-1:0] MY_NAME_PACKED =
    128'h00000000_00000000_00000065_63696c41;
```

B 板按 "Bob" 重新打包并跑一次 `make bitstream` 即可. 后续若要支持运行时配置, 可以把 MY_NAME 换成寄存器, 接 ROM 或拨码开关, 接口不变.

---

## 10. 仿真与综合

**Verilator 仿真**:

```bash
make                 # 跑所有 sim/tb 下的测试
make test-be_top     # 单跑一个
make font            # 重新生成 fe_font.hex
python3 scripts/gen_big_emoji.py    # 重新生成大表情 ROM/headers
python3 scripts/gen_sram_assets.py \
  --background assets/avator_and_background/background.png \
  --local-avatar assets/avator_and_background/avator.jpg \
  --out chat_assets.bin
```

测试覆盖每个叶模块 + 集成 (io_be, comm_top_lb, chat_top, chat_top_pair). `chat_top_pair` 把两份 chat_top 的 UART 对接, 完整模拟两块板.

**Vivado 综合**:

```bash
make bitstream       # 调用 vivado/build.tcl
```

目标板 `xc7a200tfbg484-2` (Genesys 2). 引脚约束在 `constraints/chat_top_board.xdc`. 综合产物: `vivado/build/chat.runs/impl_1/chat_top_board.bit`.

板级顶层 `chat_top_board` 包两个 Xilinx IP: `ip_pll` (100 MHz → 40 MHz 像素时钟) 和 `ip_rgb2dvi` (RGB → TMDS 差分对). 这两个 IP 让 `chat_top_board` 不能用 Verilator elaborate, 所以仿真用 `chat_top` 直接对接 RGB / HSYNC / VSYNC / DE.

复位: `btn_rst` 是 active-high momentary push-button. `chat_top` 内部用 `sync_2ff` 做 reset 同步, 按钮按下时整条同步链拉 0, 松开后两拍后产生干净的同步释放沿.
