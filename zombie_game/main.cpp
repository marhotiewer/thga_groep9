#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include <iostream>

int main()
{
    std::vector<cScreen*> Screens;
    int screen = 0;
    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
    window.setFramerateLimit(144);
    MainMenu screen1(&window);
    Game screen2(&window);
    Screens.push_back(&screen1);
    Screens.push_back(&screen2);
    while (screen >= 0)
    {
        screen = Screens[screen]->Run();
        std::cout << screen << std::endl;
    }
    return 0;
}
