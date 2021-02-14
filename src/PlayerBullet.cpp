#include "PlayerBullet.hpp"

glb::PlayerBullet::PlayerBullet(const PlayerShip& playerShip)
    :
    GameObject(playerShip.position),
    rotation(playerShip.rotation),
    velocity(glb::Vector2::unit(playerShip.rotation) * speed)
{
    collider = std::make_unique<PointCollider>(position);

    float width = 4.f;
    float height = 20.f;
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setRotation(rotation);
    shape.setFillColor(sf::Color::White);
}

void glb::PlayerBullet::update(GameContext& context, const sf::Time& elapsedTime)
{
    ttl -= elapsedTime.asSeconds();
    if (ttl <= 0) { kill(); return; }

    position += velocity * elapsedTime.asSeconds();
}

void glb::PlayerBullet::collide(const GameObject& other)
{
    kill();
}

void glb::PlayerBullet::draw(GameContext& context)
{
    shape.setPosition(position);
    context.window.draw(shape);
}