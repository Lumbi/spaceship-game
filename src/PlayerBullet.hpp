#pragma once

#include "GameObject.hpp"
#include "Vector2Utility.hpp"

namespace glb
{
    class PlayerBullet: public GameObject
    {
        public:
            PlayerBullet(const float rotation);
            ~PlayerBullet();

            void update(const GameContext& context, const sf::Time& elapsedTime);
            void draw(const GameContext& context);

        private:
            sf::RectangleShape shape;
            const float rotation = 0;
            const float speed = 1000.f;
            const sf::Vector2f velocity;
    };
}