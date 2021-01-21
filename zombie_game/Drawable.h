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
			Projectile,///<Can be things like a bullet. 
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
		/// Checks if the object is colliding with a other object returns a boolian. 
		/// This function can check for future moves with the correct delta. 
		/// </summary>
		/// <param name="drawable">Needed to check with other objects. </param>
		/// <param name="delta">diference to new location(futur move). if {0,0}, checks for current position.</param>
		/// <returns>bool if colliding, if true = the object is colliding with other object, if false, the object is not colliding with other object.</returns>
		virtual bool isColliding(Drawable& drawable, sf::Vector2f delta = sf::Vector2f(0.f, 0.f));
		
		/// <summary>
		/// Virtual function used for updating a position, animation, or other things. 
		/// Default function is nothing. Need to be overrided to do something.
		/// </summary>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		virtual void update(float deltaTime) {}
		
		/// <summary>
		/// Draws to the window the outlines of objects, used for debugging purpose.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		virtual void debug_draw(sf::RenderWindow* window);
		
		/// <summary>
		/// draw's the current sprite to the window. 
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		virtual void draw(sf::RenderWindow *window);
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns>Hitbox of the current object</returns>
		virtual sf::FloatRect getHitbox();
		
		/// <summary>
		/// Function to receive damage.
		/// Default function is nothing. Need to be overrided to do something.
		/// </summary>
		/// <param name="dmg">int</param>
		virtual void damage(int dmg) {};
		
		/// <summary>
		/// Function to return size.
		/// </summary>
		/// <returns>size of the object.</returns>
		virtual sf::Vector2i getSize();
		
		/// <summary>
		/// Function to return position.
		/// </summary>
		/// <returns>return position of the current drawable</returns>
		virtual sf::Vector2f getPos();
		
		/// <summary>
		/// If the Type of the Drawable is not currently set. Set the Type to Type::Empty.
		/// need to set in the constructor, of the inherted class.
		/// </summary>
		Type type = Type::Empty;
		
		/// <summary>
		/// function to return if the class is still active. 
		/// Class can become inActive if health is zero.
		/// </summary>
		/// <returns>bool if class still active</returns>
		bool isActive();
	protected:
		AssetManager& assets;///<Reference to AssetManager, where all the textures are stored.
		bool active = true;///<Bool if class still active. Class can become inActive if health is zero.
		sf::Sprite sprite;///<Sprite of the current Drawable.
};

#endif
