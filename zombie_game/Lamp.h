#ifndef LAMP_H
#define LAMP_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Lamp : public Static
{
	public:
		Lamp(AssetManager& assets, sf::Vector2f pos);
		sf::FloatRect getHitbox() override;
};

#endif
