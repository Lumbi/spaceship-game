#include "EnemyDestroyAnimation.hpp"

void glb::EnemyDestroyAnimation::play()
{
    time = 0.f;
    isPlaying = true;
}

void glb::EnemyDestroyAnimation::stop()
{
    isPlaying = false;
}

void glb::EnemyDestroyAnimation::animate(const sf::Time& elapsedTime)
{
    if (!isPlaying) { return; }
    const float ratio = std::max((duration - time) / duration, 0.f);
    const sf::Uint8 alpha = sf::Uint8(255.f * ratio);
    enemyShape.setFillColor(sf::Color(255, 0, 0, alpha));
    enemyShape.setScale(2.f * ratio, 2.f * ratio);
    if (time < duration)
    {
        time += elapsedTime.asSeconds();
    } else {
        stop();
    }
}
