# Changelog for C-Template
All notable changes to my C Template Generator will be documented here.

---

## [0.1.0] - 2026-01-10
### Added
- Initial project structure
- CMake build system
- Formatting target (`clang-format`)
- Doxygen support
- CONTRIBUTING guide

## [1.0.0] - 2026-01-11
### Added
- Add in various Project Variables
- Tested with ninja
- Create `template-config.sh` for faster template renaming

## [1.1.0] - 2026-01-11
### Added
- Fix license separation
- Run ninja and make and tests the output

## [1.2.0] - 2026-01-11
### Added
- Automate the naming of proj_upper to replace spaces with underscore and remove special characters and move to upper case
- Validate input

---

## Planned for [1.3+]
### To Do
- Add basic unit tests to the C files
- Add a debug target
- Integrate `version.h` into build output and into github possibly
- Test with meson-buid

