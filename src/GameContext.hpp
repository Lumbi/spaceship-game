#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Keyboard.hpp"
#include "GameObject.hpp"
#include "BloomEffect.hpp"

namespace glb
{
    class GameContext
    {
        public:
            sf::RenderWindow& window;
            glb::Keyboard keyboard;
            glb::BloomEffect bloomEffect;

            GameContext(sf::RenderWindow& window);

            void update(const sf::Time&);
            void draw();
            void draw(const sf::Drawable&);

            void setView(const sf::View&);

            void add(std::unique_ptr<GameObject>);

        private:
            std::vector<std::unique_ptr<GameObject>> gameObjects;
            std::vector<std::unique_ptr<GameObject>> gameObjectsToAdd;

            sf::RenderTexture render;
    };
}
