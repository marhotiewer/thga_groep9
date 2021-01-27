#ifndef ROCKS_H
#define ROCKS_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Rocks
/// \brief
/// Class for the Rocks in the map.
/// \details
/// Class used for a rock.
/// \image html rocks.png
class Rocks : public Static
{
	public:
		/// <summary>
		/// Constructor of the Rocks.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Rocks.</param>
		Rocks(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the Rocks.
		/// So the Player can walk in front or behind the Rocks.
		/// </summary>
		/// <returns>SFML FloatRect of the Hitbox of the Rocks.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
