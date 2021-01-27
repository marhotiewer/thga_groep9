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
/// Class is inherited from Static, so it can't move.
/// \image html tent.png
class Tent : public Static
{
	public:
		/// <summary>
		/// Constructor of Tent
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Tent.</param>
		Tent(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// The function return a SFML hitbox for the Tent. 
		/// This hitbox differed from the inherited hitbox function from Static. Because the Player and the Zombie can walk behind a Tent. 
		/// </summary>
		/// <returns>a SFML FloatRect (sf::FloatRect) with the correct hitbox of the Tent.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
