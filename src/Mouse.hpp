#pragma once

#include <SFML/Window.hpp>

namespace glb
{
    class GameContext;
    class Mouse
    {
        public:
            Mouse(const GameContext& context): context(context) {}

            sf::Vector2f getWorldPosition() const;
            bool isLeftButtonDown() const;

        private:
            const GameContext& context;
    };
}