cmake_minimum_required(VERSION 3.20)
project(anime_suika LANGUAGES C CXX)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.2
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(anime_suika
    src/main.cpp
)

target_link_libraries(anime_suika PRIVATE raylib)
target_compile_options(anime_suika PRIVATE -Wall -Wextra -Wpedantic)

if(MINGW)
    target_link_options(anime_suika PRIVATE -static-libgcc -static-libstdc++)
endif()

target_compile_features(anime_suika PRIVATE cxx_std_20)
set_target_properties(anime_suika PROPERTIES CXX_EXTENSIONS OFF)