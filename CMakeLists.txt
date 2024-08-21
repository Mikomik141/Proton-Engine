cmake_minimum_required(VERSION 3.29)
project(Proton_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Proton_Engine
        src/Game/Game.cpp
        include/Audio/AudioEngine.h
        include/Graphics/Renderer.h
        src/Audio/AudioEngine.cpp
        include/Physics/PhysicsEngine.h
        include/Game/Game.h
        src/Physics/PhysicsEngine.cpp
        src/Graphics/Renderer.cpp)
