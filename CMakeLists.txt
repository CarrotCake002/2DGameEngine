cmake_minimum_required(VERSION 3.16)
project(CombatEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile warnings
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Set SFML path if needed (e.g., SFML_ROOT)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add your source files (recursive)
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(CombatEngine ${ENGINE_SOURCES})

target_include_directories(CombatEngine PRIVATE src)

target_link_libraries(CombatEngine PRIVATE sfml-graphics sfml-window sfml-system)
