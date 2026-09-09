<!-- 定位：L2 QuestList 当前行为、构建与验收边界。 -->

# QuestList：当前实现与验证

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

### 可视化布局调试
现有MCM「调试 → 日志级别」选择Debug(1)或Trace(0)即启用红框，Info(2)及以上关闭。额外的`[Debug] bShowQuestListLayout=1`默认允许显示，改为0可在保持详细日志时单独禁用叠加层；该独立项只在INI中，不新增MCM控件。调试开关随设置重新应用，普通渲染路径在关闭时不创建调试MovieClip。

**最新配置读取修复（16:15部署）：**16:03–16:05新日志确认原生同步路径已执行、SWF方法存在，但`requested=false`。用户保存INI实际以`EF BB BF`（UTF-8 BOM）开头，首节为`[Debug]`；同一Windows配置读取API复现了该节的`uLogLevel`缺失，而后续`[QuestList]`可以读取。由于两个发布默认INI均为Info(2)，首节被忽略会使保存的Debug(1)无法覆盖默认值。现由`utils::INIInput`在检测到BOM时提供临时去BOM读取视图，继续使用原有游戏INI解析和三层优先级；读取结束自动删除临时文件，绝不修改用户INI。仅修复输入兼容，不改HUD、遮罩、原始素材或调试门控。新日志记录`[Settings] effective logLevel=... layoutDebugAllowed=...`及`[QuestListDebug] level=... allowed=... requested=... method=... state=...`。正常Debug应为level=1、allowed=true、requested=true、method=true、enabled=true。安装校验已通过，仍需新启动的VR实机确认。

原生回归使用真实Win32配置API复现BOM首节缺失，再验证临时视图恢复读取、后续节不变、无BOM透传、空输入和源文件/临时文件清理，共4/4项；另有MCM11/11、模块10/10、布局47/47、包装器3/3、罗盘回归、双语及13/13主包和CHS完整性检查。完整`build.bat`重编DLL，16:15增量部署备份为`_patch_work/compass-deploy-20260909-161510`，27项受保护文件哈希不变。

**最新原生启动修复（15:57部署）：**通过Windows实际重定向的文档目录取得15:47–15:51的SKSEVR日志，确认嵌入式QuestList已初始化、任务可见且MCM保存Debug(1)，但实际快照反复为`layoutDebug=false; enabled=false; overlay=false`。根因是`InfinityUI.cpp`的Compass嵌入式初始化分支只同步位置与缩放，没有调用SetLayoutDebug；旧的独立QuestItemList补丁分支才调用，正常VR嵌入路径不会经过该分支。现将首次嵌入、兼容补丁和INI热重载统一交给`CNO::UI::ApplyQuestListSettings`，同步位置、缩放、调试开关并读取实际状态。新增`[QuestListDebug] requested=... method=... state=...`日志，可直接区分设置请求、SWF方法存在性与真实启用状态。启动时不再依赖用户再次修改菜单来补同步。

本轮完整重编并链接DLL，MCM10/10、模块10/10、布局47/47、包装器3/3、罗盘回归、双语及主包13/CHS1完整性通过。仅DLL与前次构建不同，SWF和原始素材哈希不变；增量部署备份为`_patch_work/compass-deploy-20260909-155751`，全部13项主包与ZIP一致，27项保留文件未变。安装成功不等于新版本VR渲染已验收；下一步先确认新日志的enabled=true，再检查画面，不再把旧版未启用误判为UV裁切。

2026-09-09实机反馈红框仍不可见后，核对发现已安装SWF/DLL与当时发布包一致，MO2覆盖目录的MCM保存值为`uLogLevel=1`，独立开关为1；没有取得对应启动日志，因此不能断言运行时设置已成功应用。代码中确认旧叠加层会因父级、罗盘透明度、空列表或缺少锚点而自我隐藏，导致无法诊断这些状态。现改为开启时立即创建并显示根级诊断，普通HUD隐藏时仍显示摘要及已有几何，并明确报告隐藏原因；不改变真实任务列表可见性。新增`GetLayoutDebugVisibility`和`GetLayoutDebugState`，后者包含enabled、overlay、overlayVisible、entries、hudVisible、reason、root和parent，并附入按需`GetLayoutSnapshot`日志。关闭Info或独立开关后仍清理调试显示。若没有任务行，应至少看到独立摘要；若完全没有摘要，优先排查设置分发、实例初始化、实际加载SWF及VR画面映射。

本轮新增空列表、无锚点、隐藏父级/罗盘及原布局不变回归，47/47布局、10/10模块、3/3包装器、MCM10/10通过。仅重编AS2和两份嵌入式Compass，沿用此前已完整编译的DLL；三项SWF哈希和主包13文件/CHS1文件校验通过。15:41增量部署两份SWF，保留用户配置与MO2优先级，安装前后哈希一致性已核对；实机红框、字体和VR坐标映射仍未验收。

叠加层在`_root`中作为独立兄弟节点绘制，不属于QuestItemList的viewportMask，也不属于DetailBox的Body遮罩。红框表示外层Box、Body、正文、目标分隔区及目标行，橙色表示原版Header/Bracket/EndPiece，青色表示Body遮罩和安全限制线；隐藏行采用虚线，即使内容被正常省略也能观察其原始布局位置。原始装饰、文字、目标顺序和动画均不因调试绘制而修改。

每个区域标注`R (x,y) w x h`（根坐标轴对齐包围盒）和`L w x h`（区域局部逻辑尺寸）。矩形边线由原本地四角转换而成，保留父级旋转/缩放，不把全局Y当作根坐标Y。摘要包括Stage尺寸、请求/生效缩放、完整/可见底边、真实安全限制、目标显示数量及`fitReason/omissionReason`；红线是保守安全底边，青线是内容/省略限制，不代表VR物理屏幕边缘。调试最多展示8项任务、每项24个目标行，避免极端列表无限生成标签；所有真实目标仍保留在布局数据中。文字与框按几何变化刷新，关闭和卸载时清理，不按每帧写日志。

此功能用于取得实际VR运行数据，不能把模拟测试或截图中的空白当作已经测得的UV安全范围。验收应比较红线、完整Box底边、隐藏目标和物理画面位置，再决定是否需要调整安全区策略。


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



