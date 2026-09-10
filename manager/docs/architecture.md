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

## 掌上独立显示：现状与目标分开

```text
当前完整任务UI：任务数据 → GFx → Compass内嵌QuestList → 共享HUD表面
当前测试支路：Palm更新罗盘节点 → HIGGS后置观察 → RoomNode下独立NIF/DDS静态面板
尚未实现：任务数据 → 独立Scaleform/纹理输出 → 独立掌上任务面板
```

- Palm继续拥有原罗盘的变换；本项目测试支路只读其位置/方向和节点可见状态，独立控制面板物理尺寸与偏移，不修改Palm。
- 旧760～960候选连续带仅适用于共享HUD内嵌路径；独立面板不复制该数值。统一坐标、整行裁切、换行/省略等原则可复用，但需按新渲染视口重验。
- 当前只有静态模型已构建部署，尚未通过VR验收，更未完成独立任务UI。保留内嵌路径；不得从上图推断已实现自动模式切换。
- 选型代价、旧测试价值及迁移门槛统一见[掌上原型复盘](palm-test-panel.md#架构转向复盘旧边界测试的价值与适用范围)。

## 源码整理与资源所有权

palmtest当前源码将配置IO和只读场景查询移出运行时控制器，Surface独占本项目面板资源，Runtime持有罗盘观察引用和调度状态；对外SKSE消息接口不变。该重构已构建但未部署，不等于独立任务UI已完成。首批范围及后续热点见[源码整理](source-cleanup.md)。

## 关键边界
- C++ 通过 GFx 向 AS2 传递任务及目标状态，不是 Web API；没有需新增的 HTTP 接口或鉴权流程。
- Infinity UI/Scaleform 控制 HUD 资源，Flash 层级不能消除 VR 网格 UV 分区限制。
- Helper 菜单注册与罗盘 DLL 加载是两条需分别验证的链路。
- 详细接口与六参数兼容要求见 [QuestList](quest-list.md)，菜单配置契约见 [MCM](mcm.md)。

职责导航见 [C++ 目录](../../source/README.md) 和 [资源目录](../../assets/README.md)。私有实现头文件与源文件同目录；原始素材、构建中间件、发布文件分开放置，只有主包与语言覆盖输入参与打包。

## 普通 HUD Debug
唯一普通观察器位于 `swf/compass/Debug.as`，构建时并入 Compass；QuestList 的 Debug 模块只提供数据，Calibration 模块保留独立校准。`SettingsLifecycle::PollDebugOverlay` 从原罗盘更新路径取走有界日志，默认关闭，不进入布局测量。详见 [HUD Debug](hud-debug.md)。
