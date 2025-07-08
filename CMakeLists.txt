cmake_minimum_required(VERSION 3.16)

# Automatically use vcpkg toolchain if VCPKG_ROOT is set
if (DEFINED ENV{VCPKG_ROOT})
    message(STATUS "Using vcpkg from: $ENV{VCPKG_ROOT}")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(SpriteFoundry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# ---------------------------
# Dependencies (via vcpkg)
# ---------------------------
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# ---------------------------
# Dexium2D Subproject
# ---------------------------
file(GLOB_RECURSE DEXIUM_SRC
    external/Dexium2D/src/*.cpp
)
file(GLOB_RECURSE DEXIUM_HDR
    external/Dexium2D/include/*.hpp
    external/Dexium2D/include/*.inl
)

add_library(Dexium2D STATIC ${DEXIUM_SRC} ${DEXIUM_HDR})

target_include_directories(Dexium2D PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/Dexium2D/include
    ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include          # ✅ Add vcpkg include root
)

source_group("Dexium2D\\Source" FILES ${DEXIUM_SRC})
source_group("Dexium2D\\Include" FILES ${DEXIUM_HDR})
set_target_properties(Dexium2D PROPERTIES FOLDER "Dexium2D")

# ---------------------------
# ImGui (Manual integration)
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
file(GLOB_RECURSE SF_HDR include/*.hpp include/*.inl)

add_executable(SpriteFoundryEditor
    ${SF_SRC}
    ${SF_HDR}
    ${IMGUI_SRC}
    ${IMGUI_HDR}
)

target_include_directories(SpriteFoundryEditor PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends
)

target_link_libraries(SpriteFoundryEditor
    Dexium2D
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_image::SDL2_image
    nlohmann_json::nlohmann_json
)

# ---------------------------
# Visual Studio Filters
# ---------------------------
source_group("SpriteFoundry\\Source" FILES ${SF_SRC})
source_group("SpriteFoundry\\Include" FILES ${SF_HDR})
source_group("ImGui\\Source" FILES ${IMGUI_SRC})
source_group("ImGui\\Header" FILES ${IMGUI_HDR})

set_target_properties(SpriteFoundryEditor PROPERTIES FOLDER "SpriteFoundry")
