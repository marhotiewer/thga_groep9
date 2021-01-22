#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>

#include "Static.h"
/// @file


/// \class Tree
/// \brief
/// Tree Class
/// \details
/// The Tree Class is a class for the Trees in the game. 
/// All functions are inherited from Static, and Static inherited it's functions from Drawable. 
/// The function getHitbox is overrided because the hitbox is different because the Player and Zombie can walk behind a tree.
/// The Texture used for the Tree is the TreeTexture and is loaded from the AssetManager class. 
/// \image html tree.png
class Tree : public Static
{
public:
	/// <summary>
	/// The Tree class need the AssetManager for the tree texture. 
	/// The Tree class needs a position to place the tree in the correct position.
	/// </summary>
	/// <param name="assets">AssetManager required for textures</param>
	/// <param name="pos">The position of the Tree.</param>
	Tree(AssetManager& assets, sf::Vector2f pos);
	
	/// <summary>
	/// The function return a SFML hitbox for the Tree. 
	/// This hitbox differed from the inherited hitbox function from Static. Because the Player and the Zombie can walk behind a tree. 
	/// </summary>
	/// <returns>a SFML FloatRect (sf::FloatRect) with the correct hitbox of the tree.</returns>
	sf::FloatRect getHitbox() override;
};

#endif
