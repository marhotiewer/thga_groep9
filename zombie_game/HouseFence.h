#ifndef HOUSEFENCE_H
#define HOUSEFENCE_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class HouseFence
/// \brief
/// Class of a HouseFence
/// \details
/// Class of the fence near the house.
/// \image html fenceHouse.png
class HouseFence : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the fence of the house.</param>
		/// <param name="size">Size of the fence.</param>
		HouseFence(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
