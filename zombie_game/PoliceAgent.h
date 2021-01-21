#ifndef POLICEAGENT_H
#define POLICEAGENT_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class PoliceAgent : public Static
{
public:
	PoliceAgent(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
