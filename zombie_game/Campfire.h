#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include <SFML/Graphics.hpp>

#include "Static.h"
///@file


/// \class Campfire
/// \brief
/// Class of a Campfire
/// \details
/// This class creates a Campfire.
/// This is a Static class that dont move. 
/// This class has a override on getHitbox function for it's own hitbox.
/// \image html campfire.png
class Campfire : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">position of the Campfire.</param>
		Campfire(AssetManager& assets, sf::Vector2f pos);
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
