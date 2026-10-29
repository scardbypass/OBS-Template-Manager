# Native OBS dock prototype (v0.1.0)

This is an **uncompiled UI prototype**, not a usable template installer.

It registers a dock panel containing Library, My Templates, Creator and Backup tabs. Buttons intentionally display a "not implemented" message and **do not modify OBS configuration**.

## Build requirements
- OBS Studio SDK/build environment compatible with the target OBS version
- CMake >= 3.24
- C++17 compiler (MSVC on Windows)
- Qt 6 Widgets matching the OBS build
- libobs and obs-frontend-api CMake package targets

Configure the plugin within a compatible OBS plugin build environment, then compile using CMake. CMake target names and SDK paths must be validated against the selected OBS release.

## Testing checklist
- [ ] Windows 10 x64 load
- [ ] Windows 11 x64 load
- [ ] Dock appears under OBS Docks
- [ ] No config mutation
- [ ] Plugin unload/restart
- [ ] OBS release API compatibility

**Do not distribute this as a finished plugin until compiled and tested.**
