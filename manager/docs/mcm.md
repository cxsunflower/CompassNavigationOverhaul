<!-- 定位：L2 当前 MCM 配置契约、设置链路、验证步骤与运行时排障边界。 -->

# MCM 配置与菜单排查

## 最新全设置审查
原29项菜单已追踪至消费点（删除Y后现28项）：两项标记开始／保持角度存在单例缓存导致的热更新缺陷；模式依赖项和菜单外兼容键分别记录。13项绑定测试通过不代表全量有效；中文完整校验另有 HUD 缩写白名单问题。详见 [逐项审查与优先级](mcm-audit.md)。后续已按授权删除Y偏移并扩大X范围；本轮没有执行部署；历史只读检查曾发现偏移修订的安装输入与当时产物一致，更新过程未确认。

## 当前契约
- 名称和距离：`[Display] fMarkerNameScale / fMarkerDistanceScale`，25～150%。
- 列表面板：`[QuestList] fTextScale`，25～110%；自动缩小下限 `min(90,期望值)`，自然宽度后缩小／省略，不向固定装饰外扩宽正文。
- 列表仅保留横向偏移：`fOffsetX`，范围-200～200、步长5、默认0；中英文菜单、C++及AS2范围一致。`fOffsetY`整条设置链路已删除，垂直位置由固定布局决定；继续跟随罗盘。X已通过Passenger模拟端点测试，实机效果仍待查。本轮不执行部署；实际安装变化见审查记录。[证据](mcm-audit.md)
- 最大高度设置已退役；旧 `fPositionX/fPositionY` 已从变量、注册／分发及发布默认INI中删除，不再读取；横向相对偏移保留，已有用户INI不重写。本删除已部署，待实机验收。
- 列表页保持左右双栏，“需要注视罗盘”默认开启；用户已有保存值仍优先。
- **MCM 日志级别 Debug／Trace 开启全部普通 HUD 诊断，Info 及以上关闭（默认 Info）。**不需要独立普通开关；校准由 `bCalibrateQuestList` 单独控制。[当前 Debug](hud-debug.md)。

## 配置来源与安装关系
英文母本与默认 INI：`assets/main/MCM/Config/Compass Navigation Overhaul VR/`；中文母本：`assets/localization/zh-CN/MCM/Config/Compass Navigation Overhaul VR/config.json`。CHS 只覆盖同路径配置，不是独立完整模组。
不翻译 `modName`、ID、sourceType、数值占位符；目录名、ESP 主干与 modName 保持一致。

设置优先级从低到高：
1. `Data/MCM/Config/Compass Navigation Overhaul VR/settings.ini`
2. `Data/SKSE/Plugins/CompassNavigationOverhaulVR.ini`
3. `Data/MCM/Settings/Compass Navigation Overhaul VR.ini`

原生注册、分发和菜单关闭时的重载共用该链路。修改发布默认值不等于覆盖用户保存值，不删除保存 INI 或清理存档来排障。

## UTF-8 BOM 兼容
`INIInput` 对含 BOM 输入提供临时规范化读取视图，读取后清理；无 BOM 时透传原路径。用户文件不重写，三层优先级不变。历史证据在 [S2](../stages/s2-mcm.md#2026-09-09-utf-8-bom-首节读取修复)。旧 `allowed/debugState` 字段不作为新观察器的检查接口。

## 修改、测试和打包
文案从英文母本和 `tools/make_mcm_config_zhcn.py` 翻译规则同步生成；不能只改中文母本。
```powershell
python -X utf8 tools/make_mcm_config_zhcn.py
python -X utf8 tools/tests/test_mcm_bindings.py
# 若 C++ 改动，必须使用完整 build.bat；仅配置且 DLL 已匹配时：
.\build.bat nobuild
python -X utf8 tools/verify_mcm_config_zhcn.py
```
任一步非零就停止。完整校验器会比较已有打包暂存文件，母本修改后须重新打包再校验。绑定测试核对 INI 分节、注册／回调、默认值、范围、双语结构与退役设置。

## 菜单不显示：排查顺序
1. 查看本次启动 `sksevr.log`、`MCMHelper.log` 和 `CompassNavigationOverhaulVR.log`；Windows 文档目录可能被重定向。
2. 确认 Helper 与罗盘 DLL 真正加载；MO2 勾选和 ESP 启用不等于 DLL 加载成功。
3. 核对实际配置目录、JSON、脚本与 DLL 的覆盖来源，不只看工作区母本。
4. 完全重启后核对菜单注册、保存与中文显示；仍异常再调查脚本，不先重置配置。

## 部署与验收状态
此前配套 DLL、两份内嵌 Compass 与中英文 MCM 配置已有部署，武器隐藏行为不变；VR根搜索／QL诊断／标签位置已部署、待实机验收；之后的Y删除和X扩范围在本轮只读安装检查中也已与最新产物相符，更新执行过程未确认，本次发现的两项标记角度热更新缺陷尚未修复。已有 Helper 注册成功是历史事实，文件部署成功不等于当前进程已加载新包。
静态通过不验证 Papyrus、VR 字形或真实菜单热重载；仍需实机对比 Debug／Trace 开启、Info 关闭、校准独立和保存优先级。
[当前列表](quest-list.md) · [玩家排障](../user-manual/debugging.md) · [整理前证据](guidance-history.md)

## 武器拔出隐藏开关
菜单名称现为“拔出武器时隐藏”／“Hide With Weapon Drawn”，不是实际战斗检测。帮助说明以游戏报告的武器拔出状态为准，与战斗状态无关；设置键仍为 bHideInCombat:QuestList，默认值和保存配置不变。CommonLib 的 IsWeaponDrawn 对 Drawn、WantToSheathe、Sheathing 返回 true，因此持续隐藏需先区分未完成收刀、VR 动作状态与其他门控；没有实机状态证据时不归因于具体模组。该次改动只澄清菜单文字，保留原行为，已部署但待游戏内确认。
