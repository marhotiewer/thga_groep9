#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

#include "Drawable.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Tree.h"

class Game {
	public:
		Game();
		~Game();
		void update(float deltaTime);
		void pollEvents();
		bool running();
		void render();
	private:
		std::vector<Entity*> entities;
		std::vector<Static*> statics;
		bool noKeyPressed = false;
		sf::RenderWindow* window;
		AssetManager assets;
		sf::Event event;
		Player *player;
};

#endif GAME_H
