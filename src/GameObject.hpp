#pragma once

#include <SFML/System.hpp>

#include "GameContext.hpp"

namespace glb 
{
    class GameObject
    {
        public:
            sf::Vector2f position;

            virtual void update(const GameContext& context, const sf::Time& elapsedTime) {};
            virtual void draw(const GameContext& context) {};
    };
}