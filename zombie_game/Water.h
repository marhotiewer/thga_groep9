#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Water
/// \brief
/// Water class.
/// \details
/// Class used for spawning Water.
/// \image html water.png
class Water : public Static
{
	public:
		/// <summary>
		/// Constructor of Water.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Water.</param>
		/// <param name="size">Size of the Water.</param>
		Water(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
