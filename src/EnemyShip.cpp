#include "EnemyShip.hpp"

glb::EnemyShip::EnemyShip()
    : GameObject(sf::Vector2f()),
      shape(sf::Vector2f(40.f, 40.f)),
      hitAnim(shape),
      followTarget(nullptr)
{
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(2.f);
    shape.setOrigin(shape.getSize() / 2.f);

    collider = std::make_unique<ShapeCollider>(shape);
}

void glb::EnemyShip::start(GameContext& context)
{
    auto weapon = std::make_unique<EnemyWeapon>(this, followTarget);
    context.add(std::move(weapon));
}

void glb::EnemyShip::update(GameContext& context, const sf::Time& elapsedTime)
{
    hitAnim.animate(elapsedTime);

    // Follow player
    if (followTarget) {
        sf::Vector2f distanceToTarget = followTarget->position - position;
        if (glb::Vector2::magnitude(distanceToTarget) > 300.f) {
            sf::Vector2f direction = glb::Vector2::unit(distanceToTarget);
            velocity += direction * acceleration * elapsedTime.asSeconds();
        } else {
            velocity -= velocity * drag * elapsedTime.asSeconds();
        }
    }

    glb::Vector2::clamp(velocity, 0.f, maxSpeed);
    position += velocity * elapsedTime.asSeconds();
}

void glb::EnemyShip::collide(GameObject* const other)
{
    auto playerBullet = dynamic_cast<PlayerBullet* const>(other);
    if (playerBullet)
    {
        hitAnim.play();
    }
}

void glb::EnemyShip::draw(GameContext& context)
{
    shape.setPosition(position);
    context.draw(shape);
}

void glb::EnemyShip::setFollowTarget(const GameObject* const targetToFollow)
{
    followTarget = targetToFollow;
}
