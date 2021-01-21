#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Drawable.h"
#include "Static.h"
/// @file

// \class Entity
/// \brief
/// Entity Class for movable items
/// \details
/// This class inhert from Drawable. And is a abstract class.
/// This class exists for other classes to inhert for movable items.
/// This class can be a Drawable Type Projectile, Player & Enemy.
class Entity : public Drawable
{
	public:
		/// <summary>
		/// Constructor is empty. Class is used to inhert functions.
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="objects">A vector of pointers of all the Drawable, is used for collision detection.</param>
		Entity(sf::RenderWindow* window, AssetManager& assets, std::vector<Drawable*>& objects) : Drawable(assets), objects(objects), window(window) {}
		
		/// <summary>
		/// Draw the item on the screen. 
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		void draw(sf::RenderWindow* window) override;
		
		/// <summary>
		/// Function to check if a Entity can move to a new position(old position+deta).
		/// </summary>
		/// <param name="delta">Delta is now much difference to new position</param>
		/// <returns>Pointer to drawable if colliding.</returns>
		virtual Drawable* move(sf::Vector2f delta);

		/// <summary>
		/// Function to receive damage. And set the class to not active if health is zero. 
		/// </summary>
		/// <param name="dmg">Number of damage</param>
		virtual void damage(int dmg) override;
	protected:
		std::vector<Drawable*>& objects;///<Vector of all Drawable Objects. Is used for collision detection. 
		sf::RenderWindow* window;
		float deltaTime = 0;///<The time elapsed for one frame.
		sf::Vector2f delta;///<New difference to move to new position. example is x+=1 and y+=1 the newpostion is y+1 and x+1.
		int health = 1;///<Lives for the object. 
		int frame = 0;///<Is used in Zombie class and Player class to select to current frame for the animation of the Zombie and Player.
};

#endif
