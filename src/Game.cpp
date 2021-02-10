#include "Game.hpp"

int glb::Game::Run()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    glb::GameContext context(window);
    sf::Clock clock;

    glb::PlayerShip playerShip;
    playerShip.position.x = 100.0f;
    playerShip.position.y = 100.0f;

    glb::PlayerBullet testPlayerBullet(90.f);
    testPlayerBullet.position.x = 100.0f;
    testPlayerBullet.position.y = 100.0f;

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

        playerShip.update(context, elapsed);
        testPlayerBullet.update(context, elapsed);

        window.clear();
        playerShip.draw(context);
        testPlayerBullet.draw(context);
        window.display();
    }

    return 0;
}
