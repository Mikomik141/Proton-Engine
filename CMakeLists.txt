cmake_minimum_required(VERSION 3.29)
project(Proton_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/Audio)
include_directories(include/Graphics)
include_directories(include/Physics)
include_directories(include/Gui)
include_directories(include/Gui/imgui)
include_directories(imgui/)
# Find and link GLAD
find_package(glad CONFIG REQUIRED)
# Find and link GLFW
find_package(glfw3 REQUIRED)

# Detect system architecture
if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    set(ARCH "x86_64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    set(ARCH "arm64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
    set(ARCH "arm")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86")
    set(ARCH "x86")
else()
    message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# Find and link FMOD
find_library(FMOD_LIBRARY NAMES fmod fmodL fmodstudio fmodstudioL PATHS ${CMAKE_SOURCE_DIR}/api/core/lib/${ARCH})

if(NOT FMOD_LIBRARY)
    message(FATAL_ERROR "FMOD library not found. Please check the path.")
endif()

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
        include/Audio/fmod_output.h
        include/Gui/imgui.h
        include/Gui/imgui_impl_glfw.h
        include/Gui/imgui_impl_opengl3.h
        src/Gui/imgui.cpp
        src/Gui/imgui_draw.cpp
        src/Gui/imgui_impl_glfw.cpp
        src/Gui/imgui_impl_opengl3.cpp
        src/Gui/imgui_tables.cpp
        src/Gui/imgui_widgets.cpp)

# Link the necessary libraries
target_link_libraries(Proton_Engine PRIVATE glad::glad glfw ${FMOD_LIBRARY})