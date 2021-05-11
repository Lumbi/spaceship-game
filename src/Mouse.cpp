#include "Mouse.hpp"
#include "GameContext.hpp"

sf::Vector2f glb::Mouse::getWorldPosition() const
{
    sf::Vector2i windowPosition = sf::Mouse::getPosition(context.window);
    return context.toWorldPosition(windowPosition);
}

bool glb::Mouse::isLeftButtonDown() const
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
