#pragma once

#include "GameContext.hpp"
#include "GameObject.hpp"

namespace glb
{
    class PlayerShip;
    class EnemyShip;
    class Debris;
    class Collider;

    class PlayerBullet: public GameObject
    {
        public:
            PlayerBullet(const PlayerShip&);

            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);
            void collide(GameObject* const);

        private:
            sf::RectangleShape shape;
            float rotation = 0;
            const float speed = 1400.f;
            sf::Vector2f velocity;
            float ttl = 0.5f;
            const float maxTtl = 2.f;

            void collide(EnemyShip* const);
            void collide(Debris* const);
    };
}
