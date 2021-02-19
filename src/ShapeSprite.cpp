#include "ShapeSprite.hpp"

void glb::ShapeSprite::setShape(const sf::Shape& shape)
{
    float width = shape.getLocalBounds().width;
    float height = shape.getLocalBounds().height;

    render.create(width, height);
    render.setView(
        sf::View(
            sf::Vector2f(0.f, 0.f),
            sf::Vector2f(render.getSize().x, render.getSize().y)
        )
    );

    render.clear(sf::Color::Transparent);
    render.draw(shape);
    render.display();

    setTexture(render.getTexture(), true);
    setOrigin(render.getSize().x / 2.f, render.getSize().y / 2.f);
}