#pragma once

#include <SFML/Graphics.hpp>

namespace glb
{
    class ShapeSprite: public sf::Sprite
    {
        public:
            void setShape(const sf::Shape& shape);

        private:
            sf::RenderTexture render;
    };
}