#ifndef INVISIBLEWALL_H
#define INVISIBLEWALL_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class InvisibleWall
/// \brief
/// Class of the Invisible Wall.
/// \details
/// Class used for invisibe Walls.
/// \image html invisible.png
class InvisibleWall : public Static
{
	public:
		/// <summary>
		/// Constructor of the Invisible wall class.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the place of the invissibleWall.</param>
		/// <param name="size">Size of the invissibleWall.</param>
		InvisibleWall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
