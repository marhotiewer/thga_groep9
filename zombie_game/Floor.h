#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>
#include "Static.h"
/// @file

/// \class Floor
/// \brief
/// Class for floor tiles.
/// \details
/// The Floor Class is a class for the floors in the game. 
/// The Floor Class has one overriding functions(isCoolliding). 
/// All functions are inherited from Static, and Static inherited it's functions from Drawable. 
/// The Texture used for the Floor is the FloorTexture and is loaded from the AssetManager class. 
class Floor : public Static
{
	public:
		/// <summary>
		/// The floor needs a AssetManager to load the texture of the floor. 
		/// The floor also needs a position and a size. To place the floor on the correct spot. 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Floor</param>
		/// <param name="size">Size of the Floor to be placed</param>
		Floor(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
		
		/// <summary>
		/// Overriding isColliding function Floor.
		/// </summary>
		/// <param name="drawable"></param>
		/// <param name="delta"></param>
		/// <returns>Bool if colliding with other object.</returns>
		bool isColliding(Drawable& drawable, sf::Vector2f delta = sf::Vector2f(0.f, 0.f)) override;

		/// <summary>
		/// Function that return the order of draw order.
		/// </summary>
		/// <returns>A 0. Because the floor is always lowest.</returns>
		float Z_Order() override;
};

#endif
