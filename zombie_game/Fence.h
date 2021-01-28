#ifndef FENCE_H
#define FENCE_H

#include <SFML/Graphics.hpp>
#include "Static.h"
///@file


/// \class Fence
/// \brief
/// Class of a Fence
/// \details
/// Fence class used in the map for a fence.
/// Class is inherited from Static, so it can't move.
/// \image html fence.png
class Fence : public Static
{
	public:
		/// <summary>
		/// Constructor of the Fence. Loads the texture of the Fence and set it in the map.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Fence.</param>
		/// <param name="size">Size of the Fence</param>
		Fence(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
