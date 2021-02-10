#include "Game.hpp"

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
