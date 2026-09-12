<!-- 定位：L1 项目索引，仅说明项目身份、当前状态和按需导航。 -->

# Compass Navigation Overhaul VR

## 项目身份
- 目标：扩展 Skyrim VR 罗盘信息、任务详情及 MCM 设置。
- 技术栈：C++、CommonLibSSE-NG VR、SKSEVR、Infinity UI、AS2、Python、CMake。
- 项目管家初始化：2026-09-08；项目版本仅以 vcpkg.json 为准。

## 当前状态
- 当前工作：运行时统一及正式包隔离PalmTest／meta.ini；64项Python、正式VR编译、临时主包15／汉化1文件校验通过。本批已获准提交，结果以git log为准；不部署、不推送。
- 当前实现：三点矢量标记按实际23×5边界占位；目标任一子元素越界时整条替换并停止后续；Q/F/V线段限制在列表显示带。[实现](docs/quest-list.md)
- 设置：仅保留X偏移±200；28项菜单、34个注册键；默认Info关闭普通诊断。旧Y／绝对位置键已退役。[MCM](docs/mcm.md)
- 安装证据：本轮只读核对两份SWF、中英文MCM及默认INI与当前输入一致；外部更新过程未确认，不执行覆盖或回滚。文件一致不等于实机通过。[审查](docs/documentation-review.md)
- 验证：55项Python、60项最终SWF布局、16组观察器、84项距离回归；源码及资源清单配套检查。构建不等于部署或VR验收。
- 待处理：X实机效果、两项标记角度缓存、Palm隐藏／恢复、空手时列表缺失、标签和三点可读性；精确完成时间排序仍缺数据。[问题](docs/mcm-audit.md)
- Git：此前4次提交已撤回；用户重新授权本批分组英文提交，具体结果以git log为准。不部署、不推送，后续授权不自动延续。

## 阶段摘要
| 阶段 | 状态 | 详情 |
|---|---|---|
| S1 QuestList | 旧 Palm 修复未通过；VR 节点与门控修订已部署、待实测 | [S1](stages/s1-questlist.md) |
| S2 MCM 与 HUD | 武器隐藏菜单已部署；新英文诊断与标签位置已部署、待实测 | [S2](stages/s2-mcm.md) |
| S3 文档 | 已按 Skill 同步当前状态、排障、手册与经验 | [S3](stages/s3-documentation.md) |
| S4 独立掌上原型 | 仅静态原型已部署，未完成独立任务 UI | [S4](stages/s4-palm-test.md) |

## 导航规则
- 通用约定 → [agents](agents.md)；开发与资源 → [架构](docs/architecture.md)、[C++ 导航](../source/README.md)。
- 当前 Debug、日志与验收 → [HUD Debug](docs/hud-debug.md)。
- 列表行为与构建 → [QuestList](docs/quest-list.md)；配置链路 → [MCM](docs/mcm.md)。
- 排障与未完成项 → [问题导航](docs/troubleshooting.md)、[遗留问题](docs/experience.md#遗留问题追踪)。
- 源码整理与原型边界 → [源码整理](docs/source-cleanup.md)、[掌上原型](docs/palm-test-panel.md)。
- 安装、操作与开发 → [使用手册](user-manual/README.md)。
- 文档规则符合性 → [本轮文档审查](docs/documentation-review.md)。
- 历史实验 → [QuestList 历史](docs/quest-list-history.md)、[整理前指南存档](docs/guidance-history.md)；不作为当前操作指引。
- Skill 原文只读；隐私映射仅在任务确需时读取，不预加载。
