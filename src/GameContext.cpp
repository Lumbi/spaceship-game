#include "GameContext.hpp"

glb::GameContext::GameContext(sf::RenderWindow& window)
    : window(window) 
{

}

void glb::GameContext::update(const sf::Time& time)
{
    while (!gameObjectsToAdd.empty())
    {
        auto it = gameObjectsToAdd.begin();
        gameObjects.push_back(std::move(*it));
        gameObjectsToAdd.erase(it);
    }

    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        it->get()->update(*this, time);
    }
}

void glb::GameContext::draw()
{
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        it->get()->draw(*this);
    }
}

void glb::GameContext::add(std::unique_ptr<GameObject> gameObject)
{
    gameObjectsToAdd.push_back(std::move(gameObject));
}
