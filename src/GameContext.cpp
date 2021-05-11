#include "GameContext.hpp"

glb::GameContext::GameContext(sf::RenderWindow& window)
    : window(window),
      bloomEffect(window),
      mouse(*this)
{
    render.create(window.getSize().x, window.getSize().y);
    debugFont.loadFromFile("../resources/Arial.ttf"); // TODO: Copy resources and fix path
    debugText.setFont(debugFont);
    debugText.setColor(sf::Color::White);
    debugText.setPosition(100, 100);
}

void glb::GameContext::update(const sf::Time& time)
{
    // Add new game objects
    while (!gameObjectsToAdd.empty())
    {
        auto it = gameObjectsToAdd.begin();
        it->get()->start(*this);
        gameObjects.push_back(std::move(*it));
        gameObjectsToAdd.erase(it);
    }

    // Update game objects and removed killed game objects
    auto it = gameObjects.begin();
    while (it != gameObjects.end())
    {
        if (it->get()->isAlive())
        {
            it->get()->update(*this, time);
            it++;
        }
        else
        {
            it = gameObjects.erase(it);
        }
    }

    // Check collisions
    for (const auto& first : gameObjects)
    {
        for (const auto& second : gameObjects)
        {
            if (first != second && first->collider && second->collider)
            {
                bool collided = first->collider->collides(*second->collider);
                if (collided)
                {
                    first->collide(second.get());
                    second->collide(first.get());
                }
            }
        }
    }
}

void glb::GameContext::draw()
{
    render.clear();
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        if (it->get()->isAlive())
        {
            it->get()->draw(*this);
        }
    }
    render.display();
    bloomEffect.render(render.getTexture());
    window.draw(debugText);
    window.display();
}

void glb::GameContext::draw(const sf::Drawable& drawable)
{
    render.draw(drawable);
}

void glb::GameContext::setView(const sf::View& view)
{
    render.setView(view);
}

sf::Vector2f glb::GameContext::toWorldPosition(const sf::Vector2i& windowPosition) const
{
    return render.mapPixelToCoords(windowPosition);
}

void glb::GameContext::add(std::unique_ptr<GameObject> gameObject)
{
    gameObjectsToAdd.push_back(std::move(gameObject));
}

void glb::GameContext::debugAppend(const std::string& string)
{
    debugStream << string;
    debugText.setString(debugStream.str());
}

void glb::GameContext::debugClear()
{
    debugStream.str("");
    debugText.setString("");
}
