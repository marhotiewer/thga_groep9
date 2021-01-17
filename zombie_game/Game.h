#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

#include "Drawable.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Floor.h"
#include "Wall.h"
#include "Tree.h"
#include "cScreen.h"

class Game : public cScreen {
	public:
		Game(sf::RenderWindow &window);
		~Game();
		void update(float deltaTime);
		void toggleFullscreen();
		void pollEvents();
		bool running();
		void render();
		virtual int Run(sf::RenderWindow &window);
	private:
		std::vector<Drawable*> objects;
		bool noKeyPressed = false;
		bool isFullScreen = false;
		sf::RenderWindow* window;
		AssetManager assets;
		bool debug = false;
		sf::Event event;
		Player *player;
};

#endif
