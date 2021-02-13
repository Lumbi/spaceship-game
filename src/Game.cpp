#include "Game.hpp"

void addDebris(glb::GameContext& context);

int glb::Game::Run()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    glb::GameContext context(window);
    sf::Clock clock;

    auto playerShip = std::make_unique<PlayerShip>();
    playerShip->position.x = 100.0f;
    playerShip->position.y = 100.0f;

    auto playerWeapon = std::make_unique<PlayerWeapon>(*playerShip.get());

    context.add(std::move(playerShip));
    context.add(std::move(playerWeapon));

    addDebris(context);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            } else {
                context.keyboard.update(event);
            }
        }

        context.update(elapsed);

        window.clear();
        context.draw();
        window.display();
    }

    return 0;
}

void addDebris(glb::GameContext& context)
{
    auto debris = std::make_unique<glb::Debris>();
    debris->position.x = 100.f;
    debris->position.y = 200.f;
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>();
    debris->position.x = 300.f;
    debris->position.y = 250.f;
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>();
    debris->position.x = 600.f;
    debris->position.y = 150.f;
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>();
    debris->position.x = 800.f;
    debris->position.y = 550.f;
    context.add(std::move(debris));
}