#include "EnemyWeapon.hpp"
#include "EnemyBullet.hpp"
#include "Vector2Utility.hpp"

glb::EnemyWeapon::EnemyWeapon(const glb::GameObject* const holder, const GameObject* const target)
    :
    GameObject(sf::Vector2f(0.f, 0.f)),
    holder(holder),
    target(target)
{

}

void glb::EnemyWeapon::update(GameContext& context, const sf::Time& elapsedTime)
{
    timeElapsedSinceLastFire += elapsedTime.asSeconds();

    if (holder && target) {
        if (timeElapsedSinceLastFire > 1.f / fireRate)
        {
            const sf::Vector2f distanceToTarget = target->position - holder->position;
            if (glb::Vector2::magnitude(distanceToTarget) < 300.f)
            {
                const float rotation = glb::Vector2::angle(distanceToTarget);
                fire(context, rotation);
            }
        }
    }
}

void glb::EnemyWeapon::fire(GameContext& context, const float rotation)
{
    timeElapsedSinceLastFire = 0.f;
    auto bullet = std::make_unique<glb::EnemyBullet>(holder->position, rotation);
    context.add(std::move(bullet));
}