#pragma once

#include <memory>

#include "GameObject.hpp"

namespace glb
{
    class EnemyWeapon : public GameObject
    {
        public:
            EnemyWeapon(const GameObject* const holder, const GameObject* const target);

            void update(GameContext& context, const sf::Time& elapsedTime);

        private:
            const GameObject* const holder;
            const GameObject* const target;
            const float fireRate = 2.f;
            float timeElapsedSinceLastFire = 0.f;

            void fire(GameContext& context, const float rotation);
    };
}
