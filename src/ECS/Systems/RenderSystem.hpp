#pragma once

#include <SFML/Graphics.hpp>

class RenderSystem {
public:
    RenderSystem() = default;

    void render(sf::RenderSystem &window, EntityManager &entities) {
        for (const auto &entity : entities.getEntitiesWithComponents<Sprite, Position>()) {
            auto &sprite = entity.getComponent<Sprite>(entity);
            auto &position = entity.getComponent<Position>(entity);

            sprite.sprite.setPosition(position.x, position.y);
            window.draw(sprite.sprite);
        }
        
    }
}