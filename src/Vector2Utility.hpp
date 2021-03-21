#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

namespace glb
{
    namespace Vector2
    {
        template<typename T>
        static const sf::Vector2<T> up(static_cast<T>(0), static_cast<T>(-1));

        template<typename T>
        static sf::Vector2<T> unit(const T angleDeg = 0.f)
        {
            const float angleRad = angleDeg * M_PI / static_cast<T>(180);
            const float cosine = cos(angleRad);
            const float sine = sin(angleRad);
            auto up = glb::Vector2::up<T>;
            return sf::Vector2<T>(
                cosine * up.x - sine * up.y,
                sine * up.x + cosine * up.y
            );
        }

        template<typename T>
        T magnitude(const sf::Vector2<T>& vector2)
        {
            return sqrt(vector2.x * vector2.x + vector2.y * vector2.y);
        }

        template<typename T>
        sf::Vector2<T> unit(const sf::Vector2<T>& vector2)
        {
            return vector2 / magnitude(vector2);
        }

        template<typename T>
        T angle(const sf::Vector2<T>& vector2)
        {
            return static_cast<T>(90) + atan2(vector2.y, vector2.x) * static_cast<T>(180) / M_PI;
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