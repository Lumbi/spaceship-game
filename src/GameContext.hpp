#pragma once

#include <SFML/Graphics.hpp>

#include "Keyboard.hpp"

namespace glb
{
    class GameContext 
    {
        public:
            sf::RenderWindow& window;
            glb::Keyboard keyboard;

            GameContext(sf::RenderWindow& window);
            ~GameContext();
    };
}
