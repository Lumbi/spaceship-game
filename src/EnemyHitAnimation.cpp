#include "EnemyHitAnimation.hpp"

void glb::EnemyHitAnimation::play()
{
    time = 0.f;
    isPlaying = true;
}

void glb::EnemyHitAnimation::stop()
{
    isPlaying = false;
}

void glb::EnemyHitAnimation::animate(const sf::Time& elapsedTime)
{
    if (!isPlaying) { return; }
    const sf::Uint8 alpha = sf::Uint8(255.f * (duration - time) / duration);
    enemyShape.setFillColor(sf::Color(255, 0, 0, alpha));
    time += elapsedTime.asSeconds();
    if (time >= duration)
    {
        stop();
    }
}
