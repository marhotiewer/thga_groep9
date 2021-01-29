#include <SFML/Graphics.hpp>
#include <time.h>

#include "AssetManager.h"
#include "ScoreScreen.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "Z-Rush" };
	srand((unsigned int)time(NULL));
	AssetManager assets;

	window.setIcon(assets.gameIconWindow.getSize().x, assets.gameIconWindow.getSize().y, assets.gameIconWindow.getPixelsPtr());
	
	cScreen* Screens[] = {
		new MainMenu(&window, assets),
		new Game(&window, assets),
		new GameOver(&window, assets, *static_cast<Game*>(Screens[1])),
		new ScoreScreen(&window, assets)
	};

	Screen currentScreen = Screen::MainMenu;
    while (currentScreen != Screen::None)
    {
		currentScreen = Screens[int(currentScreen)]->run();
    }
	for (cScreen* screen : Screens) delete screen;

    return 0;
}
