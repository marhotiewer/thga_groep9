#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
///@file


/// \struct HudInfo
/// \brief Information on the screen: Health, points and time.
struct HudInfo{
	int health = 10;///< Health of the Player. 
	int points = 0;///< Points of the Player. 
	float time = 0;///< time of the current game. 
};


/// \class HUD
/// \brief 
/// Class for on screen information
/// /details
/// Class used for on screen information.
class HUD
{
	public:
		/// <summary>
		/// Constructor of the HUD.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position of the HUD</param>
		HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos);
		
		/// <summary>
		/// Function to draw the hud. The hud wil contain: Health, Time and Points
		/// </summary>
		///<param name="window">The pointer to the current SFML window of the game.</param>
		void draw(sf::RenderWindow* window);

		/// <summary>
		/// Function to update the correct size of the HUD.
		/// </summary>
		void update();

		/// <summary>
		/// Function to update the correct wave to the HUD.
		/// </summary>
		/// <param name="newWave">Wave number</param>
		void updateWave(int newWave);

		/// <summary>
		/// Function to update the correct information on the HUD.
		/// </summary>
		/// <param name="info">Struct HudInfo with player information.</param>
		void updateText(HudInfo info);
	private:
		sf::RenderWindow* window;///< Pointer to the SFML window. [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		sf::Sprite bottom_right;///< The background of the hud. 
		AssetManager& assets;///< Reference to the AssetManager. To load textures. 
		sf::Text healthText;///< SFML Text used for displaying the Health of the player on screen.
		sf::Text timeText;///< SFML Text used for displaying the time of the game on screen.
		sf::Text pointsText;///< SFML Text used for displaying the points of the player on screen.
		sf::Text waveText;///< SFML Text used for displaying current wave of the game on screen.
		int wave = 1;///< The wave number of the game.. 
};

#endif
