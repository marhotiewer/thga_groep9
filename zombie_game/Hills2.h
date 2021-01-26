#ifndef HILLS2_H
#define HILLS2_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Hills2
/// \brief
/// class of a Hills2
/// \details
/// Class of the hills with waterfall.
/// \image html hills2.png
class Hills2 : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position to place the Hills(2)</param>
		Hills2(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
