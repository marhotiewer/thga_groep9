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
	int alpha_max;
	int alpha_div;
	bool isFullScreen = false;
	AssetManager* assets;
	sf::RenderWindow* window;
	sf::Event event;
	std::vector<Button*> buttons;
	sf::Sprite logo;
	sf::Sprite background;
	sf::Music *backgroundMusic;
	sf::Sound clickSound;
public:
	MainMenu(sf::RenderWindow* window, AssetManager* assets);
	screen update(float deltaTime);
	void toggleFullscreen();
	screen pollEvents();
	bool running();
	void render();
	screen run() override;
};

#endif
