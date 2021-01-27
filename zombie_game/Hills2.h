#ifndef HILLS2_H
#define HILLS2_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Hills2
/// \brief
/// Class of a Hills2
/// \details
/// Class of the hills with waterfall.
/// Class is inherited from Static, so it can't move.
/// \image html hills2.png
class Hills2 : public Static
{
	public:
		/// <summary>
		/// Constructor of the hill.
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Hills(2)</param>
		Hills2(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the hill.
		/// </summary>
		/// <returns>SFML FloatRect of the Hitbox of the hill.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
