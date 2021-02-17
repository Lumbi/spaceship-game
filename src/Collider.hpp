#pragma once

#include <SFML/Graphics.hpp>

namespace glb
{
    class Collider
    {
        public:
            Collider() {};
            virtual sf::FloatRect boundingRect() const { return sf::FloatRect(0.f, 0.f, 0.f, 0.f); };
            bool collides(const Collider&);
            virtual void draw(sf::RenderWindow& window) {};

        protected:
            virtual bool collides(const sf::Vector2f& point) { return false; };
            virtual bool collides(const sf::FloatRect& rect) { return false; };
    };

    class PointCollider: public Collider
    {
        public:
            const sf::Vector2f& point;
            PointCollider(const sf::Vector2f& point): point(point) {};
            void draw(sf::RenderWindow& window);

        protected:
            bool collides(const sf::FloatRect& rect);
    };

    class ShapeCollider: public Collider
    {
        public:
            sf::FloatRect boundingRect() const;
            ShapeCollider(const sf::Shape& shape): shape(shape) {};
            void draw(sf::RenderWindow& window);

        protected:
            const sf::Shape& shape;
            bool collides(const sf::Vector2f& point);
    };
}