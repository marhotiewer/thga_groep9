#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game game;

    sf::Clock clock;
    float deltaTime;

    while (game.running())
    {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        game.update(deltaTime);
        game.render();
    }

    return 0;
}
