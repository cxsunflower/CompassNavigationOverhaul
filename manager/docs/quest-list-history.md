<!-- 定位：L2 历史档案，保留旧实验和回退原因，不是当前指令。 -->

# QuestList 历史记录

> 本页保留此前实现、排查与回退记录（最早在前），不是当前操作指南。
> 最新行为、构建步骤和验收状态见 [QuestList 当前说明](quest-list.md)。历史中的“已部署”“当前”等仅指当时状态；撤回的 Palm UV/网格补偿不得恢复。

以下按时间顺序记录 QuestList 的实现变更（最早在前）。凡标注"仍需实机 / VR 验收"的结论，以进游戏验收为准。

### 2026-09-07 定位与详情修复

- 实际旧 SWF 的 `AddQuest` / `SetQuestInfo` 只有 5 个参数，而 DLL 已传 6 个参数；新增 description 导致后续目标数组和 ageIndex 错位。现两层接口统一为 type、title、description、isInSameLocation、objectives、ageIndex。
- 列表跟随聚焦文本下方：先在文本框父级中计算底部中心，再经 localToGlobal/globalToLocal 转换到列表父级；通过实际 getBounds 修正美术资源注册点偏移，支持 VR 父级缩放。
- 动态详情文本继承标题字体、颜色、嵌入字体设置，长文本高度限制为 60；无日志描述（包括杂项任务）时跳过详情，继续显示目标。
- 同一任务、同一标记的多个目标使用 try_emplace 累积，避免每次匹配覆盖已有目标。
- 保留 VR 的空 AddToHudElements；onEnterFrame 仅更新罗盘锚点，不访问 HUDMenu 的 HudElements。

### 2026-09-08 回退布局

按用户要求撤回两栏布局，恢复任务名称、详情、目标从上到下排列，保留先前定位和详情接口修复。源码、SWF、安装包及 MO2 当前启用版本同步回退。

### 2026-09-08 随罗盘移动

QuestList 每个界面帧以 Compass.FocusedMarkerInfo.Target.TextFieldInstance 的底部中心为锚点，保留 6 单位间距，经父级坐标转换后居中放置。原生 AnchorBelow 绑定锚点，UpdateLayout 不再恢复固定屏幕坐标。每帧重新获取文本框，适应罗盘移动和文本框重建；仅测量当前有效条目，避免退出动画影响位置。纵向内容布局不变。

验证：DLL 编译、SWF 反编译接口检查、定位脚本模拟（嵌套缩放、移动、文本宽度变化、无漂移及空列表）、MO2 部署哈希均通过。模拟不代替 VR 实机验证。

### 2026-09-08 手掌罗盘实机反馈后的调整

截图显示同级列表仍与手掌罗盘分离。改将 HUDMenu 和 VR_HMD_info 的 QuestItemList 及其美术资源注入 CompassShoutMeterHolder\Compass 内，C++ 路径与 AS 锚点路径同步更新。旧同级注入文件已移到备份，避免重复列表。Palm Compass 移动场景节点，之前的纯二维坐标模拟不足以验证 VR 挂接。

按最新要求保留装饰，仅杂项类型（6）显示标题；其他任务不显示任务名。正文优先显示日志详情，没有日志说明时显示目标文本。定位边界包含保留的装饰。DLL 构建、SWF 接口校验及部署哈希已通过，新挂接层级和手掌下方显示仍需实机验收。

### 2026-09-08 02:27 实机反馈后继续修复

InfinityUI 日志确认 Compass.QuestItemList 已加载，但截图仍在上方，之前关于挂到 Compass 即能解决问题的判断未获实机支持。进一步移至 Compass.FocusedMarkerInfo.Target.QuestItemList，与罗盘任务文字共享父级，直接使用文字的局部底部中心定位，去除锚点全局转换及对 TextField._parent 的依赖。位置采用绝对赋值。新增 GetAnchorState 和原生前三次定位日志 [QuestListAnchor]。标题、装饰和详情行为保持不变。编译、SWF 校验、局部坐标模拟及部署校验通过，实机位置仍待验收。

### 2026-09-08 独立影片加载边界排查

02:54 日志确认 SetAnchor 已执行、父级为 Target，局部坐标已在文字下方，但用户报告实机仍偏移且不跟随。因此仅调整层级/二维坐标不足。检查 InfinityUI 源码可见每个补丁通过 CreateEmptyMovieClip + loadMovie 独立加载；当前假设是该加载边界与 VR 渲染相关，尚未实机证实。

改为将 QuestItemList 主时间轴封装成 Compass 内部的 DefineSprite 511，静态放入 Target（sprite 133），QuestItem 等资源 ID 加 500 重映射；保持原 Compass 的脚本和美术资源，移动 QuestItemListArt 到 Compass 的资源目录。不再部署任何独立 QuestItemList.swf 注入文件。原生在 Compass 补丁完成时初始化内嵌列表，日志记录 Embedded Compass sprite initialized 或 missing。

构建先运行 build_questlist_swf.py 得到 swf/QuestItemList.swf，再运行 embed_questlist_compass.py 合并到两份 Compass.swf。tools/Compass.before-embedded.swf 是合并前基底；修改原罗盘时必须同步更新基底。打包校验两组哈希。已完成编译、XML 往返、脚本反编译和部署/ZIP 校验；仍需 VR 实机确认跟随。保留杂项标题、装饰、日志详情及空日志时的目标回退。

### 2026-09-08 12:08 Palm 兼容：HUD 贴图取样范围

运行日志确认内嵌列表初始化及局部定位正常，但截图仍固定在上方，独立 SWF 加载边界的猜测被实机结果否定。继续检查原版 Skyrim_VR - Main.bsa 的两块 HUD 网格：罗盘 BSTriShape（60 顶点、56 三角形）只采样 U=0.334716796875..0.70703125、V=0.5400390625..0.7275390625。HUD 舞台为 1024×1024；罗盘区域的下边界约 y=745。QuestList 超出该区域会落到固定 skyvr_hmd_info.nif 对应的贴图区，而 Palm 源码和运行日志证明它只移动 skyVR_HMD_Compass.nif 场景节点。Flash 父子层级不能改变网格 UV 分区。

不能直接扩大罗盘 UV 区域：原版 SubtitleTextHolder 的文字区域位于其下方，会把字幕带到手上。最终方案保留原 UV 和三角拓扑，将 Compass、ShoutMeterInstance、ShoutWarningInstance 的 Flash y 上移 80 像素；对罗盘网格顶点按同一 UV 位移补偿，维持罗盘本体在手掌上的位置。固定 HUD 网格不改。列表按实际全局边界限制在 x=344.75..722、y≤743 的安全区，必要时等比缩小并横向收拢，保持位于任务文字下方。

配套产物：DLL + 两份 Compass.swf + meshes/skyvr_hmd_compass.nif，必须一起更新。网格由 tools/build_vr_hud_meshes.py 根据原版模板生成；支持 --check 并纳入 build.bat。检查通过：27 组真实定位脚本模拟、NIF 读写/UV/拓扑/补偿检查、编译、打包与部署哈希。实际视觉位置和字体大小仍需 VR 验收。

此前研究过扩展两块网格，但检测到字幕区域冲突后未部署该方案；assets 与安装包不含 skyvr_hmd_info.nif。

### 当前状态：已撤回 Palm 贴图重排方案

按用户最新要求撤回 80px 贴图重排、网格补偿及列表区域自适应缩放，接受列表在罗盘上方的原显示方式。保留杂项标题、装饰、详情说明。源码和构建检查同步撤回，网格生成脚本及中间输入归档至 build；MO2 的 skyvr_hmd_compass.nif 覆盖移至备份，恢复使用原游戏网格。DLL 和两份 Compass.swf 已恢复为 CNO-Palm-Atlas-20260908-131300 备份，安装包校验逐字节一致，且不包含 NIF 网格文件。

### 2026-09-08 正文占满装饰宽度

正文原先复用标题文本框宽度（仅装饰中间的标题槽）和右对齐格式，导致右侧留白及提前换行。现以 Bracket、EndPiece 与标题框的联合左右边界设置正文区域，两侧内缩 4 单位，左对齐并自动换行。保留当前位置、杂项标题、装饰和详情回退规则；不重新启用网格补偿。SWF 重编译、嵌入、打包及 MO2 部署校验通过。

### 2026-09-08 正文可读性

正文改为白色粗体，并通过黑色 GlowFilter 外发光形成字形描边（alpha=1、blurX/Y=4、strength=4、quality=2）。保留整宽左对齐、字号、位置及装饰。编译并反编译确认粗体、白色和描边设置已写入 SWF，部署哈希通过；VR 字体粗体替代和实际描边显示仍需实机确认。

正文再次加重：粗体基础上增加 1.5 单位白色字形扩边（strength=3），黑色描边扩大到 6 单位（strength=6）；字号和布局不变。已编译、打包并校验部署。

### 2026-09-08 当前实现：详情、Objectives 与真实素材

前面的加重记录属于历史版本。按最新反馈，正文已撤回白色扩边，黑色 GlowFilter 使用 `0x000000, 1, 3, 3, 3, 2, false, false`；标题装饰及分割线保留 `4/4/4` 黑色描边。字号、正文宽度与已撤回的 Palm 方案均不变。

当前内容结构为原有标题装饰（仅杂项显示标题）、独立日志详情、`OBJECTIVES` 分割区以及逐条任务目标。日志详情不再以目标文字作回退，两种内容可同时显示。没有目标时不显示空分割区；没有日志详情时，目标区仍可显示。长文字按实际换行高度测量，不再用固定 120 高度截断详情；高度限制按完整段落/行控制，避免半行裁切。`GetContentBounds` 使用稳定内容矩形，`SyncQuests` 通过任务键及内容签名更新目标状态，不必每帧重建相同内容。

C++ 的 `CollectQuestObjectives` 从玩家任务目标列表按 owner、instance 和 objective index 收集目标，保留已显示、已完成和失败状态，去重并按目标顺序排列。GFx 传递的每条数据包含 `text`、`completed`、`failed`。未完成使用空心菱形，已完成使用实心菱形，失败使用低透明度空心菱形；完成/失败文字为灰色，普通目标保持白色粗体及细黑描边。原六参数接口不变。

#### 第 3 步：正式素材导入

三份用户 PNG 的来源哈希、矢量化 SVG 和映射记录位于 `tools/questlist-art/README.md`。导入的是基于原图轮廓和颜色的原生 SWF 矢量资源，不是运行时加载 PNG，也不是上一阶段的临时几何图形。`Journal Basic.png` 对应 `QuestObjectivesDivider`，`Quest Active Hover.png` 对应 `QuestObjectiveCompleted`，`Quest.png` 对应 `QuestObjectivePending`。分割线中央留空，由文本框显示可本地化的 `OBJECTIVES` 标签；资源缺失时保留临时绘制回退。

`tools/build_questlist_swf.py` 每次从 `tools/QuestItemList.HUDMenu-original.swf` 构造带真实素材的基底，再导入 ActionScript，不会反复往上一次生成的 SWF 中追加资源。构建清单覆盖原始基底、矢量源、导入脚本、AS 源码和输出 SWF。独立电影使用形状 ID 300–302、Sprite ID 303–305；嵌入 Compass 时整体加 500，变为 800–805，原有 QuestList 容器仍是 Sprite 511。嵌入前检查 ID 冲突，转换后验证真实资源及链接名。

```powershell
$ff = '完整路径\ffdec-cli.jar'
python tools/build_questlist_swf.py --ffdec $ff
python tools/build_questlist_swf.py --check
python tools/embed_questlist_compass.py --ffdec $ff --output build/compass-step3-preflight.swf
```

第 3 步验证范围：独立 SWF 的脚本/非脚本标签检查、真实图形导出、六个资源定义与三组 linkage、嵌入预检的 ID 映射，以及反编译 AS2 的布局/状态模拟。该阶段不代表 DLL 已重新编译、发布包已更新或 VR 实机效果已验收。正式两份 Compass、DLL、主包/CHS 覆盖包及部署留待第 4 步统一处理；不要单独部署中间 QuestItemList.swf，也不要恢复已撤回的 UV/网格补偿方案。

### 中文方框字与目标标签修复

当前启用字体包 Font-LXGWWenKaiMono 的 EverywhereMediumFont 等别名均映射 Normal。通过 GetReadableTextFormat 明确指定 $EverywhereMediumFont、Normal（bold/italic=false）及有效字号，避免空标题返回不完整字体格式以及请求不存在的粗体字形；保留用户当前描边参数。分隔标题明确显示中文“目标”，不依赖 OBJECTIVES 翻译键。8 项反编译脚本布局/状态测试通过，包含空标题字体格式回归场景。已编译、打包并部署两份 Compass.swf；实际字形显示仍需重启游戏确认。

### 目标标题宽度自适应

使用当前翻译表已有的 $OBJECTIVES（当前汉化表映射为“目标”），不再立即用硬编码文本覆盖翻译结果。根据 textWidth 居中设置标签宽度，加 10 单位间距；原分隔图形用两个带遮罩的副本分别显示左右侧，按剩余宽度等长排布。通常保持字号，超长翻译才适当缩小。保留 Normal 字体映射及当前描边参数。9 项反编译布局/状态测试通过，涵盖中文、OBJECTIVES、超长标题、居中、左右对称及不重叠。已重编译、打包并更新 MO2 两份 Compass.swf。

### 目标装饰加厚与进行中目标优先

目标分隔图形高度提高约 30%（最低 16），加 1.5 单位灰色扩边；外层黑色描边与任务标题装饰一致（blur/strength=4），不改文字粗细。显示前按进行中、已完成、已失败排序，并使用原始索引保持同状态内顺序，状态变化后重新排序。10 项反编译布局/状态测试通过，包括交错状态输入、状态更新、同组稳定性及装饰描边一致性。已打包并部署两份 Compass.swf。

目标分隔装饰按用户纠正仅加强黑色外描边（blurX/Y 和 strength 从 4 改为 6），不改源图灰色、不提亮文字；保留原有宽度自适应与状态排序。10 项回归测试及部署校验通过。

### 2026-09-08 目标状态图标显眼度提升

实机截图显示目标旁菱形装饰在复杂背景上几乎看不见：此前图标 12×18 经 65% 缩放后仅约 8×12 像素，且是唯一没有黑色 Glow 的元素。现统一放大到 18×27（图标列 x=2..20，行文字 x=26 起，不重叠），并加上与标题装饰同款的黑色 GlowFilter(0x000000,1,4,4,4,2)；原画风灰色不动，失败态保持 50% 透明度。链接素材与 fallback 绘制走同一套尺寸与滤镜，布局回归测试新增对应断言。已重建验证：build_questlist_swf → embed → 双 --check → 10/10 布局回归测试 → build.bat nobuild（主包/CHS 包）；待 MO2 部署与 VR 实机验收。

### 2026-09-08 罗盘注视门控

任务列表新增罗盘注视门控：任务标记 yaw 聚焦之外，另要求罗盘可见（GFx _visible/_alpha 与 skyVR_HUD01 节点可见性三者 OR）且 3D 视线看向罗盘，三者同时成立 0.3 秒后弹出，任一丢失立即隐藏；Palm Compass VR 手掌放下（罗盘隐藏）时不再弹出。注视检测三档经 MCM 热切：2=罗盘节点世界坐标视线夹角（显示 15°/保持 25°，默认），1=右手节点，0=俯角兜底（显示 18°/保持 10°，bCompassOnPalm=0 时改为抬头判定）；节点缺失自动降级并记 warn，读档或 3D 重建后缓存经场景根比对失效重找。相机前向量由 cameraRoot 旋转矩阵 12 候选轴与已验证 yaw 自校准（含 15°/5° 残差门），日志 [QuestListGaze] 以 2Hz 打门控读数（Debug 级别）。新增 9 个 [QuestList] 设置（总数 18→27），MCM 中英配置与校验脚本同步。DLL 一次编译通过（无新增警告），主包/CHS 包已出；Palm 手势显隐、注视角度读数与三态图标仍待 MO2 部署后 VR 实机验收。

### 2026-09-08 罗盘文字分开缩放与列表面板缩放

罗盘聚焦文字拆分为任务名称与距离两个独立缩放（MCM 各 25–300%，默认 100%）：CompassMarkerInfo 新增 SetNameScale/SetDistanceScale 分缩 Target/Distance 子 clip（高度箭头随距离走），Compass.as 新增同名转调，C++ 经 ApplyAllSettings 应用；旧整体缩放 fMarkerTextScale 废弃（保留解析，不再生效）。任务列表 fTextScale 进 MCM（显示名"面板缩放"，25–300%）：条目文字与图标整体缩放，锚点自动跟随，最大高度不变。构建：新增 tools/build_compass_swf.py（ffdec importScript，其 --check 接入 build.bat），罗盘基底改走源码→二进制单向链路；此次重编顺带发货了此前滞留源码的两处改动（SetMarkerTextScale/SetTextScale、上游 unknown 标记 gotoAndStop(3)），并修复源码里除 100 会把文字缩到 1% 的 bug（旧二进制从未编入，无实际影响）。MCM id 27→30，中英配置与校验同步。反编译回归：新接口存在性、转调与旧基底三语句（gfxExtensions、HeightIndicator 默认帧、stop）保留断言通过；名称/距离独立缩放效果、"?" 标记帧与面板缩放待 VR 实机验收。

### 2026-09-08 已完成目标倒序与黑色描边加强

已完成组改按原始目标序号倒序，进行中仍优先，失败组保持原序。注意：原生快照不含完成时间戳，倒序反映任务流程序号，不能精确恢复非线性完成历史。目标分隔装饰黑色 Glow 的 blurX/Y、strength 从 6 增至 8，状态菱形从 4 增至 6；文字、灰色源图、尺寸及标题装饰保持不变。新增倒序、重复刷新、输入不变及空/单目标回归断言。

验证：JPEXS 重编译及嵌入 HUDMenu / VR_HMD_info 两份 Compass 成功；11/11 反编译脚本布局与状态测试通过；源码及嵌入哈希检查通过。build.bat nobuild 已更新 主包与 CHS 包，沿用现有 DLL（本次未改 C++）。主包内两份 Compass 与 assets 逐字节一致，无独立 QuestItemList.swf。尚未部署到 MO2，VR 视觉效果待实机验收。

### 菱形图标保持原描边

按用户纠正撤回本次菱形图标描边加强，恢复黑色 GlowFilter 的 blurX/Y、strength 为 4；保留原尺寸 18×27，不改变源图。目标分隔装饰仍为 8，已完成目标倒序不变。


