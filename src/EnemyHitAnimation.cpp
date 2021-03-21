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
    const float ratio = std::max((duration - time) / duration, 0.f);
    const sf::Uint8 alpha = sf::Uint8(255.f * ratio);
    enemyShape.setFillColor(sf::Color(255, 0, 0, alpha));
    if (time < duration)
    {
        time += elapsedTime.asSeconds();
    } else {
        stop();
    }
}
