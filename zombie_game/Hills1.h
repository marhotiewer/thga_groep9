#ifndef HILLS1_H
#define HILLS1_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Hills1
/// \brief
/// class of a Hills1
/// \details
/// Class of the normal hills (with no waterfall).
/// \image html hills1.png
class Hills1 : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Hills(1)</param>
		Hills1(AssetManager& assets, sf::Vector2f pos);
		sf::FloatRect getHitbox() override;
};

#endif
