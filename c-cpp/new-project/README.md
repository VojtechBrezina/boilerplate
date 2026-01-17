# A C++ project template

## How to use

1. Copy everything (except the README) to a new directory.
2. Replace `%project_name%` with the project name in `CMakeLists.txt`
3. Replace `%target_name%` with the name of the executable in both
   `CMakeLists.txt` and `Justfile`
4. Run `just run` in the terminal to see a `Hello World!` and get the
   compilation database generated.

## What's in here

- A basic CMake configuration.
    - Precompiled headers.
    - Standard set to C++23.
    - No `CMakePresets.json` here. I find them annoying.
- A simple `just` configuration for development on linux with GCC/Clang and some
basic automation.
    - `Ninja Multi-Config` set as the generator to have both configurations in
    the same place.
    - The compilation database is enabled.
    - Some compiler specific flags for the configuration. The defaults are
    mostly OK, but I like to set them explicitly.
        - Includes `-fdiagnostics-color=always` because Ninja has issues
        otherwise.
    - The following actions:
        - `reconfigure` to discard the build directory and reconfigure CMake
        fresh.
        - `build <config>` to buld one of the configurations explicitly.
        - `run` and `run-rel` to directly run the executable in debug or release
          mode. (The project is autmatically rebuilt and any arguments are
        passed on to the executable.)
- A simple `.gitignore` with the build directory and clangd cache.
- A clangd config to detect the compilation database correctly.

## Software requirements

- [clangd](https://clangd.llvm.org/)
- [CMake](https://cmake.org/documentation/)
- [`just`](https://just.systems/man/en/)
- [Ninja](https://ninja-build.org/)
- This project is designed for a Linux system with a compiler that follows the
GCC interface (Clang is fine) and supports C++23.
    - The `CMakeLists.txt` by itself should be portable, platform specific
    options are in the `Justfile`.

## TODO

- Look into cross-compilation.
