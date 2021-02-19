#include "PlayerShip.hpp"

glb::PlayerShip::PlayerShip()
    : GameObject(sf::Vector2f(0.f, 0.f))
{
    float width = 20.0f;
    float height = 40.0f;
    shape = sf::ConvexShape(3);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::White);
    shape.setPoint(0, sf::Vector2f(- width / 2.0f, height / 2.0f));
    shape.setPoint(1, sf::Vector2f(0, - height / 2.0f));
    shape.setPoint(2, sf::Vector2f(width / 2.0f, height / 2.0f));
}

void glb::PlayerShip::update(GameContext& context, const sf::Time& elapsedTime)
{
    if (context.keyboard.isDown(sf::Keyboard::Left)) {
        rotation -= angularVelocity * elapsedTime.asSeconds();
    }

    if (context.keyboard.isDown(sf::Keyboard::Right)) {
        rotation += angularVelocity * elapsedTime.asSeconds();
    }

    if (context.keyboard.isDown(sf::Keyboard::Up))
    {
        position.x -= 1.0f * elapsedTime.asSeconds();
        sf::Vector2f direction = glb::Vector2::unit(rotation);
        velocity += direction * acceleration * elapsedTime.asSeconds();
    } else {
        velocity -= velocity * drag * elapsedTime.asSeconds();
    }
    glb::Vector2::clamp(velocity, 0.f, maxSpeed);
    position += velocity * elapsedTime.asSeconds();
}

void glb::PlayerShip::draw(GameContext& context)
{
    shape.setPosition(position);
    shape.setRotation(rotation);
    context.draw(shape);
}