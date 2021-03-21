#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "GameObject.hpp"

namespace glb
{
    class EnemyBullet: public GameObject
    {
        public:
            EnemyBullet(const sf::Vector2f& position, const float rotation);

            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);
            void collide(GameObject* const);

        private:
            sf::RectangleShape shape;
            float rotation = 0;
            const float speed = 400.f;
            sf::Vector2f velocity;
            float ttl = 3.f;
    };
}