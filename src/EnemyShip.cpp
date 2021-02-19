#include "EnemyShip.hpp"

glb::EnemyShip::EnemyShip()
    : GameObject(sf::Vector2f()),
      shape(sf::Vector2f(40.f, 40.f)),
      hitAnim(shape)
{
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2.f);
    shape.setOrigin(shape.getSize() / 2.f);

    collider = std::make_unique<ShapeCollider>(shape);
}

void glb::EnemyShip::update(GameContext& context, const sf::Time& elapsedTime)
{
    hitAnim.animate(elapsedTime);
}

void glb::EnemyShip::collide(GameObject* const other)
{
    hitAnim.play();
}

void glb::EnemyShip::draw(GameContext& context)
{
    shape.setPosition(position);
    context.draw(shape);
}
