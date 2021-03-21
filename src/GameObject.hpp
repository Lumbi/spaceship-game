#pragma once

#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Collider.hpp"

namespace glb
{
    class GameContext;

    class GameObject
    {
        public:
            sf::Vector2f position;
            std::unique_ptr<Collider> collider;

            GameObject(sf::Vector2f position): position(position) {};

            virtual void start(GameContext& context) {};
            virtual void update(GameContext& context, const sf::Time& elapsedTime) {};
            virtual void draw(GameContext& context) {};
            virtual void collide(GameObject* const) {};

            bool isAlive() { return alive; }
            virtual void kill() { alive = false; }

        private:
            bool alive = true;
    };
}