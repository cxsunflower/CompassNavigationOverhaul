<!-- 定位：L2 整理前指南与旧 Passenger 方案存档，仅保存历史证据，不是当前实现或部署指引。 -->

# 整理前指南存档

2026-09-10 文档符合性审查将旧指南中的历史材料归档。下文的“当前／最新／已部署”均指各原记录形成时，不代表现在。原文保留便于追溯；现行规则以 [QuestList](quest-list.md)、[MCM](mcm.md)、[HUD Debug](hud-debug.md) 为准。
特别注意：旧 Passenger 笔记中“所有 Debug 都用 Passenger 空间”的建议已废弃；当前布局在 Target，根级 Debug 必须将四角转为 root。旧红框、R/L 标签及旧缩放范围不再使用。

## QuestList 整理前材料


# QuestList：当前实现与验证

## 显示路径与迁移边界

本页的完整QuestList当前仍运行于Compass内嵌共享HUD路径。760～960候选连续带及其窗口钳制只约束这一模式，不是独立掌上面板的通用安全区。

新掌上NIF/DDS目前只是静态原型，未接任务数据、未获VR验收，不替代本页实现。迁移时保留坐标一致性、完整目标行/菱形、换行、省略优先级和装饰/排序/淡入要求，但按新载体视口重新验证；不能机械搬用旧边界，也不能提前删掉旧修复。详见[旧测试价值与迁移门槛](palm-test-panel.md#架构转向复盘旧边界测试的价值与适用范围)。下方带日期的测试/部署/未提交描述为各次操作当时记录，最新状态以CONTEXT及当前阶段为准。

## 2026-09-10 省略号挤掉全部可读目标
02:51日志中前两条文字底边927.42/953.74均低于960，但34高省略字段加8间距预留把内容底边降到918，导致全目标隐藏。省略字段现跟随实际item比例SCALE*effectiveScale/100（90时58.5%）；宽高按真实显示尺寸测量。额外保护每项任务最后一条原本可显示的目标，若省略号会将其挤掉，则恢复未预留时的完整行并不画省略号。保护正文规则保留；不改位置、候选带760～960、面板缩放或目标行排序。
模拟器补正TextField显示宽高包含自身缩放、textHeight保持本地测量，避免假测试掩盖省略字段尺寸。56/56反编译模拟、24/24 Python、SWF哈希和打包通过，两份Compass部署哈希一致；100个受保护文件未变，备份`_patch_work/compass-debug-scale-20260910-025957`。DLL未改，未暂存/提交，实机待重启验证。


## 2026-09-10 根据采样限制连续显示带
实机标定记录：中心X=512的Y740在罗盘附近、750已在上方，745标记不完整不能硬判；X400/600的Y740仍在下方，760～900位于上方。Y900起步长20采样，图中可辨900～980，1000/1020未见。说明共享显示路径存在分段；这些是采样点观察，不是全宽、所有姿态已标定的UV矩形。

普通Passenger采用候选根坐标带Y760～960（1024舞台），不再只减去底部8%。上下界约束布局、完整段/行省略、面板遮罩与debug；窗口只能在带内移动，不能为保留220高度跨到上方接缝另一侧。固定宽度、原始装饰、110期望上限/min(90,期望)下限不变。父级仍为Target，偏移在安全窗口内受限；窗口已占满可用高度时，纵向偏移可能被边界钳制。

对转换后的局部窗口，在左右两个X端点分别求满足根坐标四边的Y区间，避免旋转情况下直接用逆变换AABB误放行。标定独立节点与dedicated分支不使用此限制；GetSharedHudSafeTop/Bottom按舞台高度归一化换算，非1024尺寸仅为比例假设，未实机验证。横向仍使用已有逻辑宽度/舞台保护，不宣称全宽已标定。

新增变换父级旋转±12度、缩放和±100偏移测试；54/54反编译模拟、24/24 Python、完整构建（DLL已最新）/双语/打包校验通过。仅两份嵌入Compass部署哈希一致，100个受保护文件不变，备份`_patch_work/compass-debug-scale-20260910-024721`。未暂存/提交。

验收：用户将bCalibrateQuestList改0并重启，比较上方完整装饰、正文、目标、省略号与跨区残片。候选带仍待实机验证，不保证任意长度任务全部显示。


## 2026-09-10 独立边界标定模式
新增INI独立开关 `bCalibrateQuestList:Debug`，默认false；axis/start/step/cross默认0/700/40/512。原生注册、分发、启动/重载同步至SetCalibration，记录QuestListCalibration状态。不开新MCM控件，不写回保存设置。

开启时正常QuestList透明度为0、普通调试框隐藏并暂停布局求解；标定节点是同Target父级下的独立兄弟节点，用根坐标短十字/标签采样，不经过QuestList遮罩或8%保护。保留祖先可见性与实际显示路径，关闭/卸载移除标记并恢复正常布局。此为人工采样工具，不代表已测得边界，不修改UV网格。

同时包含上一轮尚未部署的固定锚点修正：不再为保留220逻辑高度而整体上移，而是在原锚点以下与安全底边相交取剩余高度；顶部装饰消失的实际原因及恢复效果仍需实机确认。

53/53反编译布局/状态模拟、24/24 Python、完整DLL重编、双语和主包14/CHS1打包校验通过。14文件已部署且哈希一致，88个受保护文件不变；备份 `_patch_work/compass-full-deploy-20260910-021019`。标定保持默认关闭；未暂存/提交。首次使用须重启。详见[标定操作](../user-manual/calibration.md)。


## 2026-09-10 目标底部跨到上方：恢复共享HUD保护
用户确认分离红紫线对应下方目标区域，不能作为独立调试图形处理。01:43实机快照：期望100/实际90，完整底边1018.31、mask底边1012，首目标文字底边959.32；后两行已隐藏、省略号可见。该日志证实仍放行到原有底部保护之外，但不构成精确UV边界标定。

Passenger窗口与FitsViewport重新使用 `Stage.height-max(20,Stage.height*0.08)` 的共享HUD底边，1024时为942.08。窗口必要时整体上移，保持现有逻辑宽高与罗盘层级；mask和debug线段同步限制，专用独立影片不应用共享HUD保护。维持自动下限90和主动低于90的设置，仍按完整段/行省略。锚点增加0.1界面坐标余量，避免Scaleform twip舍入把4px边距误判溢出。

日志将原本错误标注Root的实际布局空间值更名为safeLimitLocal/contentLimitLocal/visibleBottomLocal，并明确layoutSpace及sharedHudSafeBottomRoot。新增按实机父级Y=706.45的回归，检查90下限、目标可见行、mask与debug底边及偏移后保护。

52/52真实反编译模拟、24/24 Python及完整build.bat/打包校验通过（DLL已最新）。两份内嵌Compass增量部署哈希一致，100个受保护文件不变；备份`_patch_work/compass-debug-scale-20260910-014624`。未暂存/提交。需重启实机对比同任务的目标、省略号和上方残片；不能宣称VR映射已修复或所有内容保证完整显示。


## 2026-09-10 调试白块与 Passenger 过度缩小
- 实机日志：期望 panel=110，实际 effective=25。Passenger 配置单独使用 scale=70/minScale=25，绕过原有 110 上限与 min(90,期望值) 下限；现同步为 110/90。保留 Target 子级跟随、固定逻辑区域、偏移及正文省略，不修改玩家保存值。
- 调试几何曾转换成 Target 局部坐标，但 overlay、裁剪窗口和标签都在 root，导致混用。统一四角转换到 root。保留工作区已有的取消实心填充修改，删除多余的调试 ClipMask，只保留无底色文字与线条；不改正常内容遮罩。原有修改未同步到构建哈希，本轮已重新编译并嵌入两份 Compass。
- 新增 Passenger 模式缩放及旋转/缩放父级下的调试四角、无填充回归；测试读取真实反编译的配置，不再用硬编码 70/25 掩盖活动分支。模块函数清单旧断言 44 已按现有 55 个函数同步，本轮没有新增运行时函数。
- 51/51 反编译布局/状态模拟、24/24 Python、双语、三项构建哈希及主包14/CHS1打包一致性通过。仅增量部署两份内嵌 Compass，哈希一致；DLL、用户设置、汉化及MO2状态等100个受保护文件未变。备份 `_patch_work/compass-debug-scale-20260910-012723`；未暂存或提交。
- 待验收：重启游戏，在同一任务下开关Debug，确认不再出现白色实心区域，框随内容对齐；面板期望110时effective不低于90（玩家主动设置低于90除外）。现有Passenger区域仍是逻辑限制，不能据测试宣称VR物理显示边界已标定。


## 当前：相对偏移与自动高度
最新布局：原版Title完整纳入不可见`DetailBox`的Header，正文、目标分隔装饰及目标行位于DetailBody。原装饰决定自然宽度，统一布局汇总Header和Body高度并交给现有安全区适配；原18帧动画驱动整个Box。独立遮罩仅作用Body，用于极端绘制越界。长文本优先在固定宽度内换行，纵向放不下则按既有完整段落/行省略。
任务列表使用 `fOffsetX:QuestList` / `fOffsetY:QuestList`，默认均为 0；当前代码、SWF 和 MCM 已统一限制为 **-100～100**、步长 5。偏移单位为罗盘 Target 父容器的界面坐标；正 X 向右、正 Y 向下，最终位置仍是名称下方默认锚点加偏移并持续跟随罗盘。

菜单和活动实现中的最大高度设置均已移除。当前默认 INI、C++ 设置变量/注册/分发、C++/AS2 接口与活动回归均不再提供 `fMaxHeight` / `maxHeight` / `SetMaxHeight`；布局只按偏移后的面板起点与安全底边计算可用高度。历史反编译/退役补丁工具保留原版痕迹，不参与当前发布链。

面板期望上限仍为 110%，自动缩小下限仍为 min(90,期望值)，现为固定装饰内宽→缩小→省略顺序；安全底边和名称原位渐变不变。偏移过大时面板可能超出安全区而隐藏，应从 0 开始小幅调整。

验证与部署：源码已拆为13个职责模块，仍组合为原两个AS2入口。最新红框可见性修复通过10/10模块测试、47/47真实SWF反编译布局模拟、3/3包装器、MCM10/10及三项SWF哈希检查；主包/CHS已重建，13/13主包文件与安装一致。2026-09-09 15:41两份嵌入式Compass已增量部署到MO2 Default，备份`_patch_work/compass-deploy-20260909-154123`。本轮C++/DLL、原始素材、用户配置及MO2状态未改，VR实际安全边界和视觉效果仍待复测。

### 当前待验收项
- 经SKSEVR重新启动游戏验收已部署的高度修复和调试叠加层；不要单独部署`QuestItemList.swf`。
- VR 中验证 MCM 保存/重载、X/Y 到 ±100 的边界、偏移后持续跟随罗盘，以及自动安全高度没有回归。
- 检查正文、OBJECTIVES 装饰、目标菱形及文字均在原详情装饰内；覆盖长英文单词、中文长文本、长翻译、镜头运动后的换行/省略恢复。
- 复现Miraak任务截图中的提前省略，采集实际根坐标安全区、完整/可见底边和目标行状态；未取得数据前不扩大VR安全边界。
- 开启Debug并采集同一画面红框截图，检查红框、数字标签与原版装饰、隐藏行的相对位置；关闭调试后确认普通HUD无残留。

### 提前省略与运行时诊断
高度适配、整段/整行裁切和省略号使用同一根坐标空间，不再把全局Y通过任意X转换。缓存记录适配后的几何，内容或动画变化会触发重新求解。省略号仅在真正隐藏内容后预留，并放在最后可见内容之后；若它会挤掉原本可读的描述或自身放不下，则不显示。空Body余量不再构成省略原因。安全底边及原有缩放下限不变，不能把截图视觉空白直接当作Flash可用高度。

新`GetLayoutSnapshot`在按需调用时刷新一次布局，并通过原有`[QuestListLayout]`日志入口输出诊断。部署后在同一任务画面打开MCM，将任务列表缩放临时调整一个步长再恢复，关闭菜单以触发设置应用，查看本次SKSE插件日志。需要保留`stage`、`rootScale`、`safeLimitRoot`、`contentLimitRoot`、`renderedBottomRoot`、`visibleBottomRoot`、`headerHeight/bodyHeight/bodyWidth`、`fitReason`、`omissionReason`及目标行可见状态。日志不按每帧输出；只需与截图对应的一次采样。若日志仍显示实际完整内容超过安全区，应先核实VR贴图映射和真实可视边界，禁止盲目扩大Stage安全区或恢复已撤回的UV补偿。

### 当前 HUD Debug
2026-09-10 已用单一 Compass 观察器替换旧的红框、坐标表、逐行屏幕标签与旧式日志级别联动绘制方案。开关为 MCM 日志级别：Debug／Trace 开启，Info 及以上关闭（默认 Info）；最多两行中文状态，详细几何只写 `[HUDDebug]` 日志。覆盖距离、箭头、聚焦标记、名称与列表 Q/F/V，尊重共享父级隐藏，不修改布局。边界校准移至独立模块保留。

当前用法、边界定义、采样策略及验证状态见 [HUD Debug](hud-debug.md)。原 BOM 输入兼容与三层 INI 优先级继续保留；旧红框部署／排障过程只在 S2 历史记录中追溯，不再作为启用方法。**新方案已构建但尚未部署，VR 待验收。**

## 2026-09-09 顶部残片与详情黑边后续

上轮清除 Glow 未处理素材本身的黑边：标题装饰形状存在 17 条黑色 76 twips（3.8px）描边，多数禁止垂直缩放且采用高 miter 尖角。构建时从 `assets/source/questlist/art/QuestItemListArt.original.swf` 重建两份发布素材，改为 20 twips、可缩放圆角，保留填充、曲线、任务类型时间轴及目标素材。此处是已证实的素材问题，不能据此断言截图全部黑色均来自该描边。

列表遮罩改为排版后计算实际内容并留 4px 描边余量，与舞台边界相交；不再仅遮住舞台外区域。顶部“◆ …”来源尚未证实，此项仍是防护性修正，未禁用原生任务提示，也未修改 VR UV/网格。

18/18 反编译布局/状态测试、三个构建哈希校验及主包/CHS 打包通过。导出龙形素材检查黑色尖角已消除；4 个更新 SWF 已于 00:41 备份并部署主包，哈希逐一一致。游戏整体显示仍待验收。全仓 `git diff --check` 报既有 CMakeLists.txt 文件末尾空行，本轮相关文件检查无新增空白错误；未暂存、未提交。

[文档索引](../CONTEXT.md) · [历史记录与回退原因](quest-list-history.md) · [工具说明](../../tools/README.md)

本页描述当前工作区实现；历史方案保留在独立记录中，不作为部署指引。版本号以根目录 `vcpkg.json` 的 `version-string` 为准。

## 内容与排序

- 内容从上到下：原有标题装饰、日志详情、目标分隔区、逐条目标。仅杂项任务显示任务名。
- 日志详情与目标是独立内容，不互相替代；空详情不占正文，空目标不显示分隔区。
- 原生层按 owner / instance / objective index 收集、去重目标，保留显示、完成和失败状态。
- 进行中目标在前；已完成组按原始目标序号倒序；失败组在后。进行中与失败组保留原顺序。
- **排序限制**：当前没有完成时间戳，目标序号倒序不等于严格的完成时间倒序，无法精确恢复非线性完成历史。
- `SyncQuests` 按任务键与内容签名更新，避免未变化内容反复重建和重启动画。

## 字体、装饰与布局

正文使用 `$EverywhereMediumFont` 的 Normal 字体（`bold=false`、`italic=false`），兼容当前中文字体包。普通目标为白色，完成/失败文字为灰色。长文本按换行后的实际高度测量；高度限制隐藏完整段落或行，不裁半行。

完整层级为`QuestItem → DetailBox → Header + DetailBody + DetailContentMask`。Header是未修改的原版Title符号，包含Bracket、EndPiece、TitleTextField；Body包含正文、目标分隔区和目标容器。构建期新增包装Sprite 306，将原18帧时间轴的Title放置改为外层DetailBox，保留原矩阵/alpha关键帧及Header符号。`this.Title`作为兼容引用指向Header，不在运行时复制或销毁原素材。

横向安全区在每次`SetQuestInfo`选择任务类型后，从Header实际Bracket/EndPiece边界计算，左右各留12px（窄装饰时保留至少32px内容宽度的退让规则）。外层Box拥有`layoutLeft/layoutTop/layoutWidth/layoutHeight`完整逻辑矩形，Body拥有独立`layoutWidth/layoutHeight`，位于装饰底边下方4px。`LayoutDetailBox`统一测量正文换行、分隔标签/双翼及目标行并累加高度；空区不占高度。外层逻辑矩形包含Header与Body，四角变换后供现有安全区使用，不由未裁切素材的`getBounds`撑大。`ReflowWidth`仅在自然内宽以内调整Body，最小48px，不缩放原Header。`DetailContentMask`是外层Box的子级，仅裁切Body，留4px滤镜余量。原素材和VR UV/网格保持不变。

| 元素 | 当前设置 |
|---|---|
| 正文、目标文字、目标标签 | 黑色 Glow：blurX/Y=3、strength=3 |
| 原任务标题装饰 | 黑色 Glow：4/4/4 |
| 目标分隔装饰 | 复用任务详情标题装饰的黑色 Glow：4/4/4；不再额外灰色扩边 |
| 状态菱形 | **保留原描边 4/4/4，不加粗**；尺寸 18×27，失败态透明度 50% |

上述黑色滤镜均为 alpha=1、quality=2、inner=false、knockout=false。目标标签使用 `$OBJECTIVES` 翻译键，左右装饰按标签实际宽度等长布局。源素材、SVG 与 SWF 符号映射见 [美术资源说明](../../assets/source/questlist/art/README.md)。

## 显示、定位与缩放

- 显示要求任务标记 yaw 聚焦、罗盘可见及 3D 视线看向罗盘，同时成立 0.3 秒后弹出；任一条件失效立即隐藏。
- 注视检测提供罗盘节点、右手节点和俯角兜底模式，节点缺失时降级。具体默认参数见 `include/Settings.h` 与 MCM 配置。
- QuestList 静态嵌入 `Compass.FocusedMarkerInfo.Target`，与任务文字共享父级；以文本框底部中心为锚点，间距 6，每帧更新定位。
- 这不保证 VR 中列表跟随手掌：Flash 父子关系不能改变原 HUD 网格的 UV 取样范围。当前接受撤回补偿后的原显示方式。
- **Palm 80px 贴图重排、UV/网格补偿及安全区自适应缩放均已撤回，不得恢复。**
- MCM 分别提供任务名缩放、距离缩放与任务列表面板缩放（25–300%，默认 100%）；面板缩放对应 `[QuestList] fTextScale`。旧 `fMarkerTextScale` 保留解析但不生效。

## 源码结构与编辑入口

QuestList的两个原入口现在仅保留类/时间轴声明、状态和模块引用：`swf/QuestItem.as`及`swf/QuestItemList.as`。实现位于`swf/questlist/item/`（初始化、装饰、内容、布局、几何、调试、生命周期）与`swf/questlist/list/`（核心、条目、适配、溢出、诊断、调试），共13个模块。[完整目录与职责](../../swf/questlist/README.md)。原有C++接口、QuestItem链接类、六参数传递、Header包装器与18帧动画均保留，不引入独立运行时SWF或新的继承链。

`tools/questlist_source.py`在编译前展开明确的`// @include`指令，使用统一的`swf/questlist/`相对路径；拒绝缺失、重复、循环、越界和孤立模块，以及重复函数/意外类。新增模块必须登记到对应入口，所有依赖自动进入`questlist-swf.json`哈希清单。不要直接把源片段交给JPEXS，也不要手工维护一份重复的完整AS2文件。可使用`--output build/questlist-sources`生成仅用于检查的组合源码。

## SWF 构建与校验

需要 Python 3、Java、JPEXS 的 **`ffdec-cli.jar`**；反编译布局测试另需 Node.js。本机 JPEXS 路径作为参数传入，不写入项目源码。

```powershell
$ff = '完整路径\ffdec-cli.jar'
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/tests/test_questlist_source.py
# 仅修改 QuestList 时，从这一步开始。
python tools/build_questlist_swf.py --ffdec $ff
# 若改了 Compass.as / CompassMarkerInfo.as / 其内联 utils.as，先重建罗盘基底：
# python tools/build_compass_swf.py --ffdec $ff
python tools/embed_questlist_compass.py --ffdec $ff

python tools/build_questlist_swf.py --check
python tools/build_compass_swf.py --check
python tools/embed_questlist_compass.py --check
```

逐条检查退出码，失败后停止，不继续打包。

构建链：AS2模块 → 原两个入口组合 → 原始基底 + SVG → `assets/generated/QuestItemList.swf` → 两份发布用 `Compass.swf`（HUDMenu / VR_HMD_info）。罗盘源码单独生成 `assets/generated/Compass.before-embedded.swf`，再参与嵌入。源码、基底、生成 SWF 和哈希清单需保持配套；`build.bat` 只检查 SWF 是否同步，**不会自动重编译 ActionScript**。组合器或QuestList构建脚本变更也可能使Compass基线哈希过期，应按当前源码重建基线再嵌入。

`assets/generated/QuestItemList.swf` 是构建中间输入，不是独立注入文件。**禁止单独部署 QuestItemList.swf**。发布使用 `assets/main/Interface/InfinityUI/` 下两份内嵌 `Compass.swf` 与对应美术资源。旧固定字节补丁脚本不适用于当前重编译版本。

### 反编译回归测试

```powershell
java -jar $ff -export script build/questlist-verify assets/generated/QuestItemList.swf
node tools/tests/questlist_layout.test.cjs build/questlist-verify/scripts/__Packages/QuestItem.as build/questlist-verify/scripts/frame_1/DoAction.as
# 如修改罗盘脚本，另验证罗盘缩放接口：
java -jar $ff -export script build/compass-verify assets/generated/Compass.before-embedded.swf
node tools/tests/compass_marker_scale.test.cjs build/compass-verify/scripts
```

导出时 JPEXS 可能提示忽略外部 SWF 导入；脚本导出/模拟测试不能替代完整素材加载及 VR 实机验收。

### 打包与部署边界

- C++ 有修改：运行 `build.bat` 编译并打包。
- 仅 SWF 修改且已有可用 DLL：运行 `build.bat nobuild`，沿用现有 DLL。
- 输出在 `dist/`，`-CHS` 是中文配置覆盖包，不是独立完整主包。
- 打包不会自动部署到 MO2；应另行确认目标模组目录与覆盖顺序。不要把成功打包写成已部署或已通过实机验收。

## 最近验证状态（2026-09-08）

菱形恢复原描边后的版本已重编译并嵌入两份 Compass；**11/11 反编译布局/状态模拟测试通过**。QuestList、罗盘基底及嵌入哈希检查通过，主包与 CHS 包已重打包。本轮未修改 C++，沿用现有 DLL。

此前构建时尚未部署；后续 2026-09-08 22:26 启动记录及 MO2 Default 配置检查已确认启用 主包和 CHS 包，罗盘插件成功加载，已安装 MCM JSON 可解析。此检查不代表全部已安装文件已与构建产物逐一比对，也不代表视觉验收完成。当时菜单不显示的关键异常是 **MCMHelper.dll 加载失败**（已被后续成功注册日志取代），详见 [MCM 排查记录](mcm.md)。字形、分隔描边、目标顺序、注视门控和缩放仍待实机验收。

## MCM 配置与故障排查

名称与距离缩放归属 `[Display]`；QuestList 当前使用 `fOffsetX/fOffsetY` 有效偏移控件，旧 `fPositionX/fPositionY` 仅保留兼容。当前偏移范围为 -100～100、步长 5。配置默认值、中文生成流程、绑定测试和菜单缺失诊断统一见 [MCM 配置与菜单排查](mcm.md)。

## 分隔装饰与文字独立缩放修复
用户确认本次样式范围仅为目标分隔装饰，现复用 TitleBracket 滤镜，文字与菱形保持原样。SWF 检查发现 FocusedMarkerInfo 的动画关键帧反复写入 Target/Distance 容器矩阵，旧缩放与之冲突；名称缩放还会连带影响 Target 下的 QuestItemList。现改为缩放内部 TextFieldInstance，名称保持原中心，距离高度箭头同步缩放及对齐，并在帧更新中重新应用。

反编译行为测试覆盖独立缩放、模拟父容器动画重置、居中、无效输入和箭头位置；11/11 QuestList 测试与构建哈希通过。新包已生成，沿用现有 DLL；本轮 SWF 尚未部署 MO2，游戏内效果待验收。

## 后续实机反馈：缩放仍无效，面板放大被裁切
用户截图显示详情文字被固定区域截断，不是已证实的文本高度不足。最新检查：面板保存为 235%，名称 265%、距离 270%；23:12 启动及后续 INI 重载记录存在。启用模组的 DLL 与上轮构建 DLL、VR Compass 与上轮发布 SWF 的哈希一致，排除该路径下未安装上轮 SWF。

因此此前文字层缩放方案不能标记为修复成功。增加低频诊断：原生 setter 的输入和调用成功状态、SWF 方法类型/保存值/实际缩放及文本矩形，以及列表内容在 HUD 根坐标系的边界。诊断需要配套 DLL 与 SWF；在设置应用、重载和既有限次锚点日志中输出，不每帧写日志。

下一步安装诊断包，重启并修改一次名称/距离后关闭菜单，检查 `[MarkerScale]`、`[QuestListLayout]`、`[QuestListAnchor]`。在取得数据前不改存档、不恢复 UV/网格补偿，也不把纹理取样裁切猜测写成已确定根因。

## 自适应面板排版
MCM 面板缩放为期望值（25%–110%），实际缩放不超过该值。优先逐步扩宽详情/目标文本框，最多自然宽度 1.6 倍、HUD 宽度 80%；仅改变文本换行和分隔线长度，字形及菱形不横向拉伸。若仍放不下，对不同宽度搜索安全区域内可容纳的最大缩放。纵向可用区域由当前锚点与安全底边自动决定，不再保留用户可调的最大高度限制。

缓存由任务签名/顺序、期望大小、舞台尺寸、父变换和锚点网格位置失效驱动，避免每帧重新测量文本。日志提供 effective、widthFactor、overflow 和 fitRuns。极端情况下 25% 仍放不下时保留原有完整段落安全隐藏，标记 overflow；尚未实现分页/滚动，不能宣称无限内容完整显示。名称/距离和分隔装饰图形不在本轮修改范围。

自适应版部署完成：目标机器记录 2026-09-09 00:02；主包和汉化目录共 14 个文件与发布包逐一哈希一致。覆盖前备份：_patch_work/compass-deploy-20260909-000247。面板期望上限仍为 110%，名称/距离上限 200%；15/15 布局/状态模拟、名称/距离回归、中英文 MCM 验证及三份 SWF 哈希检查通过。保留 MCM 保存文件和 MO2 状态，Git 未暂存/提交。待游戏验证扩宽、有效缩放、溢出状态及缓存稳定性；极端内容的分页/滚动未实现。

## 三项视觉问题处理（实机待确认）
截图中的顶部菱形 Fin 残片来源尚未证实：新任务先隐藏至适配完成，退出/移除任务立即隐藏并销毁，不再让退出动画脱离布局集合；增加仅作用于 QuestList 的舞台安全区遮罩。未禁用原版 HUD 提示。
详情与目标分隔装饰撤除后来叠加的 Glow 滤镜，保留素材本身；目标文字/菱形滤镜和尺寸不变。扩宽时按裁剪区直接调整分隔素材及遮罩，不缩放包含隐藏素材的翼容器。标签两侧间隔 6、详情至分隔间隔 6、分隔至首目标间隔 5，装饰高度固定 16。
18/18 模拟测试及构建哈希验证通过。目标机器 2026-09-09 00:26 已部署，14 个文件哈希一致；备份 _patch_work/compass-deploy-20260909-002605。未回写保存值、未改暂存区，反编译 README 未改。三项视觉表现仍需游戏截图确认，不能把防护性修改写成已证明根因。

## 用户确认残片来源：已完成目标行
用户明确顶部“◆ …”为下方已完成目标被截断的部分。代码检查发现行高仅取文字高度，27px 菱形和滤镜可能超出行边界。统一初建与扩宽行高为 max(文字高度, 菱形高度)+8，上下各预留 4px，文字和图标居中；整体布局与整行隐藏复用此高度。保留菱形大小及描边。该缺陷已修正，但截图中顶部呈现机制与最终消失效果仍需 VR 验证。

新增短已完成目标的菱形/描边边界回归，19/19 模拟、三项哈希及打包通过；两份内嵌 Compass 已备份部署，哈希一致。未改设置或暂存区。

## 蓝圈范围澄清与描边回退
用户圈定的是装饰上方的黑色背景区域，之前修改标题素材描边属于误解。现恢复两份 QuestItemListArt.swf 原始字节，构建仍校验素材哈希；打包并备份部署通过。已完成目标的行高/裁剪修正保留。静态检查未发现列表独立黑色背景或父级大范围阴影，截图黑区仍需同视角隐藏面板的对照画面定位，不能宣称修复。

## 黑区随面板消失：素材库背景隔离
用户确认蓝圈黑区随面板消失，UI 关联已确认。静态素材没有背景位图或 opaque placement，但原素材库保留 #333333 的 SetBackgroundColorTag。仅移除此定义并重建两份库资源；其余标签语义一致（JPEXS 对零坐标 moveBits 的编码规范化除外），不改变装饰描边。此为单变量排查，不能把舞台背景定义直接认定为导入实例黑区根因。

构建、三项哈希、主包/CHS 打包通过；两份素材库已备份部署并逐一验证哈希。保留已完成目标行高修正、用户设置与 Git 暂存内容；下一步重启游戏复查蓝圈区域。

## 2026-09-09 名称/距离上限 150% 与海拔箭头
用户已确认此前黑区来自任务/地点名称放大后的下半部分跨到顶部显示。撤回装饰素材描边及背景定义试验，恢复原始素材，不将这些试验当作根因修复。

名称和距离的 MCM 最大值、C++ 设置回调及 AS2 setter 同步限制为 150%（最小 25%、默认 100%）；面板期望上限保持 110%。不回写用户已保存值，超过范围的值在运行时限制。名称菜单改为“任务/地点名称大小”（Quest/Location Name Size），距离帮助注明同时控制海拔上下图标。

原脚本已引用 DistanceScale，但把箭头素材约 35% 的初始矩阵比例直接覆盖，导致异常放大。现缓存每个箭头实例的基础 X/Y 比例，乘以距离百分比，不累计缩放；名称更新不改变箭头大小，箭头定位仍跟随距离文本末端。没有修改海拔阈值或方向判断。

反编译行为测试覆盖名称独立性、距离 25/50/150%、超范围和无效值、连续帧更新及 Above/Below 两种状态；MCM 6 项绑定测试、完整双语/暂存配置检查、SWF 哈希、DLL 编译及主包/CHS 打包通过。MO2 主包和 CHS 的 7 个更新文件已备份部署且哈希一致。未修改用户设置、存档或 Git 暂存区。VR 视觉效果及 150% 是否完全避开采样边界仍待实机验收。

## 距离缩放偏移修复
用户反馈距离缩放后不居中。原代码仅修改距离文字 _xscale/_yscale，autoSize="center" 不能为显式缩放固定中心。现缓存初始距离中心，按文字+可见箭头+间隔的总宽度居中；箭头隐藏时仅居中文字。使用箭头实际 bounds 补偿非零注册点；更新距离时先选择上下状态/可见性，再计算布局。

反编译模拟覆盖米/英尺、3 种距离长度、上/下/隐藏状态及 5 次缩放顺序，共 90 组组合，并检查每组连续 10 帧不漂移。构建、哈希和主包/CHS 打包通过；两份 Compass.swf 已备份部署 MO2 主包，哈希一致。沿用上一轮 DLL/配置，150% 上限与名称缩放独立性保持；VR 实机效果待验收。


## Debug颜色边框诊断（2026-09-09）
调试开关与普通HUD可见性分开；日志中的enabled/overlayVisible只证明叠加层存在，drawnRegions才表示区域绘制已执行。名称TextField的矩形必须通过父MovieClip转换四个角点，不能调用TextField.getBounds或localToGlobal。当前文字摘要隐藏的选择保留，颜色边框可独立绘制。重启后的VR显示仍须实机确认。



## MCM 整理前材料


# MCM 配置与菜单排查

## 当前：相对偏移与自动高度
任务列表当前使用 `fOffsetX:QuestList` / `fOffsetY:QuestList`，默认均为 0；MCM/C++/SWF 已统一为 **-100～100**、步长 5，C++ 与 AS2 均做同一边界 clamp。

最大高度设置已从活动配置与实现完整退役：默认 INI、C++ 设置注册/分发/变量、C++/AS2 `SetMaxHeight` 接口均已删除；可用高度只由自动安全区计算。回归测试改为检查退役设置不存在，防止后续误恢复。

面板期望上限仍为 110%，自动缩小下限仍为 min(90,期望值)，扩宽→缩小→省略顺序、安全底边和名称原位渐变不变。偏移过大时面板可能超出安全区而隐藏，应从 0 开始小幅调整。

验证与部署：最新UTF-8 BOM读取兼容修复已完整重编并于2026-09-09 16:15部署MO2 Default。原生4/4、MCM11/11、布局47/47、包装器3/3、罗盘、双语及主包13/CHS1校验通过；用户保存文件与MO2状态保持不变。VR实际红框仍待复测，详细证据见下方及[QuestList当前说明](quest-list.md)。


[文档索引](../CONTEXT.md) · [QuestList 当前说明](quest-list.md) · [工具索引](../../tools/README.md)

## 配置来源与安装关系

英文配置和默认 INI 位于 `assets/main/MCM/Config/Compass Navigation Overhaul VR/`；中文覆盖包独立放在 `assets/localization/zh-CN/`：

| 文件 | 用途 |
|---|---|
| `config.json` | 英文菜单母本，随主包发布 |
| `assets/localization/zh-CN/MCM/Config/Compass Navigation Overhaul VR/config.json` | 简体中文母本，以同路径 config.json 覆盖英文配置 |
| `settings.ini` | MCM 默认值，随主包发布 |

CHS 是覆盖包，必须与主包配合并覆盖主包的同路径 `config.json`，不是完整独立模组。`modName`、ESP 主干与 MCM 配置目录名保持 `Compass Navigation Overhaul VR`；不翻译 ID、sourceType 或数值占位符。模组名称及日志级别英文有意保留，日志选项同时带中文解释。

设置加载优先级从低到高：

1. `Data/MCM/Config/Compass Navigation Overhaul VR/settings.ini`
2. `Data/SKSE/Plugins/CompassNavigationOverhaulVR.ini`
3. `Data/MCM/Settings/Compass Navigation Overhaul VR.ini`（用户保存值）

修改默认配置不保证覆盖既有用户设置。不要为排查菜单注册问题直接删除用户 INI 或清理存档。

### UTF-8 BOM 首节兼容（2026-09-09）

16:03–16:05日志显示已安装最新DLL、嵌入式QuestList接口存在，但Debug请求仍为false。实际保存的MCM INI以UTF-8 BOM开头且`[Debug]`是首节，`uLogLevel=1`。直接使用Windows配置API验证：原文件的Debug键返回缺失，后续QuestList键正常；去掉临时读取副本的BOM后Debug键可读。问题是原生INI解析兼容性，不是MCM没有保存或红框被遮罩裁切。

`include/utils/INIInput.h`与`source/utils/INIInput.cpp`仅在检测到UTF-8 BOM时创建临时规范化视图，由原`INISettingCollection::ReadFromFile`读取，随后清理；无BOM文件保持原路径，三层优先级与全部设置分发不变。原始用户INI不删除、不重编码、不覆盖。读取失败时报告错误并遵循原有默认值回退。原生测试与新增绑定回归覆盖该契约。新日志的有效级别、独立开关与实际SWF状态可用于继续定位；若level=1、allowed=true、requested=true、enabled=true仍无图形，再查渲染路径。

## 当前设置修正

- `fMarkerNameScale=100`、`fMarkerDistanceScale=100` 位于 **`[Display]`**，与 MCM ID 和 C++ 注册/回调一致，不放在 `[QuestList]`。
- `[QuestList]` 的当前有效位置设置是 `fOffsetX=0` / `fOffsetY=0`；MCM ID 为 `fOffsetX:QuestList` / `fOffsetY:QuestList`，拖动会移动列表并继续跟随罗盘锚点。
- 当前滑块为 -100～100、步长 5；中英文 JSON、C++ clamp、AS2 clamp 与测试已同步，不能只改菜单显示范围的约束继续保留为回归原则。
- 最大高度设置已完整退出活动配置/运行时/API/测试链；旧 `fPositionX/fPositionY` 仍作为位置兼容键保留，与已退役的最大高度无关。
- 任务列表页使用 `topToBottom`，左侧“显示”标题固定 `position=0`，右侧“罗盘注视”标题固定 `position=1`；后续控件分别按列向下排列，保持原 ID、顺序和帮助文案。中英文使用相同的布局字段。
- `bRequireLookingAtCompass:QuestList` 默认开启：C++ 初始值为 `true`，MCM 默认 INI 和 SKSE 默认 INI 均为 `1`，双语帮助均注明开启。已有用户保存值优先于默认值，不应为了修改默认值直接覆盖或删除用户配置。
- MCM Helper 当前已有成功注册记录；历史加载失败仅保留在后续故障记录中，不再作为当前阻塞。

### 待完成清单
- [x] 偏移范围 -100～100：英文/中文配置、C++、AS2、测试统一修改。
- [x] 最大高度：移除 `fMaxHeight`/`maxHeight`/`SetMaxHeight` 的活动代码、默认配置与兼容行为测试。
- [x] 重新执行绑定校验、SWF 校验、DLL 构建与主包/CHS 打包。
- [x] 任务列表双栏及注视默认开启：双语位置、默认 INI 与 C++ 契约检查通过，9/9 回归及配置重打包完成。
- [ ] 部署新包后进行游戏内保存、重载、±100 边界和跟随验收。
- [ ] VR 中确认左右栏实际显示、已有关闭保存值的优先级，以及重新开启后注视门控生效。

## 修改、测试和打包

改文案时同步维护英文母本及 `tools/make_mcm_config_zhcn.py` 的翻译规则，再生成中文；不要只手改中文母本，否则下次生成会覆盖。

从项目根目录逐条执行，任一步非零退出就停止：

```powershell
python -X utf8 tools/make_mcm_config_zhcn.py
python -X utf8 tools/tests/test_mcm_bindings.py
# 仅配置修改且已有有效 DLL：
.\build.bat nobuild
python -X utf8 tools/verify_mcm_config_zhcn.py
```

完整校验器会比较已有 `build/package` 暂存配置与母本。因此修改母本后、重新打包前报“暂存副本不一致”是正常的过期产物提示，不能通过修改母本来迎合旧副本。`build.bat` 当前不自动运行 MCM 校验器，打包后需手动执行上述最后一步；C++ 有改动时应使用完整 `build.bat` 编译。

当前检查覆盖中英文 JSON 结构、翻译、占位符、29 个唯一 ID、INI 分组、数值帮助默认值、类型/范围、C++ 注册与变更回调，以及暂存配置一致性。9 项绑定回归测试还覆盖退役高度设置不存在、任务列表左右列分组和注视默认值；原有错分组、默认值不符、原生绑定缺失、越界值及重复 INI 键反例保留。

**静态校验通过不代表 MCM 已在游戏内注册。**上述工具不验证 DLL 加载、Papyrus 运行、所有 MCM Helper 版本的完整 schema 或 VR 中文字形显示。

## 菜单不显示：排查顺序

1. **检查最新启动日志**：在 Windows 文档目录（可能已重定向）的 `My Games/Skyrim VR/SKSE/` 查看 `sksevr.log`、`MCMHelper.log`、`CompassNavigationOverhaulVR.log`，先核对时间。
2. **检查依赖是否真正加载**：确认 MCMHelper.dll 和罗盘 DLL 成功加载。MO2 勾选模组/ESP 不等于其 DLL 加载成功。
3. **检查当前 MO2 配置**：确认主包、CHS、MCM Helper、SkyUI VR 及相应 ESP 的启用状态，并检查覆盖顺序和 overwrite。重点核对 `MCMHelper.dll`、`MCM_ConfigBase.pex`、`SKI_ConfigMenu.pex` 与菜单 JSON 的来源。
4. **检查生效配置**：验证实际安装的 JSON、modName、目录与 ESP 名匹配，而不只检查源码母本。若有条件，再逐字节比较安装文件和发布包。
5. DLL 成功加载后，完全退出并重新启动游戏，再检查菜单注册及中文显示。若仍缺失，再调查脚本/注册状态；不要先盲目重置菜单或清理存档。

### 2026-09-08 22:26 启动记录：历史故障，后续状态见下文

用户反馈罗盘模组的 MCM 菜单不显示。已完成只读日志、MO2 Default 配置及实际安装文件排查。

**已确认：**

- `sksevr.log` 记录 CompassNavigationOverhaulVR 加载成功。
- 同一日志记录 MCM Helper 加载失败：

```text
MCMHelper.dll ... disabled, fatal error occurred while loading plugin
```

- `MCMHelper.log` 仅有 `MCMHelper v1.6.3.0` 初始化行，没有提供进一步错误原因。
- Default 配置启用了 MCM Helper、SkyUI VR、罗盘 主包和 CHS；`MCMHelper.esp`、`Compass Navigation Overhaul VR.esp` 均启用。
- 已安装的中英文 JSON 均可解析，modName 正确，包含 3 个页面。
- 已检查的启用模组中，MCMHelper.dll 与 MCM_ConfigBase.pex 由 MCM Helper 提供；MCM Helper 与 SkyUI VR 都提供 SKI_ConfigMenu.pex，需要留意覆盖关系。

**待查及边界：**

- DLL 加载失败是菜单缺失的重要异常；日志不足以判定是版本兼容性、安装选项、依赖还是其他运行时原因。不能仅凭 `1.6.3.0` 断言该版本不支持 VR。
- 下一步核对实际安装包的 VR 支持、安装选项及依赖，修复后以新的 SKSE 日志确认成功加载。
- 尚未替换 Helper、重置菜单或修改存档；菜单恢复及中文实际显示尚未验收。

## 最近验证摘要

2026-09-08 的配置修复完成后：6/6 绑定回归通过，84 处文案检查、5 组选项、14 个格式字符串及全部 30 个 ID 检查通过；主包、CHS 包和默认 INI 的 ZIP 内容与母本一致。随后实机启动暴露 Helper 加载故障；其后已检查到成功注册日志，当前验收重点转向缩放效果。

## 后续状态：Helper 注册恢复，名称/距离缩放修复待验收
最新检查的 22:37 启动记录中，MCM Helper 已注册 98 个设置、2 个菜单配置和 Papyrus 函数，故不再沿用“Helper DLL 加载失败”作为当前阻塞。用户保存的 Display 名称/距离缩放值均为 300，插件日志也记录 INI 变更后的重载；未修改用户保存值。

已安装 DLL 与修复前构建 DLL、已安装 VR Compass 与修复前发布 SWF 的哈希一致。SWF 动画关键帧存在容器矩阵覆盖，现把缩放移至内部文字层，避免动画与任务列表继承缩放；行为测试和重打包通过。新资源尚未部署，菜单内调节后的实际游戏效果仍待确认。这次没有更换 Helper 或修改存档。

## 后续实机反馈：缩放仍无效，面板放大被裁切
用户截图显示详情文字被固定区域截断，不是已证实的文本高度不足。最新检查：面板保存为 235%，名称 265%、距离 270%；23:12 启动及后续 INI 重载记录存在。启用模组的 DLL 与上轮构建 DLL、VR Compass 与上轮发布 SWF 的哈希一致，排除该路径下未安装上轮 SWF。

因此此前文字层缩放方案不能标记为修复成功。增加低频诊断：原生 setter 的输入和调用成功状态、SWF 方法类型/保存值/实际缩放及文本矩形，以及列表内容在 HUD 根坐标系的边界。诊断需要配套 DLL 与 SWF；在设置应用、重载和既有限次锚点日志中输出，不每帧写日志。

下一步安装诊断包，重启并修改一次名称/距离后关闭菜单，检查 `[MarkerScale]`、`[QuestListLayout]`、`[QuestListAnchor]`。在取得数据前不改存档、不恢复 UV/网格补偿，也不把纹理取样裁切猜测写成已确定根因。

## 缩放上限调整
名称、距离、任务列表面板的 MCM 上限由 300% 调整为 200%，下限 25%、默认 100% 不变。英文和中文配置、原生设置钳制、名称/距离与面板 SWF 限制同步更新；旧兼容整体缩放设置也采用 200% 原生上限。保存值不回写：旧 INI 中超过 200% 的值在运行时按 200% 使用。此调整不等同于已修复缩放无效或区域裁切，诊断仍保留。

## 面板 110% 与名称/距离实例绑定修正
用户选择将面板上限降至 110%，仅调整 QuestList；名称/距离仍可在 25% 至 200% 独立调节。旧保存值仍不回写。110% 来自当前任务边界估算，不保证任意长度的任务内容都能容纳。

运行时日志：原生传入 200 且 invoked=true，AS 方法类型为 function，但实例 NameScale/DistanceScale 为 undefined，实际文字缩放均为 100。修正 CompassMarkerInfo 方法内成员为显式 this 引用、静态常量使用类限定名；测试不再自动将隐式引用改为 this。此方案针对作用域问题，是否完全解决需实机确认；目标分隔装饰差异仍未解决，本轮不改其图形。

本轮还补齐 HUD 补丁加载完成后的名称/距离设置同步：原先启动流程只同步单位，缩放仅在 INI 重载时应用。显式引用类的反编译测试与 11 项布局测试通过，旧隐式引用类被新测试拒绝；DLL 构建及三份 SWF 校验通过。2026-09-08 23:51 已更新现有主包/汉化目录，14 个文件哈希一致，备份在 _patch_work/compass-deploy-20260908-235159，未更改保存设置和 Git 暂存区。仍需重启游戏验证。

## 2026-09-09 名称/距离上限 150% 与海拔箭头
用户已确认此前黑区来自任务/地点名称放大后的下半部分跨到顶部显示。撤回装饰素材描边及背景定义试验，恢复原始素材，不将这些试验当作根因修复。

名称和距离的 MCM 最大值、C++ 设置回调及 AS2 setter 同步限制为 150%（最小 25%、默认 100%）；面板期望上限保持 110%。不回写用户已保存值，超过范围的值在运行时限制。名称菜单改为“任务/地点名称大小”（Quest/Location Name Size），距离帮助注明同时控制海拔上下图标。

原脚本已引用 DistanceScale，但把箭头素材约 35% 的初始矩阵比例直接覆盖，导致异常放大。现缓存每个箭头实例的基础 X/Y 比例，乘以距离百分比，不累计缩放；名称更新不改变箭头大小，箭头定位仍跟随距离文本末端。没有修改海拔阈值或方向判断。

反编译行为测试覆盖名称独立性、距离 25/50/150%、超范围和无效值、连续帧更新及 Above/Below 两种状态；MCM 6 项绑定测试、完整双语/暂存配置检查、SWF 哈希、DLL 编译及主包/CHS 打包通过。MO2 主包和 CHS 的 7 个更新文件已备份部署且哈希一致。未修改用户设置、存档或 Git 暂存区。VR 视觉效果及 150% 是否完全避开采样边界仍待实机验收。

## 距离缩放偏移修复
用户反馈距离缩放后不居中。原代码仅修改距离文字 _xscale/_yscale，autoSize="center" 不能为显式缩放固定中心。现缓存初始距离中心，按文字+可见箭头+间隔的总宽度居中；箭头隐藏时仅居中文字。使用箭头实际 bounds 补偿非零注册点；更新距离时先选择上下状态/可见性，再计算布局。

反编译模拟覆盖米/英尺、3 种距离长度、上/下/隐藏状态及 5 次缩放顺序，共 90 组组合，并检查每组连续 10 帧不漂移。构建、哈希和主包/CHS 打包通过；两份 Compass.swf 已备份部署 MO2 主包，哈希一致。沿用上一轮 DLL/配置，150% 上限与名称缩放独立性保持；VR 实机效果待验收。

## 旧 Passenger 调试笔记

# QuestList Passenger 模式调试记录

## 背景

目标：在不扩展 Palm Compass、不修改 Compass HUD 图集结构的情况下，让 QuestList 作为 Compass 当前 UV 区域中的乘客显示。

当前设计原则：

- QuestList 不创建 dedicated VR panel。
- QuestList 不申请新的 HUD 纹理区域。
- Debug 只能观察布局，不能改变 QuestList 显示状态。
- Compass 原有采样区域保持不变。

---

## 坐标系统

旧方案问题：

```
QuestList
  -> root space
  -> HUD transform
```

导致 Debug 框和实际内容不重合。

新方案：

```
QuestList
  -> Passenger Layout Space
  -> Compass local transform
```

所有 Debug 几何必须使用 Passenger Layout Space。

禁止：

```
globalToLocal(_root)
```

作为 QuestList 主布局参考。

---

## Debug 层规则

Debug 只能绘制：

- 边界线
- 标签文字
- 参考线

禁止绘制：

- ClipMask 填充面
- ViewportMask 填充面
- Placeholder panel
- 任何影响 HUD 采样的 MovieClip

Mask 关系：

```
Mask
 |
 +-- 参与裁剪
 |
 +-- 不可见
```

---

## 当前已发现问题

### 1. Debug 白色面片

表现：

- VR 中出现白色弧形区域。

原因：

- Debug mask 使用 beginFill。
- Clip geometry 被错误当作可见绘制。

修复方向：

- 移除 beginFill。
- ClipMask `_visible=false`。
- Debug 只保留线框。

---

### 2. QuestList 尺寸异常

表现：

- QuestList 内容缩小。

可能原因：

```
Embed scale
    +
Layout fit scale
    +
Passenger scale
```

产生重复缩放。

正确方案：

```
位置 -> Compass transform
尺寸 -> 单次 FitLayout
```

不能同时叠加多个 scale。

---

## 后续修复顺序

1. 清理 Debug 可见填充。
2. 编译 SWF 验证 Debug 不产生白块。
3. 检查 QuestList 实际 passenger bounds。
4. 移除重复 scale。
5. 重新验证 Compass UV 区域。

---

## 不应再修改的部分

- Palm Compass 本体。
- Compass 原始 UV atlas。
- dedicated panel 路径。

除非确认 Passenger 方案不可行，否则保持当前架构。
