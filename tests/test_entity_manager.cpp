    #define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/ECS/EntityManager.hpp"

TEST_CASE("Entity creation works") {
    EntityManager manager;
    auto e1 = manager.createEntity();
    auto e2 = manager.createEntity();
    REQUIRE(e1 != e2);
    REQUIRE(e2 == e1 + 1);
}

TEST_CASE("Add and get component") {
    EntityManager manager;
    auto e = manager.createEntity();
    manager.addComponent<int>(e, 42);
    REQUIRE(manager.getComponent<int>(e) == 42);
}
