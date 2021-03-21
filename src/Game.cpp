#include "Game.hpp"

void addEnemyShips(glb::GameContext& context, const glb::GameObject* const playerShip);
void addDebris(glb::GameContext& context);

int glb::Game::Run()
{
    const float windowWidth = 1920, windowHeight = 1080;
    sf::RenderWindow window(
        sf::VideoMode(windowWidth, windowHeight),
        "Game",
        sf::Style::Titlebar | sf::Style::Close
    );
    window.setVerticalSyncEnabled(true);

    glb::GameContext context(window);
    sf::Clock clock;

    auto camera = std::make_unique<Camera>(sf::Vector2f(windowWidth, windowHeight));

    auto playerShip = std::make_unique<PlayerShip>();
    playerShip->position.x = 100.0f;
    playerShip->position.y = 100.0f;
    camera->follow(playerShip.get());

    auto playerWeapon = std::make_unique<PlayerWeapon>(*playerShip.get());

    addEnemyShips(context, playerShip.get());
    addDebris(context);

    context.add(std::move(camera));
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
        context.draw();
    }

    return 0;
}

void addEnemyShips(glb::GameContext& context, const glb::GameObject* const playerShip)
{
    auto enemyShip = std::make_unique<glb::EnemyShip>();
    enemyShip->position.x = -100.f;
    enemyShip->position.y = -100.f;
    enemyShip->setFollowTarget(playerShip);
    context.add(std::move(enemyShip));

    enemyShip = std::make_unique<glb::EnemyShip>();
    enemyShip->position.x = 250.f;
    enemyShip->position.y = 130.f;
    enemyShip->setFollowTarget(playerShip);
    context.add(std::move(enemyShip));

    enemyShip = std::make_unique<glb::EnemyShip>();
    enemyShip->position.x = -50.f;
    enemyShip->position.y = -200.f;
    enemyShip->setFollowTarget(playerShip);
    context.add(std::move(enemyShip));
}

void addDebris(glb::GameContext& context)
{
    auto debris = std::make_unique<glb::Debris>(sf::Vector2f(100.f, 200.f));
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>(sf::Vector2f(-300.f, -250.f));
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>(sf::Vector2f(600.f, 150.f));
    context.add(std::move(debris));

    debris = std::make_unique<glb::Debris>(sf::Vector2f(800.f, 550.f));
    context.add(std::move(debris));
}