#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameContext.hpp"
#include "Camera.hpp"
#include "PlayerShip.hpp"
#include "PlayerBullet.hpp"
#include "PlayerWeapon.hpp"
#include "Debris.hpp"

namespace glb
{
    class Game
    {
        public:
            int Run();
    };
}