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
/// Class is inherited from Static, so it can't move.
/// \image html shed.png
class Shed : public Static
{
	public:
		/// <summary>
		/// Constructor of the Shed.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Shed.</param>
		Shed(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// The function return a SFML hitbox for the Shed. 
		/// This hitbox differed from the inherited hitbox function from Static. Because the Player and the Zombie can walk along the Shed.
		/// </summary>
		/// <returns>a SFML FloatRect (sf::FloatRect) with the correct hitbox of the Shed.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
