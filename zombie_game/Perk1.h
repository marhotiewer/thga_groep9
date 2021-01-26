#ifndef PERK1_H
#define PERK1_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Perk1
/// \brief
/// Class for a item Perk shop.
/// \details
/// Class used in the map for a item Perk shop.
/// \image html perk1.png
class Perk1 : public Static
{
	public:
		/// <summary>
		/// Constructor of Perk1.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Perk(1).</param>
		/// <param name="size">Size of the Perk</param>
		Perk1(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
