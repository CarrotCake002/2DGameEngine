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

            // === Add a component ===
        template <typename Component, typename... Args>
        void addComponent(Entity entity, Args&&... args) {
            auto& componentMap = components[std::type_index(typeid(Component))];
            componentMap[entity] = std::make_shared<Component>(std::forward<Args>(args)...);
        }

        // === Get a component ===
        template <typename Component>
        Component& getComponent(Entity entity) {
            auto& componentMap = components[std::type_index(typeid(Component))];
            return *std::static_pointer_cast<Component>(componentMap.at(entity));
        }
};