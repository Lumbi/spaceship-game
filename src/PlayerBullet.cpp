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
    shape.setOrigin(width / 2.f, height / 2.f);
    shape.setFillColor(sf::Color::White);
}

void glb::PlayerBullet::update(GameContext& context, const sf::Time& elapsedTime)
{
    ttl -= elapsedTime.asSeconds();
    if (ttl <= 0) { kill(); return; }

    position += velocity * elapsedTime.asSeconds();
}

void glb::PlayerBullet::collide(GameObject* const other)
{
    auto debris = dynamic_cast<Debris* const>(other);
    if (debris)
    {
        collide(debris);
        return;
    }

    auto enemyShip = dynamic_cast<EnemyShip* const>(other);
    if (enemyShip)
    {
        collide(enemyShip);
        return;
    }
}

void glb::PlayerBullet::collide(Debris* const debris)
{
    sf::FloatRect otherRect = debris->collider->boundingRect();
    sf::Vector2f updatedVelocity = velocity;

    float topPenetration = std::abs(position.y - otherRect.top);
    float bottomPenetration = std::abs(otherRect.top + otherRect.height - position.y);
    float leftPenetration = std::abs(position.x - otherRect.left);
    float rightPenetration = std::abs(otherRect.left + otherRect.width - position.x);

    float verticalPenetration = std::min(topPenetration, bottomPenetration);
    float horizontalPenetration = std::min(leftPenetration, rightPenetration);

    if (horizontalPenetration < verticalPenetration)
    {
        updatedVelocity.x *= -1.f;
    } else {
        updatedVelocity.y *= -1.f;
    }

    velocity = updatedVelocity;
    rotation = glb::Vector2::angle(velocity);

    // Increase the TTL every time the bullet ricochets
    ttl = std::min(ttl + 0.1f, maxTtl);

    // Adjust position to move it outside the collider
    if (horizontalPenetration < verticalPenetration)
    {
        if (leftPenetration < rightPenetration)
        {
            position.x -= (leftPenetration + 1.f);
        } else {
            position.x += (rightPenetration + 1.f);
        }
    } else {
        if (topPenetration < bottomPenetration)
        {
            position.y -= (topPenetration + 1.f);
        } else {
            position.y += (bottomPenetration + 1.f);
        }
    }
}

void glb::PlayerBullet::collide(EnemyShip* const enemyShip)
{
    kill();
}

void glb::PlayerBullet::draw(GameContext& context)
{
    shape.setPosition(position);
    shape.setRotation(rotation);
    context.window.draw(shape);
}