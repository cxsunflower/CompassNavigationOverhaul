<!-- 定位：L2 当前 MCM 配置契约、设置链路、验证步骤与运行时排障边界。 -->

# MCM 配置与菜单排查

## 当前契约
- 名称和距离：`[Display] fMarkerNameScale / fMarkerDistanceScale`，25～150%。
- 列表面板：`[QuestList] fTextScale`，25～110%；自动缩小下限 `min(90,期望值)`，自然宽度后缩小／省略，不向固定装饰外扩宽正文。
- 列表相对偏移：`fOffsetX / fOffsetY`，-100～100、步长 5、默认 0；继续跟随罗盘。
- 最大高度设置已退役；旧 `fPositionX/fPositionY` 为兼容键，不作为当前相对偏移入口。
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
新普通 Debug 和三项边界修复已构建、**尚未部署**，需要配套新 DLL 与两份内嵌 Compass。已有 Helper 注册成功和距离修复部署是历史事实，不能据此宣称这次新包已加载。
静态通过不验证 Papyrus、VR 字形或真实菜单热重载；仍需实机对比 Debug／Trace 开启、Info 关闭、校准独立和保存优先级。
[当前列表](quest-list.md) · [玩家排障](../user-manual/debugging.md) · [整理前证据](guidance-history.md)
