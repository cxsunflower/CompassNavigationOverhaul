<!-- 定位：L1 项目索引，只记录项目身份、当前状态和按需导航。 -->

# Compass Navigation Overhaul VR

## 项目身份
- 目标：扩展 Skyrim VR 罗盘信息与任务列表，提供 MCM 设置。
- 技术栈：C++ / CommonLibSSE-NG VR、SKSEVR、Infinity UI、AS2/Scaleform、Python、CMake。
- 版本唯一来源：根目录 vcpkg.json，不在文档重复记录具体值。
- 项目管家初始化：2026-09-08；原项目创建时间未核实。

## 当前状态
- 当前阶段：[S2 MCM 配置与菜单恢复](stages/s2-mcm.md)，运行时布局验收仍进行中。
- 已完成：C++ 按 hooks/hud/questlist/settings/ui 分工，Hook 公私接口和 Compass 实现分离，修正拆分遗漏的包含依赖；详情见[整理记录](docs/organization.md)。
- 资源：主包、中文覆盖包、原始素材、生成中间件分目录；构建路径、翻译工具、哈希清单与文档已同步。
- 布局：DetailBox → Header + DetailBody，保留当前Passenger逻辑区域与罗盘跟随；缩放上限110、自动下限min(90,期望值)，固定宽度→缩小→完整段/行省略。
- 配置：任务列表期望上限110%，缩小下限min(90,期望值)，名称/距离上限150%；偏移-100～100、步长5、默认0，最大高度设置已退役。
- 验证：02:51日志确认省略号42坐标预留挤掉全部目标；省略号改随item比例并保护最后可读目标，56/56反编译模拟、24/24 Python及打包通过。
- 部署：02:59两份Compass哈希一致，100个受保护文件未变；备份`_patch_work/compass-debug-scale-20260910-025957`。未暂存/提交。
- 下一步：重启实测目标不再被省略号全部挤掉；保留已确认不跨区的候选带，空间不足时宁可保留最后目标而不画省略号。
- Git：用户已授权全部工作区改动按职责细分本地提交，包括已有子模块暂存项；排除隐私、临时备份和构建输出，不push。提交后以git log为记录。

## 阶段摘要
| 阶段 | 状态与结果 | 详情 |
|---|---|---|
| S1 QuestList 调整 | 源码/构建验证完成，视觉待验收 | [S1](stages/s1-questlist.md) |
| S2 MCM 与布局 | 设置、调试、源码及资源整理完成，VR待验收 | [S2](stages/s2-mcm.md) |
| S3 项目文档 | 分层文档完成，当前索引已收拢 | [S3](stages/s3-documentation.md) |

## 导航规则
- 通用约定 → [agents.md](agents.md)。
- 架构与模块定位 → [architecture](docs/architecture.md)、[C++ 导航](../source/README.md)。
- 资源与整理边界、后续维护项 → [资源说明](../assets/README.md)、[整理记录](docs/organization.md)。
- QuestList 修改/构建 → [quest-list](docs/quest-list.md)。
- MCM 配置/绑定与菜单排查 → [mcm](docs/mcm.md)。
- 排障入口 → [troubleshooting](docs/troubleshooting.md)。
- 可复用经验 → [experience](docs/experience.md)。
- 历史实验与回退 → [QuestList 历史](docs/quest-list-history.md)、[旧索引快照](docs/context-history-20260909.md)，仅按需读取。
- 安装、操作或开发上手 → [使用手册](user-manual/README.md)。
- 隐私数据只在任务需要时读取 privacy.md，不预加载。
## 本轮整理与验收摘要
- 连续显示带：用户确认跨区现象不再出现；不等于全宽/所有姿态已标定。
- 目标过早省略：已定位省略号预留挤占并部署修正；实机恢复情况尚未确认。
- 详细交付与提交分组见[交付记录](docs/delivery-review.md)。
