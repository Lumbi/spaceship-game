#pragma once

#include <SFML/System.hpp>

namespace glb
{
    class GameContext;

    class GameObject
    {
        public:
            sf::Vector2f position;

            GameObject() {};
            GameObject(sf::Vector2f position): position(position) {};

            virtual void update(GameContext& context, const sf::Time& elapsedTime) {};
            virtual void draw(GameContext& context) {};

            bool isAlive() { return alive; }
            virtual void kill() { alive = false; }

        private:
            bool alive = true;
    };
}