<!-- 定位：L1 项目索引，仅说明项目身份、当前状态和按需导航。 -->

# Compass Navigation Overhaul VR

## 项目身份
- 目标：扩展 Skyrim VR 罗盘信息、任务详情及 MCM 设置。
- 技术栈：C++、CommonLibSSE-NG VR、SKSEVR、Infinity UI、AS2、Python、CMake。
- 项目管家初始化：2026-09-08；项目版本仅以 vcpkg.json 为准。

## 当前状态
- 阶段：S2 普通 HUD Debug 修复与 S3 文档一致性整理；S4 保持原有静态原型状态。
- 已完成：新 Debug 替换旧实现；MCM Debug／Trace 联动；线段裁剪、Q 可见范围、空列表状态三项修复已构建回归。
- 正在做：等待另行确认部署，再进行 VR 字体、动画、映射及重建验收。
- 部署边界：新 Debug 未部署；此前距离底边修复已部署，未回退。现有安装和用户配置保持不变。
- Git：用户已授权将本轮累积改动按职责分批提交，提交信息统一英文；本地提交记录以 git log 为准，不推送、不部署。
- 阻塞：缺少新方案 VR 实机证据；模拟测试不代表物理显示或 UV 边界已验证。

## 阶段摘要
| 阶段 | 状态 | 详情 |
|---|---|---|
| S1 QuestList | 源码与构建验证完成，视觉待验收 | [S1](stages/s1-questlist.md) |
| S2 MCM 与 HUD | 新 Debug 及三项审查修复已构建，未部署 | [S2](stages/s2-mcm.md) |
| S3 文档 | Skill 分层与一致性已整理，审查结果留档 | [S3](stages/s3-documentation.md) |
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
