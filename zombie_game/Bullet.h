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
/// test
class Bullet : public Entity
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets"></param>
		/// <param name="objects"></param>
		/// <param name="startPos"></param>
		/// <param name="direction"></param>
		Bullet(AssetManager& assets, std::vector<Drawable*>& objects, sf::Vector2f startPos, sf::Vector2f direction);
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		/// <param name="deltaTime"></param>
		void update(sf::RenderWindow* window, float deltaTime) override;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="delta"></param>
		/// <returns></returns>
		Drawable* move(sf::Vector2f delta) override;
	private:
		sf::Vector2f direction;///< test
};

#endif
