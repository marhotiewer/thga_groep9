#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#include "Static.h"
#include "Entity.h"
/// @file


/// \class Bullet
/// \brief
/// Bullet Class
/// \details
/// The Bullet class is the class of the Bullet.
/// The textures are loaded from the AssetManager: bulletSprite. 
/// The bullet class inhert from Entity.
/// The bullet disappears if it hits a object. 
/// If the bullet hits a zombie, the zombie will be damaged.
/// The Bullet is a Drawable::Type= Type::Projectile
class Bullet : public Entity
{
	public:
		/// <summary>
		/// In the constructor the texture will be loaded from AssetManager the texture: bulletSprite. 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="objects">Vector of all the drawables, is used for collision detection.</param>
		/// <param name="startPos">The start position of the bullet(spawn location bullet)</param>
		/// <param name="direction">In SFML Vector2f. For example if x = +1 and y =+1. The bullet will go to bottom right corner.</param>
		Bullet(AssetManager& assets, std::vector<Drawable*>& objects, sf::Vector2f startPos, sf::Vector2f direction);
		
		/// <summary>
		/// This function updates the position on the screen. And runs the Bullet::move function to check if it can move to the new location. 
		/// </summary>
		/// <param name="window">The pointer to the current window of the game.</param>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		void update(sf::RenderWindow* window, float deltaTime) override;
		
		/// <summary>
		/// This function checks if the bullet can move to currentposition + delta. If a Zombie is detected, the zombie will get one damage. 
		/// </summary>
		/// <param name="delta"></param>
		/// <returns></returns>
		Drawable* move(sf::Vector2f delta) override;
	private:
		sf::Vector2f direction;///< The direction of the Bullet. Example: if x =+1 and y =+1. The bullet will go to the bottom right corner. 
};

#endif
