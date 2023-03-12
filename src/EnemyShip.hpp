#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "GameObject.hpp"
#include "EnemyHitAnimation.hpp"
#include "EnemyDestroyAnimation.hpp"
#include "Vector2Utility.hpp"
#include "EnemyWeapon.hpp"
#include "PlayerBullet.hpp"

namespace glb
{
    class EnemyShip: public GameObject
    {
        public:
            EnemyShip();

            void start(GameContext& context);
            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);
            void collide(GameObject* const);

            void setFollowTarget(const GameObject* const);

        private:
            sf::RectangleShape shape;
            EnemyHitAnimation hitAnim;
            EnemyDestroyAnimation destroyAnim;
            const GameObject* followTarget;

            sf::Vector2f velocity;
            const float maxSpeed = 500.f;
            const float acceleration = 400.f;
            const float drag = 0.20f;
            int health = 100;

            bool isDead() const { return health <= 0; };

        private:
            void takeDamage(int damange);
    };
}