#pragma once

#include "GameContext.hpp"
#include "GameObject.hpp"
#include "PlayerShip.hpp"
#include "Vector2Utility.hpp"

namespace glb
{
    class PlayerBullet: public GameObject
    {
        public:
            PlayerBullet(const PlayerShip&);

            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);

        private:
            sf::RectangleShape shape;
            const float rotation = 0;
            const float speed = 1400.f;
            const sf::Vector2f velocity;
    };
}
