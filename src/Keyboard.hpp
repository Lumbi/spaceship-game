#pragma once

#include <SFML/Window.hpp>
#include <map>

namespace glb 
{
    class Keyboard
    {
        public:
            bool isDown(sf::Keyboard::Key key) const;
            void update(const sf::Event& event);

        private:
            std::map<sf::Keyboard::Key, bool> state;
    };
}
