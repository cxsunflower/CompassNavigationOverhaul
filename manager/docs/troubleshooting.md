<!-- 定位：L2 按现象导航的排障入口，不重复保存具体故障日志。 -->

# 问题排查入口

| 现象 | 首先检查 | 详情 |
|---|---|---|
| MCM 中没有罗盘菜单 | 最新 SKSE 日志中 Helper 是否真正加载 | [MCM 排查](mcm.md) |
| 菜单未汉化 | CHS 是否覆盖同路径 config.json，是否被 overwrite 覆盖 | [MCM 安装关系](mcm.md) |
| 校验提示暂存副本过期 | 修改母本后是否重新打包 | [MCM 修改流程](mcm.md) |
| SWF/source mismatch | AS2、SVG、基底与哈希清单是否配套重建 | [SWF 工作流](quest-list.md) |
| Debug模式没有布局红框 | 先读取最新有效日志级别、`[QuestListDebug]`与`debugState`；核对UTF-8 BOM首节兼容 | [配置读取](mcm.md)、[可视化调试](quest-list.md) |
| 菱形过粗/装饰不清 | 区分图标描边与目标分隔装饰参数 | [样式](quest-list.md) |
| 列表未跟随手掌 | 检查已撤回的 UV 方案边界，不再次强加补偿 | [历史档案](quest-list-history.md) |

先收集证据并确认日志时间；不要先删除 INI、重置菜单或清理存档。历史上的 Helper 加载失败已被后续成功注册日志取代；若菜单再次缺失，应按最新启动日志重新定位，具体证据与待查项只维护于 mcm.md。

红框复测应在重新启动SKSEVR后将MCM日志级别设为Debug(1)，关闭菜单并查看独立摘要。新版诊断不再因普通HUD隐藏而自我消失；若仍无摘要，先检查最新插件日志中的`[QuestListLayout]`与`debugState`，区分设置未应用、SWF接口缺失、实例未创建和画面映射问题。不要靠删除用户INI、扩大安全区或恢复UV补偿来猜测原因。

15:47–15:51真实日志已确认过一次原生初始化漏同步：MCM保存Debug但嵌入式实例enabled=false。15:57版已统一嵌入、兼容补丁和热重载路径。`requested=true; method=true; state=enabled=true`才表示开关已到达SWF；若这些成立仍没有画面，再调查实际渲染/字体/可视范围。日志位于Windows实际文档目录的`My Games/Skyrim VR/SKSE/`，不要假定用户目录一定在C盘。

16:03–16:05复测进一步确认requested=false是保存INI的UTF-8 BOM使首个Debug节被原生读取器忽略。16:15版已加入临时去BOM视图，不修改用户文件。再次复测应先确认`[Settings] effective logLevel=1`和`[QuestListDebug] level=1 allowed=true requested=true`；如果仍为2，采集该次完整加载日志，不再通过反复覆盖SWF猜测。
