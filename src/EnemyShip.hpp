#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "GameObject.hpp"

namespace glb
{
    class EnemyShip: public GameObject
    {
        public:
            EnemyShip();

            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);

        private:
            sf::RectangleShape shape;
    };
}