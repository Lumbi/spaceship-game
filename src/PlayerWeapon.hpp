#pragma once

#include <memory>

#include "GameObject.hpp"
#include "PlayerShip.hpp"
#include "PlayerBullet.hpp"

namespace glb
{
    class PlayerWeapon : public GameObject
    {
        public:
            PlayerWeapon(const PlayerShip&);

            void update(GameContext& context, const sf::Time& elapsedTime);

        private:
            const PlayerShip& playerShip;
            const float fireRate = 8.f;
            float timeElapsedSinceLastFire = 0.f;

            void fire(GameContext& context);
    };
}
