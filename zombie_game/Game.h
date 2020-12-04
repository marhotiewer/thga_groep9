#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>

#include "GameObject.h"

class Game {
	public:
		Game();
		~Game();

		bool running();
		void pollEvents();
		void update();
		void render();

		std::vector<std::unique_ptr<GameObject>> gameObjects;
	private:
		sf::RenderWindow* window;
		sf::Event event;
};

#endif GAME_H
