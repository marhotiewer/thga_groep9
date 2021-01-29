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
/// Class is inherited from Static, so it can't move.
/// \image html sandbag.png
class Sandbag : public Static
{
	public:
		/// <summary>
		/// Constructor of a Sandbag.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Sandbag.</param>
		Sandbag(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// The function return a SFML hitbox for the Sandbag. 
		/// This hitbox differed from the inherited hitbox function from Static. Because the Player and the Zombie can walk behind a Sandbag. 
		/// </summary>
		/// <returns>a SFML FloatRect (sf::FloatRect) with the correct hitbox of the Sandbag.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
