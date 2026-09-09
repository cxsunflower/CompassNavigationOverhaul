<!-- 定位：L2 架构说明，提供模块职责、数据流和关键源码导航。 -->

# 架构与模块

```text
游戏任务/标记与玩家状态
  → HUDMarkerManager / QuestObjectiveData
  → QuestItemList 原生快照及 GFx 调用
  → Compass 内嵌 QuestItemList / QuestItem（AS2）
  → Scaleform HUD

MCM config.json + settings.ini → MCM Helper / 设置注册
  → source/settings/ → 原生门控、缩放及布局更新
```

| 模块 | 职责 | 入口 |
|---|---|---|
| 罗盘与门控 | 聚焦、注视、可见状态 | source/hud/、include/Compass.h |
| 任务数据 | 目标收集、去重、状态与内容签名 | source/questlist/Objectives.cpp、source/questlist/Bridge.cpp、Sync.cpp |
| 设置 | 注册、读写及变更应用 | source/settings/、include/Settings.h |
| Hook 与兼容 | 指令校验、跳板、回调及第三方兼容 | source/hooks/、include/Hooks.h |
| UI 生命周期 | GFx 罗盘接口、Infinity UI 接入、设置应用 | source/ui/、include/Compass.h |
| Flash UI | 布局、状态排序、字体与装饰 | swf/QuestItemList.as、swf/QuestItem.as |
| SWF 构建 | 原始基底→Header包装器→重编译→嵌入发布资源 | tools/questlist_header_layout.py、tools/build_questlist_swf.py、tools/embed_questlist_compass.py |
| 配置与发布输入 | 主包、中文覆盖、原始素材、生成中间件 | assets/main/、localization/zh-CN/、source/、generated/ |

## 关键边界
- C++ 通过 GFx 向 AS2 传递任务及目标状态，不是 Web API；没有需新增的 HTTP 接口或鉴权流程。
- Infinity UI/Scaleform 控制 HUD 资源，Flash 层级不能消除 VR 网格 UV 分区限制。
- Helper 菜单注册与罗盘 DLL 加载是两条需分别验证的链路。
- 详细接口与六参数兼容要求见 [QuestList](quest-list.md)，菜单配置契约见 [MCM](mcm.md)。

职责导航见 [C++ 目录](../../source/README.md) 和 [资源目录](../../assets/README.md)。私有实现头文件与源文件同目录；原始素材、构建中间件、发布文件分开放置，只有主包与语言覆盖输入参与打包。
