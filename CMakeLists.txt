cmake_minimum_required(VERSION 3.29)
project(Proton_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/Audio)
include_directories(include/Graphics)
include_directories(include/Physics)
find_package(glad CONFIG REQUIRED)

add_executable(Proton_Engine
        src/Game/Game.cpp
        include/Audio/AudioEngine.h
        include/Graphics/Renderer.h
        src/Audio/AudioEngine.cpp
        include/Physics/PhysicsEngine.h
        include/Game/Game.h
        src/Physics/PhysicsEngine.cpp
        src/Graphics/Renderer.cpp
        include/Audio/fmod.h
        include/Audio/fmod.hpp
        include/Audio/fmod_errors.h
        include/Audio/fmod_output.h)

target_link_libraries(Proton_Engine PRIVATE glad::glad)