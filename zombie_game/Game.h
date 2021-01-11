#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>

#include "Drawable.h"
#include "Wall.h"
#include "Floor.h"

class Game {
	public:
		Game();
		~Game();

		bool running();
		void pollEvents();
		void update();
		void render();

		std::vector<Drawable*> drawables;
	private:
		sf::RenderWindow* window;
		AssetManager assets;
		sf::Event event;
};

#endif GAME_H
