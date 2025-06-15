
cmake_minimum_required(VERSION 3.16)
project(2DGameEngine)

set(CMAKE_CXX_STANDARD 20)

# Set output directory (optional, but nice for structure)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
