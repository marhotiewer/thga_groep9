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
		Game(sf::RenderWindow *window, AssetManager *assets);
		void update(float deltaTime);
		void toggleFullscreen();
		screen run() override;
		void pollEvents();
		bool running();
		void render();
		~Game();
	private:
		std::vector<Drawable*> objects;
		sf::Event event = sf::Event();
		bool noKeyPressed = false;
		bool isFullScreen = false;
		sf::RenderWindow* window;
		float elapsedTime = 0.f;
		AssetManager* assets;
		bool debug = false;
		Player *player;
};

#endif
