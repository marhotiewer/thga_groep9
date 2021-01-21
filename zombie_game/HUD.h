#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
///@file

struct HudInfo{
	int health = 10;
	int points = 0;
	float time = 0;
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
		/// 
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">position of the HUD</param>
		HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos);
		
		/// <summary>
		/// Function to draw the HUD on the screen
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		void draw(sf::RenderWindow* window);

		/// <summary>
		/// Function to update the correct size of the HUD.
		/// </summary>
		void update(HudInfo info);
	private:
		sf::RenderWindow* window;///<Pointer to the SFML window. [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		sf::Sprite bottom_right;///<
		AssetManager& assets;///<Reference to the AssetManager. To load textures. 
		sf::Text healthText;
		sf::Text timeText;
		sf::Text pointsText;
};

#endif
