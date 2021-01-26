#ifndef LAMP_H
#define LAMP_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Lamp
/// \brief
/// Class for Street lights.
/// \details
/// Class used in the map for Static Street lights.
/// \image html lamp.png
class Lamp : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Lamp.</param>
		Lamp(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns>hitbox of the Street light</returns>
		sf::FloatRect getHitbox() override;
};

#endif
