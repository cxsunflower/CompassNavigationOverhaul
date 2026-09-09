# QuestList Passenger 模式调试记录

## 背景

目标：在不扩展 Palm Compass、不修改 Compass HUD 图集结构的情况下，让 QuestList 作为 Compass 当前 UV 区域中的乘客显示。

当前设计原则：

- QuestList 不创建 dedicated VR panel。
- QuestList 不申请新的 HUD 纹理区域。
- Debug 只能观察布局，不能改变 QuestList 显示状态。
- Compass 原有采样区域保持不变。

---

## 坐标系统

旧方案问题：

```
QuestList
  -> root space
  -> HUD transform
```

导致 Debug 框和实际内容不重合。

新方案：

```
QuestList
  -> Passenger Layout Space
  -> Compass local transform
```

所有 Debug 几何必须使用 Passenger Layout Space。

禁止：

```
globalToLocal(_root)
```

作为 QuestList 主布局参考。

---

## Debug 层规则

Debug 只能绘制：

- 边界线
- 标签文字
- 参考线

禁止绘制：

- ClipMask 填充面
- ViewportMask 填充面
- Placeholder panel
- 任何影响 HUD 采样的 MovieClip

Mask 关系：

```
Mask
 |
 +-- 参与裁剪
 |
 +-- 不可见
```

---

## 当前已发现问题

### 1. Debug 白色面片

表现：

- VR 中出现白色弧形区域。

原因：

- Debug mask 使用 beginFill。
- Clip geometry 被错误当作可见绘制。

修复方向：

- 移除 beginFill。
- ClipMask `_visible=false`。
- Debug 只保留线框。

---

### 2. QuestList 尺寸异常

表现：

- QuestList 内容缩小。

可能原因：

```
Embed scale
    +
Layout fit scale
    +
Passenger scale
```

产生重复缩放。

正确方案：

```
位置 -> Compass transform
尺寸 -> 单次 FitLayout
```

不能同时叠加多个 scale。

---

## 后续修复顺序

1. 清理 Debug 可见填充。
2. 编译 SWF 验证 Debug 不产生白块。
3. 检查 QuestList 实际 passenger bounds。
4. 移除重复 scale。
5. 重新验证 Compass UV 区域。

---

## 不应再修改的部分

- Palm Compass 本体。
- Compass 原始 UV atlas。
- dedicated panel 路径。

除非确认 Passenger 方案不可行，否则保持当前架构。

