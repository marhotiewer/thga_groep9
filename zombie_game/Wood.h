#ifndef WOOD_H
#define WOOD_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Wood
/// \brief
/// Wood class.
/// \details
/// Class used for spawning Wood.
/// \image html wood.png
class Wood : public Static
{
	public:
		/// <summary>
		/// Constructor of one wood plank.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Wood.</param>
		/// <param name="size">Size of the Wood</param>
		Wood(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
