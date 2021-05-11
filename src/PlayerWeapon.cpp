#include "PlayerWeapon.hpp"

glb::PlayerWeapon::PlayerWeapon(const PlayerShip& playerShip)
    :
    GameObject(sf::Vector2f(0.f, 0.f)),
    playerShip(playerShip)
{

}

void glb::PlayerWeapon::update(GameContext& context, const sf::Time& elapsedTime)
{
    timeElapsedSinceLastFire += elapsedTime.asSeconds();
    if (context.mouse.isLeftButtonDown())
    {
        if (timeElapsedSinceLastFire > 1.f / fireRate)
        {
            fire(context);
        }
    }
}

void glb::PlayerWeapon::fire(GameContext& context)
{
    timeElapsedSinceLastFire = 0.f;
    auto bullet = std::make_unique<glb::PlayerBullet>(playerShip);
    context.add(std::move(bullet));
}
