#ifndef SHED_H
#define SHED_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Shed
/// \brief
/// Class for a Shed.
/// \details
/// Class used for a Shed.
/// \image html shed.png
class Shed : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Shed.</param>
		Shed(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
