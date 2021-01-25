#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "AssetManager.h"
#include "Drawable.h"
#include "ScoreScreen.h"
#include <iostream>

int main()
{
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	AssetManager assets;
	Game game(&window, assets);
	cScreen* Screens[] = {
		new MainMenu(&window, assets),
		&game,
		new GameOver(&window, assets, game),
		new ScoreScreen(&window, assets)
	};
	Screen currentScreen = Screen::Scores;
	
    while (currentScreen != Screen::None)
    {
		currentScreen = Screens[int(currentScreen)]->run();
    }
    return 0;
}
