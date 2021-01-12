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

class Game {
	public:
		Game();
		~Game();

		bool running();
		void pollEvents();
		void update(float deltaTime);
		void render();

		std::vector<Drawable*> drawables;
	private:
		sf::RenderWindow* window;
		AssetManager assets;
		sf::View viewport;
		sf::Event event;
		Player *player;
		bool noKeyPressed = false;
};

#endif GAME_H
