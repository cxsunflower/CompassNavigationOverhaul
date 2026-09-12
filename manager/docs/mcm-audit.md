<!-- 定位：L2 全部 MCM 设置的消费链审查、条件限制、无效残留与修复优先级。 -->

# MCM 全设置审查

最新源码状态：删除旧位置键后，进一步按授权删除QuestList Y偏移，X范围扩大为-200～200；现34个注册键、28项菜单（罗盘13、列表14、调试1）。本轮未执行部署；此前分组提交前只读检查发现偏移修订安装输入与当时产物一致，但另有用户设置变化，不能再把上次三文件清单当作当前安装基线。

初次审查：2026-09-12；状态复核：2026-09-13。范围：英文／中文 MCM、默认 INI、注册与分发、菜单关闭重载、C++ 消费点、AS2 应用入口，以及当前安装与最新源码的差异。

## 结论

历史实机复核（Y设置删除前）：Y偏移在实际安装SWF的Passenger几何中被固定高度夹取完全抵消，-100/0/100的最终Y均为764.1；X在同一模拟能移动，但用户实机“没效果”尚未解释完。本报告原先仅凭消费链将偏移判为有效，证据不足；当前应按以下更新状态处理。

**不能说全部设置都正常有效。** 审查基线菜单共 **29 项**（罗盘 13、任务列表 15、调试 1；现已删除Y，剩28项），ID 无重复，均有注册及分发。发现 **2 项确定的热更新缺陷**；其余项目能找到消费链，但有模式依赖、布局约束和已知安装问题，不能据此宣称全部通过 VR 实测。

- **需修复而非删除**：罗盘“开始显示角度”“停止显示角度”的消费值只在单例创建时缓存，MCM 更新后未刷新。
- **待实机验收**：旧安装曾漏查真实VR根；节点搜索／缺失门控修订现已部署，但尚无新游戏验收证据。
- **有功能但容易误以为无效**：3D 角度／距离、俯角阈值和“掌上罗盘”受实际检测模式限制，不能同时影响所有模式。
- **退役键状态**：初审的3个旧INI键中，两项绝对位置已删除并部署；旧整体字号仍保留。后续另按授权删除Y偏移；只读安装检查已发现新输入，执行过程未确认。
- **菜单没有发现必须删除的重复控件**。建议联动灰显、明确帮助文案、修复消费链，而不是删除有效的高级设置。

初审仅记录；随后旧绝对位置键删除已部署，Y偏移删除及X扩大至±200已构建；本轮未打包部署，但只读观察安装文件已更新，且用户保存INI已发生外部变化。两项角度缓存、条件帮助及成对阈值风险尚未处理；先前分组提交已按用户要求撤回；现已重新授权整理文档并分组英文提交；本轮不部署或推送。

## 一、确定缺陷与风险

### P1：两项罗盘角度设置不支持热更新

`include/HUDMarkerManager.h` 中：

```cpp
float facingAngle = settings::display::angleToShowMarkerDetails;
float keepFocusedAngle = settings::display::angleToKeepMarkerDetailsShown;
```

这是成员初始化时复制，不是实时引用。`source/settings/Dispatch.cpp` 只更新 settings 变量；`ApplyAllSettings()` 没有刷新这两个成员。`BasicMarkers.cpp` 和 `QuestMarkers.cpp` 持续使用缓存值，单例为进程级静态实例。

提取生产字段声明、实际设置分发块和标记判断表达式，用 MSVC 编译最小探针，结果：

```text
CONFIRMED: live settings=60/80; existing consumer=10/35; recreated consumer=60/80
```

即：更新设置后原对象仍使用 10／35，重新构造才使用 60／80。探针不等于游戏重启实测；但确认了消费值与热重载变量脱节。应改为实时读取，或在设置应用时显式同步。**不要把这两项删掉来掩盖问题。**

### P1：VR可见性修订已部署，实机门控仍待验证

旧安装日志 42 次注视采样均为 mode=2/0，而 Palm 已找到 PlayerWorldNode 下的真实 compass NIF。配置值为“罗盘节点”不代表实际正在使用节点模式。最新实现已加入VR根搜索、路径核验、唯一候选及缺失否决，并已部署；旧日志不证明新实现仍漏查，也不证明已经修好实机问题。

最新源码中，启用“要求罗盘可见”且 VR 节点缺失／有歧义时，列表不显示；这会限制“高模式缺节点时自动回退”的可见结果。菜单帮助目前未完整解释这一独立门控，应同步补充。

### P2：条件项缺少清晰联动说明

- 实际模式 1／2：使用 3D 显示角、保持角、最大距离；不用俯角阈值或掌上方向开关。
- 实际模式 0：使用俯角显示／保持阈值，以及掌上方向开关；不用 3D 角度或最大距离。
- 关闭“要求注视罗盘”：上述检测参数不参与注视门控，但“要求罗盘可见”仍可独立阻止列表显示。
- “掌上罗盘”只在俯角模式决定低头／抬头方向，不会启用 Palm、切换手掌、移动罗盘或更改 3D 节点跟随。
- 未发现地点完全隐藏时，其详情开关没有可见对象可作用；敌人标记关闭时，敌人名称开关没有显示结果。
- 额外目标数量仅在“任务信息＝目标”时附加，不作用于“地点”模式。

当前 JSON 没有为这些控件声明条件联动。建议保留功能、补齐灰显／说明；由于节点可能自动降级，不能只按配置模式武断删除备用参数。

### P2：合法菜单范围内仍能构成矛盾阈值

菜单和分发没有校验参数对的关系：

- 3D 注视宜满足：保持角 ≥ 显示角。
- 俯角模式宜满足：保持角 ≤ 显示角。
- 罗盘标记的保持角小于开始角时，原判断中的“或开始角”分支可能让保持角失去独立效果。

例如 3D 显示角 30、保持角 10、当前读数 20，按现有状态表达式会在进入／退出间交替，可能反复清空 0.3 秒稳定计时。这是逻辑推演，尚未在 VR 中复现；不是用户当前问题的已证实原因。建议参数对校验或明确警告，不悄悄重写用户保存值。

### P3：帮助文案与校验工具不一致

- 敌人名称帮助写“非直接战斗时”；本项目的 `ProcessEnemyMarker()` 消费点没有独立的战斗判断。是否显示仍可能受游戏原生标记影响，不应将这段帮助当作本项目保证。
- “掌上罗盘”、检测回退、最大注视距离帮助未充分突出模式限制。
- `verify_mcm_config_zhcn.py` 本轮报 1 处失败：中文日志帮助中的 `HUD` 不在英文缩写白名单。这是校验规则与文案不一致，**不是对应设置不生效的证据**。屏幕／日志英文要求与 MCM 汉化是不同范围。

## 二、原29项逐项审查清单（保留原编号）

“链路存在”仅代表已核对注册、分发及消费位置，不代表实机逐项验收。每个显示项仍受对应对象存在、焦点和父级显隐约束。

### 罗盘页：13 项

| # | 设置 ID | 结论 | 实际作用／限制 | 消费位置 |
|---|---|---|---|---|
| 1 | `uUndiscoveredLocationMarkers:Display` | 链路存在 | 未发现地点隐藏／问号／正常图标；仍受游戏距离与标记条件影响 | hooks/Markers.cpp；hud/BasicMarkers.cpp |
| 2 | `bShowEnemyMarkers:Display` | 链路存在 | 控制敌人标记是否进入更新分支 | hooks/Markers.cpp |
| 3 | `bShowInteriorMarkers:Display` | 链路存在 | 允许特定父子 worldspace 关系的标记通过；不是列表“室内显示”的重复项 | hooks/Markers.cpp::AllowedToShowMapMarker |
| 4 | `fAngleToShowMarkerDetails:Display` | **热更新失效** | 新值已读取，现存单例的 facingAngle 不刷新 | HUDMarkerManager.h；hud/BasicMarkers.cpp／QuestMarkers.cpp |
| 5 | `fAngleToKeepMarkerDetailsShown:Display` | **热更新失效** | 新值已读取，现存单例的 keepFocusedAngle 不刷新 | 同上 |
| 6 | `fFocusingDelayToShow:Display` | 链路存在 | 实时读取标记聚焦延迟；任务列表另有固定 0.3 秒稳定等待，不由此设置取消 | hud/Focus.cpp；QuestPresentation.cpp |
| 7 | `bShowUndiscoveredLocationInfo:Display` | 条件生效 | 未发现标记允许出现后，决定能否提供名称／距离详情 | hud/BasicMarkers.cpp |
| 8 | `bShowEnemyNameUnderMarker:Display` | 条件生效／文案待澄清 | 关闭时不查询 NND、名称设空；敌人标记关闭时没有可见效果 | hud/BasicMarkers.cpp |
| 9 | `bUseMetricUnits:Display` | 链路存在 | 初始化及重载调用 SetUnits，影响距离换算和单位 | ui/Compass.cpp → Compass.as → CompassMarkerInfo.as |
| 10 | `bShowObjectiveAsTarget:Display` | 链路存在 | 切换任务标记下的目标／地点文字；不是 QuestList 总开关 | hud/QuestMarkers.cpp |
| 11 | `bShowOtherObjectivesCount:Display` | 条件生效 | 只在目标文字模式且目标数大于 1 时追加数量 | hud/QuestPresentation.cpp |
| 12 | `fMarkerNameScale:Display` | 链路存在／布局约束 | 25～150%，单独缩放名称字段；实际可读区域仍受视口保护 | SettingsLifecycle.cpp／InfinityUI.cpp → SetNameScale |
| 13 | `fMarkerDistanceScale:Display` | 链路存在 | 25～150%，距离及高度指示器一起缩放，维持原底边 | SettingsLifecycle.cpp／InfinityUI.cpp → SetDistanceScale |

### 任务列表页：15 项

| # | 设置 ID | 结论 | 实际作用／限制 | 消费位置 |
|---|---|---|---|---|
| 14 | `fOffsetX:QuestList` | 实机效果待查 | 源码范围现为-200～200，新增最终SWF Passenger端点位移及缓存回归；用户实机效果仍待查，未部署 | questlist/Bridge.cpp → list/Core.as／Layout.as |
| 15 | `fOffsetY:QuestList` | **已删除，安装输入已核对** | 因默认Passenger几何抵消Y位移，按授权删除整条设置链路，不再提供该选项 | 菜单／INI／C++／AS2已清理 |
| 16 | `fTextScale:QuestList` | 链路存在／自适应 | 25～110% 为期望大小；空间不足会缩小／省略，实际比例不保证始终等于请求值 | SettingsLifecycle.cpp → list/Core.as／Layout.as |
| 17 | `bShowInExteriors:QuestList` | 条件生效 | 决定外景允许显示；其他门控仍必须满足 | questlist/Bridge.cpp::CanBeDisplayed |
| 18 | `bShowInInteriors:QuestList` | 条件生效 | 决定内景允许显示；不是穿门户显示标记开关 | 同上 |
| 19 | `bHideInCombat:QuestList` | 链路存在，旧键兼容 | 实际按 IsWeaponDrawn 隐藏，**不是战斗状态**；不重复、更不应因旧键名删除 | QuestPresentation.cpp → Bridge.cpp |
| 20 | `bRequireLookingAtCompass:QuestList` | 链路存在 | 开启注视要求；关闭后仍受焦点、可见性和其他策略约束 | hud/Gaze.cpp；QuestPresentation.cpp |
| 21 | `bRequireCompassVisible:QuestList` | **现有安装有已知缺陷** | 旧安装漏查 VR 根；最新修复已构建未部署。关闭此项不保证实际隐藏的父级会渲染列表 | hud/Gaze.cpp／SceneNodes.cpp |
| 22 | `uCompassGazeMode:QuestList` | 条件生效／安装差异 | 配置模式 0／1／2；实际可能降级。旧日志全为 2/0，不可只看菜单值 | hud/Gaze.cpp::GetEffectiveGazeMode |
| 23 | `fCompassGazeAngleToShow:QuestList` | 条件生效 | 要求注视开启且实际模式 1／2，用于进入阈值 | hud/Gaze.cpp |
| 24 | `fCompassGazeAngleToKeep:QuestList` | 条件生效 | 同上，用于已激活时保持；参数对关系未校验 | hud/Gaze.cpp |
| 25 | `fCompassMaxDistance:QuestList` | 条件生效 | 实际模式 1／2 的头部到节点距离，游戏单位；不是任务目标距离 | hud/Gaze.cpp |
| 26 | `fCompassGazePitchToShow:QuestList` | 条件生效 | 要求注视开启且实际模式 0，控制进入俯角阈值 | hud/Gaze.cpp |
| 27 | `fCompassGazePitchToKeep:QuestList` | 条件生效 | 同上，用于保持阈值；不是 3D 保持角的重复项 | hud/Gaze.cpp |
| 28 | `bCompassOnPalm:QuestList` | 条件生效／易误解 | 仅模式 0 决定低头／抬头方向，不是 Palm 集成或手部选择总开关 | hud/Gaze.cpp |

### 调试页：1 项

| # | 设置 ID | 结论 | 实际作用／限制 | 消费位置 |
|---|---|---|---|---|
| 29 | `uLogLevel:Debug` | 链路存在 | Trace／Debug 同时开启普通 HUD 诊断及详细日志；Info 及以上关闭普通诊断。独立校准另管 | Settings.h → SettingsLifecycle.cpp；Debug.as |

## 三、审查基线与删除后的注册键

审查时37个注册键减去29个菜单项，剩余8个；删除两项旧位置键及Y偏移后，当前34个注册键、28项菜单，菜单外剩6个（一项旧整体字号、五项校准）：

| 类别 | 键 | 处理建议 |
|---|---|---|
| 已不应用的旧整体字号 | `fMarkerTextScale:Display` | 解析兼容，不再由设置应用链调用整体缩放；可清理默认文件中的无效配置或明确标注，兼容解析是否删除需另行决定 |
| 已不应用的旧绝对位置 | `fPositionX:QuestList`、`fPositionY:QuestList` | 已按授权移除变量、注册、分发和发布默认值；fOffsetX保留并扩为±200，fOffsetY随后删除，用户保存文件不重写 |
| 有效的独立校准 | `bCalibrateQuestList:Debug`、`uCalibrationAxis:Debug`、`fCalibrationStart:Debug`、`fCalibrationStep:Debug`、`fCalibrationCross:Debug` | 有调用和 AS2 校准消费链，不是废项；保持高级 INI 工具定位，不因菜单没有就删除 |

最大高度和独立普通 Debug 开关未出现在当前28项菜单中，不需要再删一次。校准开启时会影响普通诊断／列表显示，应与日志级别区分。

## 四、当前保存值与证据边界

本轮只读检查确认：

- MCM 保存层：要求注视＝1、要求可见＝1、配置模式＝2。
- MCM 保存层：`bHideInCombat=0`。**如果当前进程已正确加载这份配置，“拔出武器时隐藏”便不是本次列表消失的原因。** 不能仅凭磁盘值保证进程已重载，仍需 QL／设置日志。
- 部分角度和掌上方向没有保存键，按低优先级层／内置默认值回退，不是自动视为 0。
- 现有主包与 CHS 的 MCM JSON 分别与项目母本一致；这不说明最新 DLL／SWF 已部署，也不排除其他 MO2 覆盖来源。

证据：`test_mcm_bindings.py` 11 项通过；全量中文校验器明确有 1 处 HUD 缩写失败；原生缓存探针确认两项热更新缺陷。探针保存在忽略的 `build/journal-art-review/mcm-audit/`。

## 五、建议顺序

1. 修复两项标记角度的缓存消费问题，加入“已有实例改设置”的回归。
2. 将已构建的 VR 根查找／可见性修复按单独授权部署，用新日志定位实际门控。
3. 补齐模式限定、Palm 开关含义、回退与独立可见性要求的帮助说明；必要时联动灰显，不先删控件。
4. 增加阈值参数对的校验／提示；保留用户原始配置，不静默重写。
5. 整理 3 个兼容 INI 残留与中文校验缩写规则；5 个独立校准键保留。

两项旧位置键删除后已通过48项Python、DLL编译和打包校验，尚未部署。其余审查结论仍是待整改项，不是“所有设置已修好”的声明。后续修改菜单／源码、部署和提交应分别记录授权与验证。
## Y偏移退役与X范围扩展

2026-09-13 后续源码变更（未部署）：删除 QuestList 的 fOffsetY 菜单、默认值、注册／分发、变量、桥接、AS2 动态偏移及诊断字段；fOffsetX 范围统一为 -200～200，默认0、步长5。固定垂直布局与跟随罗盘保留，Passenger内部固定几何和独立Palm测试面板同名坐标不属于该设置，未修改。已有用户INI未改，更新后的DLL将忽略旧QuestList Y键。49项Python测试、原生编译、54项最终SWF布局模拟和15组观察器回归通过；X实机效果及两项角度缓存缺陷仍待处理。该开发轮未打包部署或提交；随后文档整理与分组英文提交已获授权，不推送。
## 提交前安装状态只读复核

本轮提交前只读检查发现，安装DLL、两份Compass、中英文MCM及两份默认INI与最新工作区产物一致；它们已不同于上次授权部署清单，另有用户保存设置及模组管理元数据变化。文件时间早于本轮操作，变更执行者和备份过程未确认。本轮没有打包部署，不覆盖或回滚这些文件；旧清单仅作历史证据，当前安装以本轮只读快照为准。文件一致不等于游戏已加载或实机验收通过。

与旧清单相比：3个部署文件变化，1701项保护记录中8项变化（MCM保存文件、2份默认INI、2份菜单配置及3项模组管理元数据）；其余1693项匹配。新版DLL和两份Compass、中英文MCM、两份默认INI逐项匹配当前源／构建输入。该差异不归因于本轮编译，不执行还原。
