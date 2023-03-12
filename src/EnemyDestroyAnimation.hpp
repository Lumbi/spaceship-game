#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace glb
{
    class EnemyDestroyAnimation {
        public:
            EnemyDestroyAnimation(sf::Shape& enemyShape): enemyShape(enemyShape) {};
            void play();
            void stop();
            void animate(const sf::Time& elapsedTime);

            bool isCompleted() const { return time >= duration; };

        private:
            sf::Shape& enemyShape;
            bool isPlaying = false;
            const float duration = 0.3f;
            float time = 0.f;
    };
}
