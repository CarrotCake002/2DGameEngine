cmake_minimum_required(VERSION 3.10)
project(2DGameEngine)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory (optional, but nice for structure)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include all source files from src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Add executable target
add_executable(2DGameEngine ${SOURCES})

# Add include directory
target_include_directories(2DGameEngine PRIVATE include)
