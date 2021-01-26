#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <functional>
#include <algorithm>
#include <iostream>
#include <json.hpp>
#include <fstream>
#include <vector>


#include "InvisibleWall.h"
#include "PoliceAgent.h"
#include "BushRotated.h"
#include "HouseFence.h"
#include "Drawable.h"
#include "Fountain.h"
#include "Campfire.h"
#include "Sandbag.h"
#include "cScreen.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Hills1.h"
#include "Hills2.h"
#include "Floor.h"
#include "Fence.h"
#include "Water.h"
#include "Rocks.h"
#include "Perk1.h"
#include "Wall.h"
#include "Tree.h"
#include "Shed.h"
#include "Tent.h"
#include "Wood.h"
#include "Lamp.h"
#include "Bush.h"
/// @file


/// \class Game
/// \brief 
/// class for the Game.
/// \details
/// This class implement the z-rush zombie game.
class Game : public cScreen {
	public:
		/// <summary>
		/// Constructor of the game.
		/// In the constructor all the objects will be created.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		Game(sf::RenderWindow* window, AssetManager& assets);

		/// <summary>
		/// This function updates the position on the screen. And runs the Bullet::move function to check if it can move to the new location. 
		/// </summary>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		void update(float deltaTime);
		
		/// <summary>
		/// Function that as executed will toggle the SFML window to full screen.
		/// </summary>
		void toggleFullscreen();

		/// <summary>
		/// Main loop of the Z-Rush game.
		/// This function will be executed for the game.
		/// This function will return if a next screen need to show or the application need to exit. 
		/// </summary>
		/// <returns>Next screen to run(probably the game).</returns>
		Screen run() override;
		
		/// <summary>
		/// SFML Event handeler.
		/// [SFML Event Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php)
		/// </summary>
		/// <returns>If a next screen need to show. !!!!!</returns>
		void pollEvents();

		/// <summary>
		/// Function that checks if the SFML window is running.
		/// [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		/// </summary>
		/// <returns>If SFML window is running</returns>
		bool running();

		/// <summary>
		/// Function that draws everything on the screen.
		/// Uses #window [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		/// </summary>
		void render();

		Player* player;///< Pointer to the Player. Is public because the GameOver screen need to get the scores when the player dies.

		~Game();
	private:
		std::vector<sf::Vector2f> spawns;
		std::vector<Drawable*> objects;///< vector of pointers of all drawable pointers 
		bool noKeyPressed = false;///< bool if no key is pressed.
		bool isFullScreen = false;///<bool used for used full screen.
		sf::RenderWindow* window;///< Pointer to the SFML window.
		sf::Music* ingameBreeze;///< Pointer to the ingame breeze sound.
		float elapsedTime = 0.f;///<Time used for elapsed a frame.
		unsigned char wave = 1;
		AssetManager& assets;///<Reference to the AssetManager. To load textures. 
		bool debug = false;///< bool used for debug intentions.
		sf::Event event;///<SFML Event handeler. [SFML Event Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php)
		unsigned char zombiesLeft = 5;
		float spawnTimer = 0;
};

#endif
