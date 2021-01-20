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
/// This class inhert from Drawable.
/// This class exists for other classes to inhert for movable items.
/// This class can be a Drawable Type Projectile, Player & Enemy.
class Entity : public Drawable
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="objects">A vector of pointers of all the objects that are of one type.</param>
		Entity(AssetManager& assets, std::vector<Drawable*>& objects) : Drawable(assets), objects(objects) {}	
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		/// <param name="deltaTime"></param>
		virtual void update(sf::RenderWindow* window, float deltaTime) = 0;
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		void draw(sf::RenderWindow* window) override;
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="delta"></param>
		/// <returns></returns>
		virtual Drawable* move(sf::Vector2f delta);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="dmg"></param>
		virtual void damage(int dmg) override;
	protected:
		std::vector<Drawable*>& objects;///<
		float deltaTime = 0;///<
		sf::Vector2f delta;///<
		int health = 1;///<
		int frame = 0;///<
};

#endif
