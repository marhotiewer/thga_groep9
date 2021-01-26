#ifndef HILLS1_H
#define HILLS1_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Hills1
/// \brief
/// Class of a Hills1(normal hills)
/// \details
/// Class for the normal hills (with no waterfall).
/// \image html hills1.png
class Hills1 : public Static
{
	public:
		/// <summary>
		/// Constructor of the hill
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Hills(1)</param>
		Hills1(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the hill.
		/// </summary>
		/// <returns>SFML FloatRect of the Hitbox of the hill.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
