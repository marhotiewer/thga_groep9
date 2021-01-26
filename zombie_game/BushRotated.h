#ifndef BUSHROTATED_H
#define BUSHROTATED_H

#include <SFML/Graphics.hpp>

#include "Static.h"
///@file


/// \class Bush
/// \brief
/// class for a rotated Bush.
/// \details
/// This class creates rotated Bushes.
/// This is a Static class that dont move. 
/// This class has a override on getHitbox function for it's own hitbox.
/// \img html bushRotated.png
class BushRotated : public Static
{
	public:
		/// <summary>
		/// Constructor for Bush, for placement of the Buch on the map.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">position of the bush.</param>
		BushRotated(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the Bush.
		/// So the player can walk behind the Bush.
		/// </summary>
		/// <returns>hitbox of the bush.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
