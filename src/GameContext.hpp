#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <sstream>

#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "GameObject.hpp"
#include "BloomEffect.hpp"

namespace glb
{
    class GameContext
    {
        public:
            sf::RenderWindow& window;
            glb::Keyboard keyboard;
            glb::Mouse mouse;
            glb::BloomEffect bloomEffect;

            GameContext(sf::RenderWindow& window);

            void update(const sf::Time&);
            void draw();
            void draw(const sf::Drawable&);

            void setView(const sf::View&);
            sf::Vector2f toWorldPosition(const sf::Vector2i& windowPosition) const;

            void add(std::unique_ptr<GameObject>);

            void debugAppend(const std::string& string);
            void debugClear();

        private:
            std::vector<std::unique_ptr<GameObject>> gameObjects;
            std::vector<std::unique_ptr<GameObject>> gameObjectsToAdd;

            sf::RenderTexture render;

            sf::Font debugFont;
            sf::Text debugText;
            std::ostringstream debugStream;
    };
}
