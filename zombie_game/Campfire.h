#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include <SFML/Graphics.hpp>

#include "Static.h"
///@file


/// \class Campfire
/// \brief
/// Class of a Campfire
/// \details
/// This class creates a Campfire.
/// Class is inherited from Static, so it can't move.
/// This class has a override on getHitbox function for it's own hitbox.
/// \image html campfire.png
class Campfire : public Static
{
	public:
		/// <summary>
		/// Constructor of the Campfire
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">position of the Campfire.</param>
		Campfire(AssetManager& assets, sf::Vector2f pos);
		
		/// <summary>
		/// Function to return the correct hitbox of the Bush.
		/// So the player can walk behind the campfire.
		/// </summary>
		/// <returns>SFML FloatRect of the campfire</returns>
		sf::FloatRect getHitbox() override;
};

#endif
