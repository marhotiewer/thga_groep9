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

		/// <summary>
		/// 
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(float deltaTime);
		
		/// <summary>
		/// 
		/// </summary>
		void toggleFullscreen();
		screen run() override;
		void pollEvents();

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		bool running();

		/// <summary>
		/// 
		/// </summary>
		void render();
		~Game();
	private:
		std::vector<Drawable*> objects;///<
		bool noKeyPressed = false;///<
		bool isFullScreen = false;///<
		sf::RenderWindow* window;///< Pointer to the SFML window 
		float elapsedTime = 0.f;///<
		AssetManager assets;///<
		bool debug = false;///<
		sf::Event event;///<
		Player *player;///<
};

#endif
