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
    updateControls(context, elapsedTime);
    glb::Vector2::clamp(velocity, 0.f, maxSpeed);
    position += velocity * elapsedTime.asSeconds();
}

void glb::PlayerShip::updateControls(GameContext& context, const sf::Time& elapsedTime)
{
    // Update rotation
    sf::Vector2f mousePosition = context.mouse.getWorldPosition();
    sf::Vector2f vectorToMouse = mousePosition - position;
    rotation = glb::Vector2::angle(vectorToMouse);

    // Update velocity
    bool isMoving = false;
    sf::Vector2f direction = glb::Vector2::zero<float>;
    if (context.keyboard.isDown(sf::Keyboard::W))
    {
        isMoving = true;
        direction += glb::Vector2::up<float>;
    }
    if (context.keyboard.isDown(sf::Keyboard::S))
    {
        isMoving = true;
        direction += glb::Vector2::down<float>;
    }
    if (context.keyboard.isDown(sf::Keyboard::A))
    {
        isMoving = true;
        direction += glb::Vector2::left<float>;
    }
    if (context.keyboard.isDown(sf::Keyboard::D))
    {
        isMoving = true;
        direction += glb::Vector2::right<float>;
    }

    if (isMoving) {
        velocity += direction * acceleration * elapsedTime.asSeconds();
    } else {
        velocity -= velocity * drag * elapsedTime.asSeconds();
    }
}

void glb::PlayerShip::draw(GameContext& context)
{
    shape.setPosition(position);
    shape.setRotation(rotation);
    context.draw(shape);
}