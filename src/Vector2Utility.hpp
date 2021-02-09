#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

namespace glb
{
    namespace Vector2
    {
        template<typename T>
        T magnitude(const sf::Vector2<T>& vector2)
        {
            return sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
        }

        template<typename T>
        void clamp(sf::Vector2<T>& vector2, T min, T max)
        {
            auto mag = magnitude(vector2);
            if (mag == 0) { return; }
            if (mag > max) {
                auto scale = max / mag;
                vector2 *= scale;
            } else if (mag < min) {
                auto scale = min / mag;
                vector2 *= scale;
            }
        }
    }
}