# ImGui Toolkit

A blueprint-friendly Dear ImGui integration for Unreal Engine.

⚠️ This plugin is still very early in development.

⚠️ This is the "project-version", it comes with an Unreal Engine 5.7.0 project and a few examples how to use the ImGuiToolkit plugin.

The goal of ImGuiToolkit is to make creating Dear ImGui interfaces for runtime debugging and editor tools in Unreal Engine as simple as possible.
It provides seamless integration between Unreal and Dear ImGui through easily bindable delegates in both C++ and Blueprint, and it automatically handles common type conversions for you (for example: FText ↔ const char*, FLinearColor ↔ ImVec4, and so on).

ℹ️ Note: ImGuiToolkit gives you full access to Dear ImGui’s capabilities in C++. In Blueprints, it offers a streamlined subset designed to help you build UIs faster and with fewer necessary decisions.

🧩 **Attribution:** ImGuiToolkit builds upon and includes code from the following open-source projects:

- [**Dear ImGui (1.91.8)**](https://github.com/ocornut/imgui) by **ocornut**
- [**ImGui Unreal Engine Plugin**](https://github.com/VesCodes/ImGui) by **VesCodes**
- [**ImPlot**](https://github.com/epezent/implot) by **epezent**
- [**NetImgui**](https://github.com/sammyfreg/netImgui) by **sammyfreg**

## Example of ImGui Toolkit in Action

![Screenshot_01](Screenshots/ImGuiToolkit_InAction_01.png)
![Screenshot_01](Screenshots/ImGuiToolkit_InAction_02.png)

## Status Quo

### Containers

- [x] Window
- [x] Collapsing Header
- [x] TabBar
- [x] Tree
- [x] Menu Bar

### Layout

- [x] Align Text To Frame Padding
- [x] Dummy
- [x] Indent / Unindent
- [x] New Line
- [x] Same Line
- [x] Separator
- [x] Spacing

### Text

- [x] Text
- [x] Bullet Text
- [x] Label Text
- [x] Separator Text
- [x] Text Colored
- [x] Text Disabled
- [x] Text Wrapped
- [x] Text Link Open URL

### Main

- [x] Arrow Button
- [x] Checkbox
- [x] Button
- [x] Radio Button Group
- [x] Small Button
- [x] Combo Box
- [x] Begin Combo
- [x] Progress Bar
- [x] Bullet
- [x] Begin Disabled
- [x] End Disabled
- [x] Push Style Color
- [x] Pop Style Color
- [x] Push Style Var
- [x] Pop Style Var
- [x] Set Item Tooltip
- [x] Begin/End Tooltip
- [x] Popup
- [x] Table
- [x] Help Marker

### Images

- [x] Image
- [x] Image Button
- [x] Material Image
- [x] Material Image Button

### Sliders

- [x] Drag Float
- [x] Drag Vector2D
- [x] Drag Vector
- [x] Drag Vector4
- [x] Drag Int
- [x] Drag Int Point
- [x] Drag Int Vector
- [x] Drag Int Vector4
- [x] Slider Float
- [x] Slider Vector2D
- [x] Slider Vector
- [x] Slider Vector4
- [x] Slider Angle
- [x] Slider Int
- [x] Vertical Slider Float
- [x] Vertical Slider Int

### Input with Keyboard

- [x] Input Text
- [x] Input Text With Hint
- [x] Input Text Multiline
- [x] Input Float
- [x] Input Double
- [x] Input Vector2D
- [x] Input Vector
- [x] Input Vector4
- [x] Input Int
- [x] Input Int2
- [x] Input Int3
- [x] Input Int4

### Color Editor/Pickers

- [x] Color Edit
- [x] Color Picker
- [x] Color Button

### ImPlot

- [x] Begin Plot
- [x] Begin Subplots
- [x] Setup Axis
- [x] Setup Axis Limits
- [x] Setup Axes / Axes Limits / Axis Ticks / Axis Constraints
- [x] Setup Legend / Mouse Text / Axis Format / Axis Scale / Setup Finish
- [x] Set Next Axis Limits / Axes Limits / Fit Helpers / Axis Selection / Hide Next Item
- [x] Plot Queries / Axis Queries / Cancel Selection
- [x] Plot Line
- [x] Plot Line XY
- [x] Plot Scatter
- [x] Plot Scatter XY
- [x] Plot Bars
- [x] Plot Bars XY
- [x] Plot Bar Groups
- [x] Plot Stairs / Shaded / Error Bars / Stems / Infinite Lines
- [x] Plot Pie Chart / Heatmap / Histogram / Histogram2D / Digital
- [x] Plot Image / Material Image / Text / Dummy
- [x] Drag Point / Drag Line / Drag Rect
- [x] Annotation / Tag X / Tag Y
- [x] Plot Style Color / Plot Style Var / Style Presets / Next Item Style / Colormap
- [x] Plot Item Flags

### Selectables

- [x] Selectable
- [x] Multi Selectable

### Settings / Backend

- [x] Plugin settings
- [x] Runtime and editor-hosted style settings
- [x] Docking support
- [x] ImPlot backend context support
- [x] NetImgui backend integration

## Other TODOs

- [x] ImGui windows should not always be rendered on top of Slate windows
- [x] ImGui windows behind slate windows should not "steal" input
- [x] Get copy+paste to work for InputText / InputTextMultiline
- [x] Finish the ImGui Host EditorUtility Widget visibility behavior
- [ ] Create useful real-world examples (one runtime and one editor tool)
- [ ] Add Blueprint-friendly ImPlot example
- [x] Add Blueprint-friendly table wrappers
- [x] Add Blueprint-friendly color editor/picker wrappers

## Blueprint Usage Notes

ImGuiToolkit Blueprint nodes create persistent wrapper objects. The execution pins decide when the wrapper is created or updated, while the returned `Container` or `Element` object is the thing you keep wiring into other nodes.

### Containers

Nodes that return `Container` can own child elements. Wire child nodes to the returned container, not to the original parent window, when you want those children to appear inside the container.

Some containers are conditional. Popups, combos, plots, tables, tab items, tree nodes, and collapsing headers only render their children while they are open or active.

Blueprint shape:

```text
Window
Begin Combo / Begin Popup / Begin Table / Begin Plot
  Child Element
  Child Element
```

Common mistake:

```text
Window
Begin Popup
Text wired to Window instead of the popup Container
```

The text is then not part of the popup. It may appear outside the popup, or it may run at a time where the popup is not active.

### Popups

Opening a popup and drawing a popup are separate steps. `Open Popup` requests that a popup should open. `Begin Popup` defines the popup contents.

Recommended shape:

```text
Button "Open Popup"
  On Clicked -> Open Popup "MyPopup"

Begin Popup "MyPopup"
  Text "Popup content"
  Button "Close"
    On Clicked -> Close Current Popup
```

For simple button-triggered popups, prefer the dedicated popup button wrapper. It keeps the trigger and popup container together and avoids most accidental reopen behavior.

For context popups, make sure the context popup is attached to the item you want to right-click. `Close Current Popup` closes the currently active popup, but it does not disable the trigger that opened it. If the same mouse interaction is still opening the context popup every frame, the popup can appear to close and immediately reopen.

### Combo Boxes

`Begin Combo` is best for compact choice lists. The usual children are selectable items, text, small buttons, or other lightweight controls.

Recommended shape:

```text
Begin Combo "Mode"
  Selectable "A"
    On Selected -> Set Mode A
  Selectable "B"
    On Selected -> Set Mode B
```

Complex interactive widgets can be visible inside a combo, but Dear ImGui combos are not a great fit for rich tool panels. Sliders, drags, color pickers, and nested popups can have awkward focus or closing behavior. Use a popup or window when the content needs more interaction.

### Tables

Table setup should happen before table content. Define columns first, optionally draw a header row, then add rows and columns in order.

Recommended shape:

```text
Begin Table
  Table Setup Column "Name"
  Table Setup Column "Value"
  Table Headers Row

  Table Next Row
  Table Set Column Index 0
  Text "Speed"
  Table Set Column Index 1
  Drag Float
```

Common mistakes are adding content before the columns are set up, forgetting `Table Next Row`, or wiring row contents to the parent window instead of the table container.

### Images

Use the image wrappers for Unreal assets instead of manually converting texture IDs. `Image` and `Image Button` are for `Texture2D` assets. `Material Image` and `Material Image Button` are for material assets or material instances.

`Size` controls the displayed size in ImGui units. Use an explicit size when layout should be stable.

`UV0` and `UV1` are normalized texture coordinates:

```text
UV0 = (0, 0)
UV1 = (1, 1)
```

That displays the full texture. Change the UV values to crop or flip the image. For example, swapping the Y values can flip vertically depending on the texture/material setup.

For ImPlot image nodes, the bounds are plot coordinates, not pixel size.

### Style Scopes

Style nodes are stack-based. Every push must have a matching pop on the same render path.

Recommended shape:

```text
Push Style Color
Button / Text / Child Elements
Pop Style Color
```

```text
Push Style Var
Begin Disabled / Child Elements / Button
Pop Style Var
```

Keep push and pop nodes close together in the Blueprint graph. A missing pop can trigger Dear ImGui assertions such as `Missing PopStyleVar()`. A pop that runs without the matching push can also break the style stack.
