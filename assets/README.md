# 资源目录与发布边界

| 目录 | 内容 | 是否直接打包 |
|---|---|---|
| `main/` | 英文主包；目录对应游戏 Data 根目录 | 是 |
| `localization/zh-CN/` | 简体中文覆盖包；同样保持 Data 相对路径 | 中文 MCM 配置由 `build.bat` 打包 |
| `source/questlist/` | 不可变 QuestList 基底、原始标题 SWF 与目标 SVG | 否 |
| `generated/` | 由源码重建的 QuestList 与嵌入前 Compass | 否；用于后续嵌入构建 |

AS2 和 FLA 编辑工程仍在根目录 `swf/`。构建、翻译、校验脚本及哈希清单在 `tools/`。生成的 SWF 与哈希清单保留为版本控制输入，随对应源码一起审阅，不能被通用二进制忽略规则排除。

构建链：`source/questlist/` + `swf/` → `generated/QuestItemList.swf`；罗盘 AS2 → `generated/Compass.before-embedded.swf`；二者嵌入后生成 `main/Interface/InfinityUI/` 下 HUDMenu 与 VR_HMD_info 两份 `Compass.swf`。具体命令见 [工具说明](../tools/README.md)。

中文源配置位于 `localization/zh-CN/MCM/Config/Compass Navigation Overhaul VR/config.json`。它由英文配置及翻译规则生成，与主包配置使用相同文件名，安装后覆盖同一位置。

原始素材不得被生成产物覆盖。禁止独立部署 `QuestItemList.swf`，禁止恢复已撤回的 Palm UV/网格补偿。两份发布 Compass 保持各自游戏安装路径，不以符号链接代替。

当前 VR 任务列表复用 Compass SWF，通过 Passenger 区域布局、裁剪和溢出控制限制在共享 HUD 显示范围内。

