#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace glb
{
    class BloomShader: public sf::Shader
    {
        public:
            BloomShader();
            void setTexture(const sf::Texture& texture);
    };
}