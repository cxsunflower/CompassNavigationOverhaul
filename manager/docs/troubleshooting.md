<!-- 定位：L2 排障导航，区分代码、配置、安装与 VR 证据，不提供过期调试指令。 -->

# 问题排查

| 现象 | 优先核对 | 详情 |
|---|---|---|
| MCM 菜单缺失 | 本次 Helper／插件 DLL 加载、脚本、目录和覆盖来源 | [MCM](mcm.md) |
| Debug 无边框或英文状态 | 是否加载配套新 DLL／SWF、MCM 是否 Debug／Trace、共享祖先显隐、文字抑制原因 | [HUD Debug](hud-debug.md) |
| 日志提示 observer SWF missing | 实际 SWF 覆盖来源，不先改坐标或 UV | [玩家排障](../user-manual/debugging.md) |
| 目标提前省略或出现残片 | 当前 Q/F/V、fit/omission、父变换与同画面截图 | [QuestList](quest-list.md) |
| Palm 隐藏后低头仍出现列表 | 实际 VR 节点是否找到；mode=2/0 是否退回俯角；当前VR修订已部署，需新日志验收 | [任务门控排查](../user-manual/debugging.md#罗盘还在但任务列表不出现) |
| 罗盘仍在但空手时列表不出现 | QL 原因、原始武器状态、任务焦点、注视；requested 不保证最终渲染 | [英文状态释义](hud-debug.md#英文状态释义) |
| D/H 字母跑到顶部、摘要离罗盘很远 | 是否仍加载旧 SWF；短标签显示带、邻近候选及 labelSuppression，不先改 UV | [标签排查](../user-manual/debugging.md#dh-跑到画面顶部或摘要远离罗盘) |
| 距离与标记疑似重叠 | 区分自身缩放、父级动画、逻辑 AABB 与实际像素 | [HUD Debug](hud-debug.md) |
| Y菜单仍在或X范围仍为±100 | 只读安装核验已与最新输入一致；核对游戏是否重启、实际覆盖和中英文MCM是否同批 | [MCM审查](mcm-audit.md) |
| 源码与游戏行为不同 | 编译、嵌入、最终导出测试、打包和实际安装逐层对照 | [开发流程](../user-manual/development.md) |

缺失对象、空列表和隐藏状态分别报告；固定英文状态在没有安全位置时允许隐藏。不应通过强制显示隐藏祖先来排障。
使用本次启动日志和当前安装证据。旧阶段里的红框、R/L 数字和 debugState 接口不是当前指引；旧指南保留在[历史存档](guidance-history.md)。
不得为缺少日志而先重置 MCM、清理存档、扩大安全区或恢复 UV 补偿。模拟测试不能证明真实 VR 可见范围。
