cmake_minimum_required(VERSION 3.10)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 17)

# Automatically grab ALL .cpp in src/
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Make the engine library
add_library(2DGameEngineLib ${ENGINE_SOURCES})

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Link SFML to the library
target_link_libraries(2DGameEngineLib sfml-graphics sfml-window sfml-system)

# Main executable (optional)
add_executable(2DGameEngine src/main.cpp)
target_link_libraries(2DGameEngine 2DGameEngineLib)

# Tests
enable_testing()
add_subdirectory(tests)
