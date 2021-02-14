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
            sf::FloatRect boundingRect() const;
            PointCollider(const sf::Vector2f& point): point(point) {};
            void draw(sf::RenderWindow& window);

        protected:
            bool collides(const sf::FloatRect& rect);
    };

    class ConvexShapeCollider: public Collider
    {
        public:
            const sf::ConvexShape& shape;
            sf::FloatRect boundingRect() const;
            ConvexShapeCollider(const sf::ConvexShape& shape): shape(shape) {};
            void draw(sf::RenderWindow& window);

        protected:
            bool collides(const sf::Vector2f& point);
    };
}