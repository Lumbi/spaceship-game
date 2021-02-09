#pragma once

#include <math.h>

#include "GameObject.hpp"
#include "GameContext.hpp"
#include "Keyboard.hpp"

namespace glb
{
    class PlayerShip : public GameObject
    {
        public:
            float rotation = 0;

            PlayerShip();
            ~PlayerShip();

            void update(const GameContext& context, const sf::Time& elapsedTime);
            void draw(const GameContext& context);

        private:
            sf::ConvexShape shape;
    };
}