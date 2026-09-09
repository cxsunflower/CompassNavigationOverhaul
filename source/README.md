# C++ 模块导航

公开接口位于 `include/`；只供实现使用的头文件与 `.cpp` 放在同一职责目录。CMake 递归发现两类文件，无须手工维护源文件列表。

| 目录/入口 | 职责 |
|---|---|
| `main.cpp`、`MessageListeners.cpp` | 插件加载、SKSE 消息入口 |
| `hooks/Install.cpp` | 调用点验证、跳板和虚表 Hook 安装 |
| `hooks/QuestMarkers.cpp` | 任务目标匹配、别名兜底与诊断 |
| `hooks/Markers.cpp` | 地点、敌人、玩家标记与罗盘更新回调 |
| `hooks/Effects.cpp`、`Compatibility.cpp` | 效果转发、MapMarkerFramework 兼容 |
| `hooks/Internal.h` | 内部回调声明、重定位与原函数指针；不向公共接口暴露 |
| `hud/` | 标记呈现、阵营判断、聚焦、注视与场景节点 |
| `questlist/` | 目标数据、GFx 桥接、快照同步 |
| `settings/` | INI 加载、设置分发与注册 |
| `ui/` | Compass 的 GFx 方法、Infinity UI 接入、设置生命周期 |
| `NND/`、`RE/`、`utils/` | 第三方名字接口、引擎类型补充与通用工具 |

编辑 Hook 时保持调用约定、地址偏移、安装顺序和指令校验；调试扫描属于任务匹配诊断，不是新的目标读取路径。修改原生代码后运行根目录 `build.bat`，不能用 `nobuild` 代替编译。游戏内行为仍需 VR 验收。
