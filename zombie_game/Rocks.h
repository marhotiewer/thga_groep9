#ifndef ROCKS_H
#define ROCKS_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class Rocks
/// \brief
/// Class for Rocks.
/// \details
/// Class used for a rock.
/// \image html rocks.png
class Rocks : public Static
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Rocks.</param>
		Rocks(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
};

#endif
