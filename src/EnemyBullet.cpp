#include "EnemyBullet.hpp"
#include "Vector2Utility.hpp"
#include "Collider.hpp"
#include "EnemyShip.hpp"

glb::EnemyBullet::EnemyBullet(const sf::Vector2f& position, const float rotation)
    :
    GameObject(position),
    rotation(rotation),
    velocity(glb::Vector2::unit(rotation) * speed)
{
    collider = std::make_unique<PointCollider>(position);

    float width = 4.f;
    float height = 20.f;
    shape = sf::RectangleShape(sf::Vector2f(width, height));
    shape.setOrigin(width / 2.f, height / 2.f);
    shape.setFillColor(sf::Color::Red);
}

void glb::EnemyBullet::update(GameContext& context, const sf::Time& elapsedTime)
{
    ttl -= elapsedTime.asSeconds();
    if (ttl <= 0) { kill(); return; }

    position += velocity * elapsedTime.asSeconds();
}

void glb::EnemyBullet::collide(GameObject* const other)
{
    auto enemyShip = dynamic_cast<EnemyShip* const>(other);
    if (!enemyShip)
    {
        kill();
    }
}

void glb::EnemyBullet::draw(GameContext& context)
{
    shape.setPosition(position);
    shape.setRotation(rotation);
    context.draw(shape);
}
