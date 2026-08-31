# decompiled/ —— CompassNavigationOverhaul 2.9.9 反编译产物

这一层是**从二进制反编译得到并保留下来的源码**，不是从网上找来的源码。
输入文件只有一个：`CompassNavigationOverhaul_2.9.9/SKSE/Plugins/CompassNavigationOverhaul.dll`
（2033152 字节，PE64，无 PDB、无导出符号表，作者只发布了 SE/AE 版）。

这里的内容是「2.9.9 实际行为的唯一事实来源」。根目录 `source/`、`include/` 里所有可编译的 C++ 都必须能在这里找到对应依据。
**这些 .c 文件不可直接编译**：它们是 Ghidra 反编译器输出的伪 C，类型被擦除成 `undefined8` / `longlong`，
栈变量名是自动生成的，虚表调用被展开成函数指针间接跳转。

工程概览、构建与安装见根目录的 [`../README.md`](../README.md)。

## 产出方式

- 反编译器：Ghidra 11.3.2 headless（`analyzeHeadless`），Jython 2.7.4 脚本
- 单函数超时 600 秒。曾用 180 秒，`InfinityUIMessageListener`（3649 字节）会超时并产出空函数体，
  必须用 600 秒才能拿到完整的 23 KB 输出——这是本次导出里最容易踩的坑。
- 自动分析漏掉了大量「只被虚表或函数指针引用」的函数（各种 MessageListener、lambda）。
  这些字节根本没被反汇编，靠 `MakeFuncsInGaps.py` + `MakeFuncsFromOrphanCode.py` 两遍补建，
  函数总数从约 6900 补到 **8084**。
- 函数名不是猜的，来自 **2.2.0-VR 版 DLL 自带的 PDB**：先用字符串指纹稀有度加权 + 调用图传播 + 函数体
  大小比值做跨版本符号迁移，再逐个人工核对锚点（`_analysis/manual_anchors.json`）。

## 范围

只导出 **CNO 自己的代码**，不含 CommonLibSSE-NG / STL / spdlog 的几千个模板实例。
DLL 内 8084 个函数中筛出 **1125 个**属于 CNO 本体，全部反编译成功，0 失败。

| 文件 | 函数数 | 内容 |
|---|---|---|
| `Hooks.c` | 23 | `hooks::Install` 全表、6 个 trampoline 钩子、4 个虚表静态初始化器、2.9.9 新增的 3 个虚表钩子 |
| `HUDMarkerManager.c` | 12 | 罗盘标记核心：`ProcessQuestMarker`(2120B)、`SetMarkersExtraInfo`(3180B)、`ProcessLocation/Enemy/PlayerSetMarker` |
| `MessageListeners.c` | 3 | `SKSEMessageListener`、`InfinityUIMessageListener`(3649B)、`MCMPlusPlusMessageListener` |
| `QuestItemList.c` | 9 | 任务列表 HUD 元件 |
| `Compass.c` | 10 | 罗盘本体与 `Marker` 构造 |
| `Settings.c` | 1 | `settings::OnSettingChanged`(1684B)，MCM++ 设置回调 |
| `IUI.c` | 6 | Infinity UI 的 `GFxObject::Invoke<>` 各实例 |
| `NND.c` | 3 | NPC Names Distributor 接口对接 |
| `utils.c` | 2 | `GetMagicEffectArea`、虚表写入辅助 |
| `main.c` | 2 | `SKSEPlugin_Load`、`SKSEPlugin_Query` |
| `_unresolved.c` | 1054 | 尚未对上真名的 CNO 函数（仍是 `FUN_xxxxxxxx`） |

## 命名可信度

`index.tsv` 的第 5 列 `name_status` 标注每个函数名的来源，读代码时**务必先看这一列**：

| 状态 | 数量 | 含义 |
|---|---|---|
| `confirmed` | 69 | 人工核对过的锚点，或启发式映射并经交叉验证 |
| `unconfirmed` | 13 | 只有历史遗留的符号名，未逐个核对；标题里带 `[名称未经人工确认]` |
| `raw` | 1043 | 仍是 Ghidra 自动名 `FUN_地址`，真名未知 |

已知的 `unconfirmed` 里有两处**已查实的误标**，读代码时不要当真（就是紧接着的这两条）：

- `0x18003d680` 标为 `CNO::Compass::InitSingleton`，**实际是 `CNO::Compass::SetupMod`**——
  函数体是 `HasMember("Compass")` → `GFxValue::operator=` → `Invoke("Compass")`，与 2.2.0 的 `Compass.h` 逐句吻合。
  真正的 `InitSingleton` 是 `0x18003d5e0`（做魔术静态 + `singleton = &instance`，那条标注是对的）。
- `0x18003dd00` 标为 `QuestItemList::InitSingleton`，实际是同一构造逻辑的**无线程守卫副本**；
  真正带 `_Init_thread_header/footer` 并给 `DAT_1801d9528` 赋值的是 `0x18003d8f0`。

另外 `0x180041890` 标的 `hooks::compat::MapMarkerFramework::Install` 实际是个被 24 处调用的共享日志辅助函数，已从映射表里剔除，
只是程序里的旧符号还留着。2.9.9 全 DLL 没有任何 CoMAP 相关字符串。

还有一处存疑但不影响结论：`0x1800a6cd0`(341B) 与 `0x1800a6e30`(349B) 都被标成
`hooks::Trampoline::write_call<6>`。两者都额外接收一个操作码字节（`0xE9` / `0xE8`），
结合跳板尺寸 `0xE` 反推，实际应是 `Hook<5>` 对应的 `write_branch<5>` 与 `write_call<5>` 两个实例化。

## 全局变量对照表

反编译输出里的 `DAT_1801dxxxx` 都是零初始化的 `.data` 尾部（相当于 .bss），含义已查明：

| 地址 | 含义 |
|---|---|
| `DAT_1801d9588` | `RE::Compass` 虚表地址（`VariantID{se 0x41A19, ae 0x34954}`） |
| `DAT_1801d95a0` | `RE::ScriptEffect` 虚表地址 |
| `DAT_1801d95a8` | `RE::DetectLifeEffect` 虚表地址 |
| `DAT_1801d95b0` | `RE::ShaderReferenceEffect` 虚表地址 |
| `DAT_1801d9578` | `HUDMarkerManager::AddMarker` 的 `RelocationID{50851, 51728}` |
| `DAT_1801d9550 / 9548 / 9540` | 被替换掉的三个虚函数原地址（供钩子回调原实现） |
| `DAT_1801d9538` | 2.9.9 新增的布尔开关，控制「探索生命/灵魂视界照亮的角色是否上罗盘」 |
| `DAT_1801d97e0` | SKSE trampoline 对象 |

## 关键结论

（原先另有一份逐节的 `DIFF_2.2.0_to_2.9.9.md` 详版，随 `docs/` 目录一并移除；下面这份摘要即保留下来的结论记录。）

1. **2.9.9 的钩子偏移与 2.2.0 完全一致**，SE/AE 两套 ID 一个都没变，所以 VR 分支的 `Hooks.h` 可以直接复用。
2. **2.9.9 编译进了 VR 代码路径，但没有 VR 偏移数据**。汇编铁证在 `Hooks.c` 的四个静态初始化器里：
   VR 分支走 `XOR EAX,EAX; MOV RAX,RBX`，即 `模块基址 + 0`。也就是说 2.9.9 直接在 SkyrimVR 上跑会去解引用 base+0。
   这正是「2.9.9 缺 VR 版」的根因，移植必须换成 alandtse/CommonLibVR 并补上 VR 偏移。
3. **2.9.9 多了三个虚表钩子**（`DetectLifeEffect::Update`、`ScriptEffect::Update`、`ShaderReferenceEffect::DetachImpl`），
   但整个 `.text` 里对开关 `DAT_1801d9538` 只有 2 处读、**0 处写**，`.data` 初值为 0，
   也没有任何数据结构存着它的地址。所以这是个**没写完、永久关闭的休眠特性**，
   `ShaderReferenceEffect::DetachImpl` 的钩子体更是纯转发、一句额外逻辑都没有。
   移植时照抄即可，行为上等价于不装。
4. **参数槽位差异**：2.9.9 的 `HookCodeGenerator` 把任务目标写到 `[rsp+0x28]`（`UpdateQuests` 6 参数），
   VR 需要写 `[rsp+0x38]`（8 参数）。VR 分支已经处理了这一点。

## _analysis/

- `name_map.json` — 启发式跨版本符号映射（49 条）
- `manual_anchors.json` — 人工核对锚点（41 条），优先级高于启发式
- `export_list.json` — 判定为「CNO 本体」的 1125 个入口地址
- `*.py` — 复现整套流程需要的 Ghidra 脚本
- `hooks_install.c` / `vtable_init.c` / `new_hooks.c` / `hookfuncs.c` / `misc1.c` / `iui_listener.c`
  —— 分析过程中单独导出的片段，内容已并入上面的模块文件，保留以便对照

复现命令：

```
export JAVA_HOME=<jdk21>
analyzeHeadless <proj> CNO -process CNO_299.dll -noanalysis \
  -scriptPath _analysis \
  -postScript ApplyNamesAndExport.py name_map.json manual_anchors.json export_list.json <outDir>
```
