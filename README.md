# ImGui Toolkit

A blueprint-friendly Dear ImGui integration for Unreal Engine.

⚠️ This plugin is still very early in development.

⚠️ This is the "project-version", it comes with an Unreal Engine 5.7.0 project and a few examples how to use the ImGuiToolkit plugin.

The goal of ImGuiToolkit is to make it very easy to create Dear ImGui UIs for runtime debug and editor tools in Unreal Engine.
It ensures seamless interoperability between Unreal and Dear ImGui by providing delegates you can bind to in C++ or Blueprint,
and it also takes care of typical variable type conversions for you (e.g. FText - const char*, FLinearColor - ImVec4, etc.)

ℹ️️ **Note:** ImGui Toolkit exposes the full power of Dear ImGui in C++. In Blueprints, it offers a curated subset focused on common workflows, so you can build debug and editor tool UIs faster with fewer decisions.

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
- [x] Text Link Open URL (gets displayed as a link, but doesnt open the browser)

### Main

- [x] Arrow Button
- [x] Checkbox
- [x] Button
- [x] Radio Button Group
- [x] Small Button
- [x] Combo Box
- [x] Progress Bar
- [x] Bullet
- [x] Set Item Tooltip
- [ ] Begin/End Tooltip
- [ ] Popup
- [ ] Table
- [x] Help Marker

### Images

- [ ] Image
- [ ] Image Button

### Sliders

- [x] Drag Float
- [x] Drag Int
- [x] Slider Float
- [x] Slider Int

### Input with Keyboard

- [x] Input Text
- [x] Input Text Multiline
- [x] Input Float
- [x] Input Int

### Color Editor/Pickers

- [ ] Color Edit
- [ ] Color Picker
- [ ] Color Button

### Selectables

- [ ] Selectable
- [ ] Multi Selectable

## Other TODOs

- [ ] ImGui windows should not always be rendered on top of Slate windows
- [ ] ImGui windows behind slate windows should not "steal" input
- [ ] Get copy+paste to work (InputText and others)
- [ ] Finish the ImGui Host EditorUtility Widget (ImGui window should also only be rendered when the host window is visible)
- [ ] Create useful real-world examples (one runtime and one editor tool)
- [ ] Add ImPlot support (with example)
- [ ] Add PluginSettings and expose properties like "Scale" and maybe even some style settings