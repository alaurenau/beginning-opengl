# Beginning OpenGL Game Programming, Second Edition Source Code Rework

https://www.amazon.com/Beginning-OpenGL-Game-Programming-Second/dp/159863528X

Unofficial source code rework. Should be cross platform.

* CMake
* GLFW
* Dependencies as git submodules
* No platform dependencies
* No OpneGL code changes

Usage:

    git submodule init
    git submodule update
    mkdir build
    cd build
    cmake ..
    make ogro_invasion
    cp -r ../chapter_13/ogro_invasion/data ./chapter_13/ogro_invasion/data 
    cd ./chapter_13/ogro_invasion/
    ./chapter_13/ogro_invasion/

Tested on:
* MinGW GCC
* MSVC
* Ubuntu 20.04 GCC
