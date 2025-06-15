#pragma once

#include <cstdint>
#include <unordered_map>
#include <typeindex>

class EntityManager {
public:
    EntityManager() = default;

    public:
        using Entity = uint32_t;
    
    private:
        Entity nextEntityId = 0;

        std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<void>>> components;
    
    public:
        Entity createEntity() {
            return nextEntityId++;
        }
}