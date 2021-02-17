#pragma once

#include <SFML/Graphics.hpp>

namespace glb
{
    class EnemyHitAnimation
    {
        public:
            EnemyHitAnimation(sf::Shape& enemyShape): enemyShape(enemyShape) {};
            void play();
            void stop();
            void animate(const sf::Time& elapsedTime);

        private:
            sf::Shape& enemyShape;
            bool isPlaying = false;
            const float duration = 0.3f;
            float time = 0.f;
    };
}