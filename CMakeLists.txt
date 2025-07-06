cmake_minimum_required(VERSION 3.16)
project(SpriteFoundry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---------------------------
# Dependencies (vcpkg)
# ---------------------------
find_package(SDL2 REQUIRED)
find_package(nlohmann_json REQUIRED)

# ---------------------------
# Dexium2D Subproject
# ---------------------------
file(GLOB_RECURSE DEXIUM_SRC
    external/Dexium2D/src/*.cpp
)
file(GLOB_RECURSE DEXIUM_HDR
    external/Dexium2D/include/*.hpp
)

add_library(Dexium2D STATIC ${DEXIUM_SRC} ${DEXIUM_HDR})
target_include_directories(Dexium2D PUBLIC external/Dexium2D/include)

# Visual Studio Filters
source_group("Dexium2D\\Source" FILES ${DEXIUM_SRC})
source_group("Dexium2D\\Include" FILES ${DEXIUM_HDR})
set_target_properties(Dexium2D PROPERTIES FOLDER "Dexium2D")

# ---------------------------
# ImGui Files (built-in)
# ---------------------------
file(GLOB IMGUI_SRC
    external/imgui/*.cpp
    external/imgui/backends/imgui_impl_sdl2.cpp
)
file(GLOB IMGUI_HDR
    external/imgui/*.h
    external/imgui/backends/imgui_impl_sdl2.h
)

# ---------------------------
# SpriteFoundry Project
# ---------------------------
file(GLOB_RECURSE SF_SRC src/*.cpp)
file(GLOB_RECURSE SF_HDR include/*.hpp)

add_executable(SpriteFoundryEditor
    ${SF_SRC}
    ${SF_HDR}
    ${IMGUI_SRC}
    ${IMGUI_HDR}
)

target_include_directories(SpriteFoundryEditor PUBLIC
    include
    external/imgui
    external/imgui/backends
)

target_link_libraries(SpriteFoundryEditor
    Dexium2D
    SDL2::SDL2
    nlohmann_json::nlohmann_json
)

# Visual Studio Filters for SpriteFoundry
source_group("SpriteFoundry\\Source" FILES ${SF_SRC})
source_group("SpriteFoundry\\Include" FILES ${SF_HDR})
source_group("ImGui\\Source" FILES ${IMGUI_SRC})
source_group("ImGui\\Header" FILES ${IMGUI_HDR})
set_target_properties(SpriteFoundryEditor PROPERTIES FOLDER "SpriteFoundry")
