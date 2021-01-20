#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include "AssetManager.h"
#include <iostream>

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	AssetManager assets;
	cScreen* Screens[] = {
		new MainMenu(&window, &assets),
		new Game(&window, &assets)
	};
    screen currentScreen = screen::mainMenu;
    while (currentScreen != screen::none)
    {
		currentScreen = Screens[int(currentScreen)]->run();
    }
    return 0;
}
