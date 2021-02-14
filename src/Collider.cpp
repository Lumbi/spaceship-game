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


bool glb::PointCollider::collides(const sf::FloatRect& rect)
{
    return rect.contains(point);
}

void glb::PointCollider::draw(sf::RenderWindow& window)
{
    auto circle = sf::CircleShape(50.f);
    circle.setPosition(point);
    circle.setFillColor(sf::Color::Red);
    window.draw(circle);
}

bool glb::ConvexShapeCollider::collides(const sf::Vector2f& point)
{
    return shape.getGlobalBounds().contains(point);
}

void glb::ConvexShapeCollider::draw(sf::RenderWindow& window)
{

}