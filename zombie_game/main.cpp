#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include <iostream>

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	cScreen* Screens[] = {
		new MainMenu(&window),
		new Game(&window)
	};
    screen currentScreen = screen::mainMenu;
    while (currentScreen != screen::none)
    {
		currentScreen = Screens[int(currentScreen)]->Run();
        std::cout << int(currentScreen) << std::endl;
    }
    return 0;
}
