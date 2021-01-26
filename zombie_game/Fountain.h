#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Fountain
/// \brief
/// Class of a Fountain
/// \details
/// Class used to spawn a Fountain.
/// \image html fountain.png
class Fountain : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Fountain</param>
		Fountain(AssetManager& assets, sf::Vector2f pos);
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
