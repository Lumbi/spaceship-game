#pragma once

#include <math.h>
#include <algorithm>

#include "GameObject.hpp"
#include "GameContext.hpp"
#include "Keyboard.hpp"
#include "Vector2Utility.hpp"

namespace glb
{
    class PlayerShip : public GameObject
    {
        public:
            float rotation = 0;
            const float angularVelocity = 180.f;
            sf::Vector2f velocity;
            const float maxSpeed = 500.f;
            const float acceleration = 400.f;
            const float drag = 0.20f;

            PlayerShip();
            ~PlayerShip();

            void update(const GameContext& context, const sf::Time& elapsedTime);
            void draw(const GameContext& context);

        private:
            sf::ConvexShape shape;
    };
}