# 01PROJTEMP

This file is intended to show the developer various options for the build process

## docs

Doxygen is required for documentation. And is automatically run by `make` when using either `dev_build` or `docs` targets.
`doxygen Doxyfile` will also create documentation

## run-tests

ctest is the CMake tester. And is automatically run by `make` when using the `dev_build` target.
`ctest` when run from the `build/` directory will also run the generated tests if they have been generated

## 01PROJCMD

01PROJCMD is the regular executable. And is automatically run by `make` when using either `dev_build` or `01PROJCMD` targets.

## dev_build

dev_build builds all targets

## Debug

`cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug`
