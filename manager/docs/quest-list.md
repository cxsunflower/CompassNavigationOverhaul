<!-- 定位：L2 当前 QuestList 行为、源码职责、构建链及验收限制，不混入旧部署指引。 -->

# QuestList 当前实现

当前源码包含紧凑三点、省略停止、Q/F/V线段显示带限制和热路径优化；本轮获准分组提交。本轮提交前只读核对：两份安装Compass、中英文MCM及两份默认INI与当前源输入一致，打包目录的对应文件也一致。此前发现过来源未确认的外部更新；本轮仅冻结当前文件，不把一致性冒充由本轮执行的部署或游戏加载证明。 剩余问题与历史证据见[当前索引](../CONTEXT.md)和[S1记录](../stages/s1-questlist.md)。

## 当前紧凑省略规则
2026-09-13紧凑省略标记修订（本轮仅整理提交，不执行打包部署）：省略标记改为三个纯矢量点，不再用整行TextField测量。每点3×3白芯加1单位黑边，整体可见边界23×5；不加Glow／阴影滤镜，没有字体行高或额外上下间距。随条目缩放后，高度为5×0.65×实际面板比例，90%／100%／110%时分别2.925／3.25／3.575个SWF逻辑单位，不等于VR屏幕像素。空图标槽仅保留横向对齐，无独立高度。

旧实现只核对名义行高，现额外核对文字／图标四角边界；任意条目发生子元素越界就整行替换，后续不再显示。恢复内容后解除截断。新边界、任意序号、文字／图标微小横向和底部越界、多任务停止及恢复的反例均已加入最终SWF回归。

此前“先预留文本行再省略”的演进及测试数字统一保留在[S1阶段记录](../stages/s1-questlist.md)，不作为当前标记尺寸说明。

## 显示路径与迁移边界
QuestList 静态嵌入 `Compass.FocusedMarkerInfo.Target.QuestItemList`，继续跟随罗盘。掌上独立面板目前是另一条静态测试路径，不替换此实现，不修改第三方 Palm。禁止恢复已撤回的 UV／网格补偿，也禁止独立部署 QuestItemList.swf。

## 内容与排序
- 内容为原标题装饰、日志详情、目标分隔装饰和目标；仅杂项任务显示任务名，空区不占正文高度。
- `SyncQuests` 按任务键／内容签名更新，避免未变化内容反复重建与重启动画。
- 进行中目标在前、已完成组按原目标序号倒序、失败组在后。**没有完成时间戳，尚不能保证“更早完成的目标始终在底部”**；这是已有需求缺口，不是本次 Debug 修复范围。

## 字体、装饰与布局
- 正文使用 `$EverywhereMediumFont`，Normal、非斜体；目标文字按状态区分明暗。
- 详情正文、目标文字及“目标”标签统一为名称／距离同款黑色 DropShadow：距离 2、角度 45°、不透明度 1、模糊 2×2、强度 1.5、质量 2，inner／knockout／hideObject 均关闭。替换旧文字 Glow，不叠加；不更改字体、字号、字距、颜色、对齐、换行或布局。图标仍用原 4/4/4 Glow；原上方标题字段和装饰不采用这套正文滤镜；省略标记使用独立的无滤镜矢量点。
- 文字阴影已重编译并通过反编译回归，已部署；本轮按授权提交累计改动；不同缩放和复杂背景下的可读性仍待 VR 验收。
- 层级为 `QuestItem → DetailBox → Header + DetailBody + DetailContentMask`。Header 保留原 Title 引用；Body 放生成内容；局部遮罩只保护 Body。
- 原装饰决定自然内容宽度，逻辑 Box 尺寸由排版函数拥有，不从未裁切素材或 Debug 绘制反向测量。
- **当前顺序是自然宽度 → 必要时缩小面板 → 完整段／行省略**。不再使用历史的“先扩宽正文”方案，不能把文字扩到固定装饰之外。
- 省略标记视觉为`. . .`，由三个小点直接绘制，可见边界23×5（含黑边），不使用字体文本框或模糊滤镜；垂直只占实际绘制高度，空图标槽只保留横向对齐。第一条不能完整容纳的目标整条隐藏，标记放在其原起始Y和文字列X，不添加4单位间距；后续目标及后续任务条目隐藏。文字、图标实际子边界与逻辑行边界联合检查，并保留安全余量。若标记本身仍放不下，不越界、不挤掉最后一个完整目标。
- 目标图标与分隔装饰改用任务日志原始矢量；独立 `QuestItemListSkin.swf` 只含图形，不运行日志页面。**菱形不额外加粗**，保留 4/4/4 滤镜及 18×27 槽位；失败目标使用原生日志叉号，保持原比例与颜色。上方任务详情装饰字节不变。[皮肤接口与素材来源](../../assets/source/questlist/art/README.md)。
- 皮肤适配包可覆盖 HUDMenu／VR_HMD_info 两个 `!assets/QuestItemListSkin.swf`，无需改 DLL 或布局；普通日志美化包不会自动同步，须提供符合固定导出名和画布尺寸的适配。

## 显示、定位与缩放
- 修订前的历史实机日志：Palm 在 PlayerWorldNode 下找到 compass NIF，而 CNO 的 42 次采样全为 mode=2/0，说明原 camera/player 三根不覆盖实际 VR HUD。新增 VR_NODE_DATA 场景根搜索、路径核验、去重／歧义拒绝、当前根祖先链校验和独立实时时钟重试；右手回退优先读取 NPCRHnd，测距原点取跟踪 HmdNode。不开启可见性要求时，仍允许既有注视模式回退。
- 前次可见性修复（已部署，但实机发现未找到 VR 节点，未解决）：已找到的罗盘节点或任何祖先 `kHidden`／`AppCulled` 为隐藏时，Flash `_visible=true`／非零 alpha 不能推翻；Flash 明确不可见或 alpha≤1 同样否决。最新修复（已部署，待实机验收）改为：VR 必须找到经过 compass NIF 路径核验的唯一节点；找不到或候选不唯一时，可见性门控不通过，不再用 Flash 猜测。非 VR 保留 Flash 回退。
- “要求注视罗盘”与“要求罗盘可见”独立：关闭注视要求仍遵守已开启的可见性要求。保存设置、角度／距离阈值、滞回和武器拔出门控不改；3D 测距原点改读跟踪 HmdNode。
- MCM“拔出武器时隐藏”按游戏报告的 `IsWeaponDrawn()` 状态门控，不判断是否处于战斗；旧键 `bHideInCombat:QuestList` 保留以兼容已有设置。武器仍装备不等于武器已拔出；CommonLib 将已拔出、准备收刀和收刀中都视为 true。
- 当前名称／距离设置范围 25～150%；面板期望范围 25～110%，自动缩小下限为 `min(90,期望值)`。实际默认值以发布 INI 为准。
- 横向偏移 X 为 -200～200、步长5、默认0（本轮仅只读核对安装，未执行部署）；Y偏移设置已退役，固定垂直布局与跟随罗盘保留。最大高度设置已退役；旧整体文字缩放键保留解析但不应用。
- Passenger 布局使用 Target 局部空间；调试绘制统一转为 SWF 根空间。两者不能混用。
- 760～960 是当前共享 HUD 的候选连续显示带，不是全宽或所有姿态的实测 UV 保证；独立校准／专用面板不据此宣称自身边界。
- 门控包括焦点、罗盘可见性、注视与对应设置；物理手掌跟随不能由 Flash 父子关系单独保证。
- 已部署的距离修复保持文字／箭头原底边向上放大；不等于整个父级动画期间都没有遮挡。

## 当前 HUD Debug
MCM Debug／Trace 开启全部普通诊断；Info 及以上关闭。独立校准仍手动控制。
D/H/M/N/Q/F/V 空心边框、短 ID 与最多两行英文替代旧坐标表和逐行红框；详细内容写日志。
Q 仅合并可见条目和省略标记，F 表示完整内容，V 为逻辑视口。空列表保留实例存在性和 V，不伪造 Q/F 的零尺寸内容。详见 [HUD Debug](hud-debug.md)。
旧英文诊断、省略定位与文字阴影已部署；最新 QL 门控原因、边框旁摘要和短 ID 限定显示带已部署，待实机验收。Info shown 与 QL: requested 均不等于列表最终可见，详见 [HUD Debug](hud-debug.md#英文状态释义)。

## 每帧更新优化
`PrepareOverflowLabel`负责最终目标裁剪及必要的回退恢复，`Update`不再重复执行同一遍裁剪。正常显示和直接紧凑替换不建立回退快照数组、不做无用的省略尺寸测量；仅实际进入预留回退时创建两个快照数组。最后可读目标保护只需判断是否存在可见目标，找到首个即停止扫描。

新增回归统计调用与分配次数：稳定正常帧及直接替换路径每条任务只裁剪一次，省略决策的两个回退数组分配为零。此结论不是帧率或耗时提升承诺；最终视觉、保护回退和Info默认值不变；本轮不执行部署。

## 源码结构与编辑入口
- `list/Overflow.as`：一次性标记创建、首个省略位置、尺寸校验与保护回退分离；`EnsureOverflowLabel`只创建图形，不修改可见目标。
- `item/Geometry.as`：一轮目标裁剪共用视口；每条目标只计算一次逻辑矩形，再合并文字／图标边界。不重复计算同一行底边。
- `GetVisibleBottomInRoot`是保留的旧函数名，实际返回`GetLayoutSpace()`坐标，不能凭名字当成根坐标。

`swf/QuestItem.as`、`swf/QuestItemList.as` 保留原两个入口；`swf/questlist/item/` 七个模块、`list/` 七个模块共 14 个。列表 Debug 只提供数据，Calibration 独立保留校准；唯一普通观察器在 `swf/compass/Debug.as`。
组合器检查显式 include、依赖哈希、缺失／重复／循环／越界／孤立模块和重复函数。[模块导航](../../swf/questlist/README.md)。不要维护第二份完整 AS2 或另载运行时列表。独立皮肤 SWF 是获准的纯图形库，通过现有 `!assets` 导入机制使用，不含脚本、字体或任务日志引用。

## SWF 构建与校验
在项目根目录逐条执行，任何一步失败就停止。`build.bat` 不会自动重编 ActionScript。

```powershell
$ff = '完整路径\ffdec-cli.jar'
python -X utf8 tools/questlist_source.py --output build/questlist-sources
python -X utf8 tools/build_questlist_swf.py --ffdec $ff
python -X utf8 tools/build_compass_swf.py --ffdec $ff
python -X utf8 tools/embed_questlist_compass.py --ffdec $ff
python -X utf8 tools/build_questlist_swf.py --check
python -X utf8 tools/build_compass_swf.py --check
python -X utf8 tools/embed_questlist_compass.py --check
python -X utf8 -m unittest discover -s tools/tests -p 'test_*.py'
```

随后从最终内嵌 Compass 导出脚本，运行 `questlist_layout.test.cjs`、`compass_debug.test.cjs` 和 `compass_marker_scale.test.cjs`。观察器测试三个参数为 QuestItem 类、sprite 511 的列表时间轴、Compass 主时间轴；距离测试参数为 scripts 目录。[工具说明](../../tools/README.md)。
只改 AS2 且 DLL 已对应当前原生源码时可用 `build.bat nobuild` 打包；C++ 改动须完整编译。发布两份内嵌 Compass 及配套的两份独立皮肤，不能漏装皮肤文件；生成基底只作构建输入。

## 原生素材皮肤验收
已从最终皮肤 SWF 导出矢量制作静态合成预览；不是游戏截图，不证明字体、滤镜、MO2 导入解析或 VR 渲染通过。目标行／排序、换行、缩放、省略、淡入及跟随逻辑不变。皮肤整理已在此前提交。此前英文诊断、文字阴影、省略 API 修复和菜单说明已有部署记录；当前最新 VR 根节点、QL 原因与标签位置修订已部署，待实机验收，不能把旧记录当作最新安装状态。备份和修复反馈分别见 [S2](../stages/s2-mcm.md) 与 [S1](../stages/s1-questlist.md)。

## 验收与历史
本次三项 Debug 修复由最终 SWF 的新增边界用例验证；正常布局、距离动画和设置链路另跑既有回归。构建、打包、安装与 VR 必须分别记录。
历史实验／部署证据见 [S2](../stages/s2-mcm.md)、[历史记录](quest-list-history.md)、[整理前指南存档](guidance-history.md)。本页是当前实现，不从旧记录推断“新包已安装”。

