#include "Debris.hpp"

sf::ConvexShape createRandomShape()
{
    // TODO: Make more random
    sf::ConvexShape shape;
    shape.setPointCount(5);
    shape.setFillColor(sf::Color::White);
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPoint(1, sf::Vector2f(150, 10));
    shape.setPoint(2, sf::Vector2f(120, 90));
    shape.setPoint(3, sf::Vector2f(30, 100));
    shape.setPoint(4, sf::Vector2f(0, 50));
    shape.setOrigin(75.f, 50.f);
    return shape;
}

glb::Debris::Debris(const sf::Vector2f& position):
    GameObject(position)
{
    collider = std::make_unique<ShapeCollider>(shape);
    shape = createRandomShape();
}

void glb::Debris::update(GameContext& context, const sf::Time& elapsed)
{
    shape.setPosition(position);
}

void glb::Debris::draw(GameContext& context)
{
    shape.setPosition(position);
    context.draw(shape);
}
