#pragma once

#include <SFML/Graphics.hpp>

#include "GameContext.hpp"
#include "GameObject.hpp"

namespace glb
{
    class Camera: public GameObject
    {
        public:
            Camera(sf::Vector2f size);
            void update(GameContext& context, const sf::Time& elapsedTime);
            void draw(GameContext& context);
            void follow(const GameObject* const);

        private:
            sf::View view;
            const GameObject* followTarget;
    };
}