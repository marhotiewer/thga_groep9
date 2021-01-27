#ifndef SANDBAG_H
#define SANDBAG_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Sandbag
/// \brief
/// Class for Sandbag.
/// \details
/// Class used for a Sandbag.
/// \image html sandbag.png
class Sandbag : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Sandbag.</param>
		Sandbag(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
