#ifndef TENT_H
#define TENT_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Tent
/// \brief
/// Class for a Tent.
/// \details
/// Class used for spawning Tent.
/// \image html tent.png
class Tent : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Tent.</param>
		Tent(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
