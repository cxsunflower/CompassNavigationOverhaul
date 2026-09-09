# tools/ —— 打包、补丁与校验脚本

生成/校验工具主要使用 Python 3 标准库；SWF 构建另需 Java 与本机 JPEXS（`ffdec-cli.jar`），`.cjs` 回归测试使用 Node.js。`build.bat` 检查哈希并打包，不自动重编译 SWF。
部分独立校验器采用第二实现；构建脚本还包含结构断言、反编译检查与哈希检查。各检查覆盖范围不同，不能替代 VR 实机验收。

## QuestList SWF 构建链（当前流程）

| 脚本 | 用途 |
|---|---|
| `build_questlist_art.py` | 把 `assets/source/questlist/art/` 的 SVG 矢量图建成原生 SWF 符号（ID 300–305）。一般不直接调用，由下条脚本调用 |
| `questlist_header_layout.py` | 构建期新增Sprite 306，将原Title完整作为Header纳入DetailBox；验证原始符号及18帧动画不变，不修改原始基底 |
| `questlist_source.py` | 组合 `swf/questlist/item/`、`list/` 下的13个源码模块，检查引用完整性、重复函数及原入口范围；可用 `--output` 导出可检查的完整源码 |
| `build_questlist_swf.py` | 从不可变原始基底 + 两个AS2入口及其模块重建 `assets/generated/QuestItemList.swf`；`--check` 校验所有源码依赖与产物哈希一致 |
| `embed_questlist_compass.py` | 把 QuestList 以原生 Sprite 511 嵌入两份 `Compass.swf`（`HUDMenu` / `VR_HMD_info`），资源 ID +500；`--check` 校验，`--output` 只做预检不替换发布文件 |
| `build_compass_swf.py` | 把 `swf/Compass.as` / `swf/CompassMarkerInfo.as` 编入 `assets/generated/Compass.before-embedded.swf`（ffdec importScript，内联 `utils.as`，去 AS2 类型标注）；`--check` 校验源码与基底一致 |

```powershell
$ff = '完整路径\ffdec-cli.jar'
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/tests/test_questlist_source.py
python tools/build_questlist_swf.py --ffdec $ff
# 修改罗盘源码时，嵌入前另运行：
# python tools/build_compass_swf.py --ffdec $ff
python tools/embed_questlist_compass.py --ffdec $ff
python tools/build_questlist_swf.py --check
python tools/build_compass_swf.py --check
python tools/embed_questlist_compass.py --check
```

完整步骤、反编译测试命令与部署边界见 [QuestList 当前说明](../manager/docs/quest-list.md)。逐条检查退出码，任一步失败就停止。
当前完整层级为`DetailBox → Header / DetailBody / DetailContentMask`。构建脚本检查原版标题符号、动画、容器逻辑宽高及遮罩入口；完整布局/状态模拟需同时传入反编译的QuestItem类与时间轴脚本。包装器单元测试运行`python tools/tests/test_questlist_header_layout.py`，不能只执行单文件布局测试。
源码编辑入口与各模块职责见[QuestList源码结构](../swf/questlist/README.md)。原两个AS2文件现在只保留类/时间轴声明、状态和模块引用；JPEXS仍只编译这两个组合后的入口，不引入新的运行时类、动画或加载边界。新增模块必须注册到入口，不能绕过构建脚本直接安装片段。
高度修复新增根坐标比较、真实省略状态及`GetLayoutSnapshot`按需诊断。调试叠加层由Debug/Trace日志级别和`bShowQuestListLayout`独立开关共同控制，根级绘制不参与布局/遮罩；45/45布局测试另覆盖四角红框、隐藏行、门控、缓存、标签复用与卸载清理。修改`source/ui/`、`source/MessageListeners.cpp`或`source/settings/`后必须运行完整`build.bat`重编DLL，不能只用`nobuild`。MCM英文帮助修改时同时更新中文生成器及精确校验白名单；运行时日志需在部署后按需采集，不应把模拟结果当作VR安全区测量。

## MCM 配置与 ESP

| 脚本 | 用途 |
|---|---|
| `make_mcm_config_zhcn.py` | 由英文 `config.json` 生成 `assets/localization/zh-CN/` 下的 `config.json`（带次数断言的字面替换，不破坏格式与换行） |
| `verify_mcm_config_zhcn.py` | 校验中英文结构/翻译/占位符、INI 分组与数值默认值、C++ 注册/回调绑定，并核对已有打包暂存配置 |
| `make_mcm_esp.py` | 生成最小 MCM 空壳 ESP（Start-Game-Enabled Quest + `MCM_ConfigBase`） |
| `verify_esp.py` | 独立 ESP 解析器：检查长度字段、GRUP 边界、formID、VMAD，不复用生成器代码 |

MCM 操作顺序、覆盖包说明及菜单不显示排查见 [MCM 文档](../manager/docs/mcm.md)。

## 旧流程脚本（已退役，仅留作参考）

- `patch_questitemlist_vr.py` / `verify_questitemlist_vr.py`：只适用于原版参考基线 的固定长度字节补丁，**不适用**于当前重编译版本。不要再用。
- `build_vr_hud_meshes.py`：Palm 贴图重排方案的网格生成脚本，已随该方案撤回归档（见 [历史记录](../manager/docs/quest-list-history.md)），不要恢复。

## 基底与清单文件

| 文件 | 说明 |
|---|---|
| `assets/source/questlist/QuestItemList.HUDMenu-original.swf` | 不可变的原始基底：每次构建都从它重新生成，不在上次产物上追加 |
| `assets/generated/Compass.before-embedded.swf` | 合并前罗盘基底；改原罗盘时必须同步更新 |
| `questlist-swf.json` / `compass-swf.json` / `compass-embedded.json` | 构建哈希清单：`--check` 与 `build.bat` 用它们发现源码与二进制脱节 |
| `tests/test_mcm_bindings.py` | Python 回归测试：INI 错分组、双语默认值、原生绑定、范围和重复键；不修改发布文件 |
| `tests/ini_input.test.cpp` | 原生Win32配置读取回归：UTF-8 BOM首节、无BOM透传、源文件完整性与临时清理；不读取或修改玩家配置 |
| `tests/questlist_layout.test.cjs` | 反编译AS2回归入口；共享模拟环境与item/layout/debug三组测试在`tests/questlist/` |
| `tests/test_questlist_source.py` | 源码组合、模块清单、原入口API与哈希覆盖回归；不修改发布文件 |
| `tests/compass_marker_scale.test.cjs` | 反编译罗盘脚本回归测试：名称/距离缩放接口存在性与转调（Node 运行，参数为反编译 scripts 目录） |
| `assets/source/questlist/art/` | 目标装饰 SVG 源 + 映射说明（见 [素材说明](../assets/source/questlist/art/README.md)） |

INI输入兼容测试可在Visual Studio x64开发命令提示符中运行（输出只写入已忽略的build目录）：

```bat
mkdir build\ini-input-test
cl /nologo /std:c++latest /EHsc /W4 /utf-8 /I include source\utils\INIInput.cpp tools\tests\ini_input.test.cpp /Fe:build\ini-input-test\ini_input.test.exe /Fo:build\ini-input-test\ /link kernel32.lib
build\ini-input-test\ini_input.test.exe
```

这项测试针对真实Windows配置API复现首节BOM缺失，不能替代游戏内完整设置加载或VR绘制验收。修改INI读取器后还需运行MCM绑定回归、完整build.bat及发布包校验。

标题装饰同时由 `build_questlist_swf.py` 从 `assets/source/questlist/art/QuestItemListArt.original.swf` 重建：恢复并保留原始素材字节（描边及背景试验均已撤回；用户确认黑区来自名称放大后的跨区域显示），两份 `QuestItemListArt.swf` 纳入同一哈希清单。原始素材不得用生成结果覆盖。

## 发布边界校验

VR独立面板由 `build_vr_quest_panel.py --ffdec <jar>` 构建，`--check`校验影片、美术和连续UV网格。QuestList更新后须同步重建，`build.bat`已将该检查纳入打包。运行机制见[独立VR面板](../manager/docs/vr-quest-panel.md)。

`python -X utf8 tools/verify_package.py --archives` 逐文件比较主包、CHS 暂存目录及 ZIP 与当前资源、DLL 和 LICENSE；拒绝缺失、额外文件、重复 ZIP 条目或哈希不一致。未生成 ZIP 时省略 `--archives`，`MAKE_CHS=0` 时加 `--main-only`。目录职责见 [资源说明](../assets/README.md)。
