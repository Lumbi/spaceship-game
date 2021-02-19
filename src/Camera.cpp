#include "Camera.hpp"

glb::Camera::Camera(sf::Vector2f size)
    : GameObject(sf::Vector2f(0.f, 0.f)),
      view(sf::Vector2f(0.f, 0.f), size)
{}

void glb::Camera::update(GameContext& context, const sf::Time& elapsedTime)
{
    if (followTarget)
    {
        position = followTarget->position;
    }
    view.setCenter(position);
}

void glb::Camera::draw(GameContext& context)
{
    context.setView(view);
}

void glb::Camera::follow(const GameObject* const target)
{
    followTarget = target;
}