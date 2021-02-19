#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace glb
{
    class BloomEffect
    {
        public:
            BloomEffect(sf::RenderTarget& target);
            void render(const sf::Texture& texture);

        private:
            sf::RenderTarget& renderTarget;
            sf::Shader blurShader;
            sf::Shader combineShader;
            sf::RenderTexture pingpong[2];
    };
}