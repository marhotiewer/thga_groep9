#ifndef POLICEAGENT_H
#define POLICEAGENT_H

#include <SFML/Graphics.hpp>

#include "Static.h"
//@file


/// \class PoliceAgent
/// \brief
/// Class for a PoliceAgent.
/// \details
/// Class used in the map to spawn a PoliceAgent.
/// Class is inherited from Static, so it can't move.
/// \image html policeAgent.png
class PoliceAgent : public Static
{
	public:
		/// <summary>
		/// Constructor of the Police agent.
		/// </summary>
		/// <param name="assets">AssetManager required for textures.</param>
		/// <param name="pos">Position of the Police agent.</param>
		PoliceAgent(AssetManager& assets, sf::Vector2f pos);

		/// <summary>
		/// Return the correct hitbox of the police agent.
		/// </summary>
		/// <returns>SFML FloatRect of the police agent</returns>
		sf::FloatRect getHitbox() override;
};

#endif
