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


/// \class Game
/// \brief
/// Head game class
/// \details
/// Class that runs the game. 
class Game {
	public:
		/// <summary>
		/// Constructor of the game. The game loads the map in and set the player on the screen.
		/// 
		/// </summary>
		Game();

		/// <summary>
		/// Destructor of the game. 
		/// </summary>
		~Game();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(float deltaTime);
		
		/// <summary>
		/// 
		/// </summary>
		void toggleFullscreen();

		/// <summary>
		/// 
		/// </summary>
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
