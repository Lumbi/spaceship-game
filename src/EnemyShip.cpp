#include "EnemyShip.hpp"

glb::EnemyShip::EnemyShip()
    : GameObject(sf::Vector2f()),
      shape(sf::Vector2f(30.f, 30.f))
{
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2.f);
    shape.setOrigin(-shape.getSize() / 2.f);
}

void glb::EnemyShip::update(GameContext& context, const sf::Time& elapsedTime)
{

}

void glb::EnemyShip::draw(GameContext& context)
{
    shape.setPosition(position);
    context.window.draw(shape);
}
