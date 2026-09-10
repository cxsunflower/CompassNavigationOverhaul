<!-- 定位：玩家与开发者的安全排障步骤及日志入口。 -->

# 调试指南

## 菜单找不到
1. 查看本次启动的 sksevr.log，确认 Helper 和罗盘 DLL 都成功加载。
2. 检查当前 MO2 配置、ESP 勾选及主包/中文包的文件覆盖来源。
3. 检查实际安装的配置，而不是只看源码目录。
4. 依赖恢复后完全重启游戏，重新确认菜单注册和中文显示。

日志通常在 Windows 文档目录下 `My Games/Skyrim VR/SKSE/`，文档目录可能被重定向。重点日志为 sksevr.log、MCMHelper.log、CompassNavigationOverhaulVR.log。

历史上 22:26 启动曾出现 Helper 加载失败；后续 22:37 启动已成功注册设置/菜单。名称/距离及 QuestList 后续修复已有多轮部署记录，但仍需按各项说明完成 VR 实机验收；偏移范围和最大高度清理已完成。[详细记录](../docs/mcm.md)。

## HUD 几何和提前省略排查
新 Debug 已构建、尚未部署。确认配套的新 DLL 与内嵌 Compass 已安装后，在 MCM「调试 → 日志级别」选择 Debug 或 Trace，关闭菜单后开启全部普通 HUD 诊断；切回 Info 或更高级别关闭。默认 Info，不再需要 bDebugOverlay；旧的 bShowQuestListLayout 也不参与判定。不要删除或重编码 MCM 保存文件。

画面只显示 D/H/M/N/Q/F/V 短标记与最多两行中文。Q 是可见内容的保守逻辑范围，F 是完整内容，V 是逻辑视口；红色重叠提示不是实际像素遮挡证明。隐藏父级、缺失对象、文字放不下等原因写入插件日志，不强制显示画面。没有任务时仍能观察距离和聚焦标记。

复现时保留完整截图与同次启动的 `[HUDDebug]` 日志，重点比较动画帧、请求／实际缩放、父变换、四角、Q/F/V、间隙、fit/omission 及抑制原因。若日志出现 `observer SWF missing`，先核对实际覆盖来源，不盲目改 UV 或安全高度。逻辑边界和截图空白不能证明 VR 可用区域。

结束后在 MCM 将日志级别恢复 Info，关闭菜单应用。独立十字校准仍使用 `bCalibrateQuestList`，不会被普通开关改写；同时开启校准时普通叠加层暂时隐藏。

[完整定义与回归](../docs/hud-debug.md) · [校准操作](calibration.md) · [QuestList 实现](../docs/quest-list.md)

## 其他现象
字形方框、描边、列表位置和源码/产物不同步的排查入口见 [问题导航](../docs/troubleshooting.md)。

不要在日志不足时先清理存档、删除用户配置、盲目重置 MCM 或覆盖整套依赖。测试报告应区分静态通过、已安装检查和实际游戏效果。
