#ifndef LAMP_H
#define LAMP_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Lamp
/// \brief
/// Class for a Street light.
/// \details
/// Class used in the map for Static Street lights.
/// Class is inherted from Static, so it can't move.
/// \image html lamp.png
class Lamp : public Static
{
	public:
		/// <summary>
		/// Constructor of the street light.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Lamp.</param>
		Lamp(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the Street light.
		/// So the Player can walk in front or behind the Street light.
		/// </summary>
		/// <returns>SFML FloatRect of the Hitbox of the Street light.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
