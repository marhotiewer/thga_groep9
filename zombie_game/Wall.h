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
		/// Constructor
		/// </summary>
		/// <param name="AssetManager"></param>
		/// <param name="position"></param>
		/// <param name="size"></param>
		Wall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
