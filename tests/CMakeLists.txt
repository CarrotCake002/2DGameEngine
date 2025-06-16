add_executable(UnitTests
    test_entity_manager.cpp
)

# Include Catch2
target_include_directories(UnitTests PRIVATE ../external/Catch2)

# Link your engine lib (which now links SFML too!)
target_link_libraries(UnitTests 2DGameEngineLib)

# Register with CTest
add_test(NAME AllTests COMMAND UnitTests)
