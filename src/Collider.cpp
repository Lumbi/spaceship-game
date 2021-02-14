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
            auto casted = dynamic_cast<const ConvexShapeCollider&>(other);
            return collides(casted.shape.getGlobalBounds());
        }
    }
    catch (const std::bad_cast& e)
    {
        // TODO: log
    }
    return false;
}

// POINT COLLIDER

sf::FloatRect glb::PointCollider::boundingRect() const
{
    return sf::FloatRect(point, sf::Vector2f(0.f, 0.f));
}

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

sf::FloatRect glb::ConvexShapeCollider::boundingRect() const
{
    return shape.getGlobalBounds();
}

bool glb::ConvexShapeCollider::collides(const sf::Vector2f& point)
{
    return boundingRect().contains(point);
}

void glb::ConvexShapeCollider::draw(sf::RenderWindow& window)
{

}