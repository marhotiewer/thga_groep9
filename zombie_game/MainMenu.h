#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "cScreen.h"
#include "AssetManager.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class MainMenu : public cScreen
{
	private:
		std::vector<Button*> buttons;
		bool isFullScreen = false;
		sf::RenderWindow* window;
		sf::Sprite background;
		AssetManager& assets;
		sf::Event event;
		sf::Sprite logo;
		int alpha_max;
		int alpha_div;
		sf::Music* backgroundMusic;
		sf::Sound clickSound;
	public:
		MainMenu(sf::RenderWindow* window, AssetManager& assets);
		Screen update(float deltaTime);
		void toggleFullscreen();
		Screen run() override;
		Screen pollEvents();
		bool running();
		void render();
};

#endif
