#include "PlayerBullet.hpp"

glb::PlayerBullet::PlayerBullet(float rotation)
    : 
    rotation(rotation),
    velocity(glb::Vector2::unit(rotation) * speed)
{
    float width = 4.f;
    float height = 20.f;
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setRotation(rotation);
    shape.setFillColor(sf::Color::White);
}

glb::PlayerBullet::~PlayerBullet() {}

void glb::PlayerBullet::update(const GameContext& context, const sf::Time& elapsedTime)
{
    position += velocity * elapsedTime.asSeconds();
}

void glb::PlayerBullet::draw(const GameContext& context)
{
    shape.setPosition(position);
    context.window.draw(shape);
}