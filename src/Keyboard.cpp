#include "Keyboard.hpp"

bool glb::Keyboard::isDown(sf::Keyboard::Key key) const
{
    auto result = state.find(key);
    if (result != state.end()) {
        return result->second;
    } else {
        return false;
    }
}

void glb::Keyboard::update(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            state[event.key.code] = true;
            break;
        case sf::Event::KeyReleased:
            state[event.key.code] = false;
            break;
        default:
            break;
    }
}
