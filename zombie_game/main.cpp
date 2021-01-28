#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "AssetManager.h"
#include "ScoreScreen.h"


int main()
{
	srand((unsigned int)time(NULL));
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "Z-Rush" };
	AssetManager assets;
	window.setIcon(assets.gameIconWindow.getSize().x, assets.gameIconWindow.getSize().y, assets.gameIconWindow.getPixelsPtr());
	Game game(&window, assets);
	cScreen* Screens[] = {
		new MainMenu(&window, assets),
		&game,
		new GameOver(&window, assets, game),
		new ScoreScreen(&window, assets)
	};
	Screen currentScreen = Screen::MainMenu;
	
    while (currentScreen != Screen::None)
    {
		currentScreen = Screens[int(currentScreen)]->run();
    }
    return 0;
}
