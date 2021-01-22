#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

#include "Static.h"
/// @file


/// \class Wall
/// \brief
/// Wall Class
/// \details
/// The Wall Class is a class for the walls in the game. 
/// The Wall Class has no overriding functions. 
/// All functions are inherited from Static, and Static inherited it's functions from Drawable. 
/// The Texture used for the wall is the wallTexture and is loaded from the AssetManager class. 
class Wall : public Static
{
	public:
		/// <summary>
		/// Constructor for wall.
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">position of the wall</param>
		/// <param name="size">size of the wall</param>
		Wall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
