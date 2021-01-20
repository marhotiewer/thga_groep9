#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
/// @file

/// \class Drawable
/// \brief
/// Drawable
/// \details
/// The class Drawable 
/// If a class need a texture from the asset manager, the asset manager need to given by the class by reference. 
/// The image files are in the AssetManager.cpp file. 
/// The asset manager is created in Game.cpp.
class Drawable
{
	public:
		/// \enum Type
		/// /brief Enum that state the state of that drawable, like it is a Static item or a Zombie, etc. 
		enum class Type
		{
			Projectile,///<Can things be like a bullet. 
			Player,///<The player is the player on the screen.
			Static,///<Static items are items that can't move. 
			Enemy,///<Enemy's must be beaten by the player.
			Empty///<Everything other than the other types.
		};
		/// <summary>
		/// The Drawable required a AssetManager. 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		Drawable(AssetManager& assets) : assets(assets) {}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="drawable"></param>
		/// <param name="delta"></param>
		/// <returns></returns>
		virtual bool isColliding(Drawable& drawable, sf::Vector2f delta = sf::Vector2f(0.f, 0.f));
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		/// <param name="deltaTime"></param>
		virtual void update(sf::RenderWindow* window, float deltaTime) {}
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		virtual void debug_draw(sf::RenderWindow* window);
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window"></param>
		virtual void draw(sf::RenderWindow *window);
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual sf::FloatRect getHitbox();
		/// <summary>
		/// 
		/// </summary>
		/// <param name="dmg">int</param>
		virtual void damage(int dmg) {};
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		virtual sf::Vector2i getSize();
		/// <summary>
		/// 
		/// </summary>
		/// <returns>return position of the current drawable</returns>
		virtual sf::Vector2f getPos();
		/// <summary>
		/// If the Type of the Drawable is not currently set. Set the Type to Type::Empty.
		/// </summary>
		Type type = Type::Empty;
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		bool isActive();
	protected:
		AssetManager& assets;///<
		bool active = true;///<
		sf::Sprite sprite;///<
};

#endif
