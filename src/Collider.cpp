#include "Collider.hpp"
#include "GameObject.hpp"

bool glb::Collider::collides(const Collider& other)
{
    try
    {
        {
            auto casted = dynamic_cast<const PointCollider&>(other);
            return collides(casted.point);
        }
        {
            auto casted = dynamic_cast<const ShapeCollider&>(other);
            return collides(casted.boundingRect());
        }
    }
    catch (const std::bad_cast& e)
    {
        // TODO: log
    }
    return false;
}

// POINT COLLIDER

bool glb::PointCollider::collides(const sf::FloatRect& rect)
{
    return rect.contains(point);
}

void glb::PointCollider::draw(sf::RenderWindow& window)
{
    sf::CircleShape circle(5.f);
    circle.setPosition(point);
    circle.setFillColor(sf::Color::Red);
    window.draw(circle);
}

// CONVEX SHAPE COLLIDER

sf::FloatRect glb::ShapeCollider::boundingRect() const
{
    return shape.getGlobalBounds();
}

bool glb::ShapeCollider::collides(const sf::Vector2f& point)
{
    return boundingRect().contains(point);
}

void glb::ShapeCollider::draw(sf::RenderWindow& window)
{

}