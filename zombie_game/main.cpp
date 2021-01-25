#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include "AssetManager.h"

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	AssetManager assets;

	cScreen* Screens[] = {
		new MainMenu(&window, assets),
		new Game(&window, assets)
	};

    Screen currentScreen = Screen::MainMenu;

    while (currentScreen != Screen::None)
    {
		currentScreen = Screens[int(currentScreen)]->run();
    }
    return 0;
}
