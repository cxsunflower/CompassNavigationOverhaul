<!-- 定位：玩家与开发者的安全排障步骤及日志入口。 -->

# 调试指南

## 菜单找不到
1. 查看本次启动的 sksevr.log，确认 Helper 和罗盘 DLL 都成功加载。
2. 检查当前 MO2 配置、ESP 勾选及主包/中文包的文件覆盖来源。
3. 检查实际安装的配置，而不是只看源码目录。
4. 依赖恢复后完全重启游戏，重新确认菜单注册和中文显示。

日志通常在 Windows 文档目录下 `My Games/Skyrim VR/SKSE/`，文档目录可能被重定向。重点日志为 sksevr.log、MCMHelper.log、CompassNavigationOverhaulVR.log。

历史上 22:26 启动曾出现 Helper 加载失败；后续 22:37 启动已成功注册设置/菜单。名称/距离及 QuestList 后续修复已有多轮部署记录，但仍需按各项说明完成 VR 实机验收；偏移范围和最大高度清理已完成。[详细记录](../docs/mcm.md)。

## 任务详情提前显示省略号
16:15版已修复UTF-8 BOM使保存INI首个Debug节被忽略的问题。完全重启SKSEVR后，先确认新日志的`[Settings] effective logLevel=1 layoutDebugAllowed=true`，以及`[QuestListDebug] level=1 allowed=true requested=true method=true state=enabled=true`。若有效级别仍为2，请提供该次日志；不要删除或重编码保存文件。只有上述状态正确但画面仍无红框时，才继续检查实际渲染。

15:57原生修复已解决代码中首次嵌入漏同步调试开关的问题。完全重启SKSEVR后，在最新插件日志中确认`[QuestListDebug]`的`requested=true`、`method=true`及`state=enabled=true`。若requested=false，应检查实际保存/加载的日志级别和独立开关；若method=false，应核对实际加载的嵌入式SWF；只有运行时确认enabled=true仍没有图形时，才进一步检查VR渲染路径。不要靠反复改INI或猜测安全区定位。

先确认已安装最新高度修复及调试叠加层主包/CHS，不要单独安装QuestItemList.swf。进入能够复现问题的同一任务画面，在MCM「调试 → 日志级别」选择Debug（或Trace），关闭菜单后重新看向罗盘使任务列表显示。此时应出现红框、数字标签和安全边界线；同时截取完整画面，保留正文、目标、省略号、红线与顶部摘要。调试开关需要设置重新应用，若菜单关闭后尚未更新，可再次开关菜单或重启游戏。

红框表示整体Box/正文/目标，橙框表示标题装饰，青框和线表示局部遮罩及内容限制，虚线表示隐藏行。标签`R (x,y) w x h`是Flash根坐标包围盒，`L w x h`是局部逻辑尺寸。摘要中的Stage、Safe bottom、Content limit、Full bottom、Visible bottom、Fit、Omit用于判断实际省略原因，不代表VR物理像素或贴图UV边界。调试期间原有底部安全保护仍生效，框和数字也可能被真正的VR画面裁切。

如需完整日志，在同一任务画面将任务列表缩放临时调整一个步长再恢复，关闭菜单触发设置应用。新版本会按需刷新一次布局并写入`[QuestListLayout]`，不需要开启逐帧日志。请保留该行的Stage尺寸、rootScale、安全/内容限制、完整/可见底边、Header/Body尺寸、fitReason、omissionReason和目标行状态，并附上对应截图。

完成诊断后将日志级别恢复Info。若需要保留Debug日志但关闭红框，可在用户插件INI的`[Debug]`分区设置`bShowQuestListLayout=0`，保存并重新加载设置；该独立开关默认1，不需要删除任何MCM保存文件。现有用户配置优先级仍然生效。

若实际目标仍被省略，需依据这些数据判断是内容确实超过安全区、测量偏差还是VR映射问题。不要先删除保存配置、降低可读性下限或撤销底部安全保护。当前新包尚未实机验收，不能仅凭画面空白判定可用高度。[实现与验收说明](../docs/quest-list.md)。

## 其他现象
字形方框、描边、列表位置和源码/产物不同步的排查入口见 [问题导航](../docs/troubleshooting.md)。

不要在日志不足时先清理存档、删除用户配置、盲目重置 MCM 或覆盖整套依赖。测试报告应区分静态通过、已安装检查和实际游戏效果。
