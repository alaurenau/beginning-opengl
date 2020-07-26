# Beginning OpenGL Game Programming, Second Edition Source Code Rework

https://www.amazon.com/Beginning-OpenGL-Game-Programming-Second/dp/159863528X

Unofficial source code rework. Should be cross platform.

* CMake
* GLFW
* Dependencies as git submodules
* No platform dependencies
* No OpenGL code changes

Usage:

    git submodule init
    git submodule update
    mkdir build
    cd build
    cmake ..
    cmake --build .
    cd chapter_13/ogro_invasion/
    .ogro_invasion

Tested on:
* MinGW GCC 9.3.0
* MSVC 2019
* Ubuntu 20.04 GCC 9.3.0
