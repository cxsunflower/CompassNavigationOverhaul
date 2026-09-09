<!-- 定位：L2 MCM 配置、校验流程及尚未解决的运行时故障证据。 -->

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
