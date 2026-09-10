<!-- 定位：面向玩家、测试者和开发者的使用手册入口，当前状态只引用项目索引。 -->

# 使用手册

## 当前提示
新普通 Debug 及本次三项边界修复已构建，**尚未部署，VR 未验收**。此前距离修复的安装状态不代表新 Debug 已安装。最新状态见 [CONTEXT](../CONTEXT.md)。

## 三步上手
1. 阅读 [安装与环境](setup.md)，区分玩家安装与开发构建。
2. 玩家看 [菜单操作](ui-guide.md)，开发者看 [开发流程](development.md)。
3. 出现问题先看 [调试指南](debugging.md)，不要先改存档或删除保存配置。

| 读者 | 文档 |
|---|---|
| 所有人 | [架构概览](architecture.md)、[安装](setup.md) |
| 玩家与测试者 | [界面操作](ui-guide.md)、[排障](debugging.md)、[独立校准](calibration.md) |
| 开发者 | [开发和验证](development.md)、[技术架构](../docs/architecture.md)、[HUD Debug 定义](../docs/hud-debug.md) |

普通诊断由 MCM Debug／Trace 开启、Info 及以上关闭；校准单独控制。配置来源和旧保存值优先级见 [MCM](../docs/mcm.md)。
