#include "PlayerWeapon.hpp"

glb::PlayerWeapon::PlayerWeapon(const PlayerShip& playerShip)
    : playerShip(playerShip)
{

}

void glb::PlayerWeapon::update(GameContext& context, const sf::Time& elapsedTime)
{
    timeElapsedSinceLastFire += elapsedTime.asSeconds();
    if (context.keyboard.isDown(sf::Keyboard::Z)) 
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
    std::unique_ptr<GameObject> bullet(new PlayerBullet(playerShip));
    context.add(std::move(bullet));
}
