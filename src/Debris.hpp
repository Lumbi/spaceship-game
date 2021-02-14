#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "GameObject.hpp"

namespace glb
{
    class Debris: public GameObject
    {
        public:
            Debris(const sf::Vector2f& position);

            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);

        private:
            sf::ConvexShape shape;
    };
}