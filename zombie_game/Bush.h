#ifndef BUSH_H
#define BUSH_H

#include <SFML/Graphics.hpp>
#include "Static.h"
///@file


/// \class Bush
/// \brief
/// Class for a Bush.
/// \details
/// This class creates Bushes.
/// Class is inherited from Static, so it can't move.
/// This class has a override on getHitbox function for it's own hitbox.
/// \image html bush.png
class Bush : public Static
{
	public:
		/// <summary>
		/// Constructor for Bush, for placement of the Buch on the map.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">position of the bush.</param>
		Bush(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Function to return the correct hitbox of the Bush.
		/// So the player can walk behind the Bush.
		/// </summary>
		/// <returns>hitbox of the bush.</returns>
		sf::FloatRect getHitbox() override;
};

#endif
