#ifndef TENT_H
#define TENT_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Tent : public Static
{
	public:
		Tent(AssetManager& assets, sf::Vector2f pos);
		sf::FloatRect getHitbox() override;
};

#endif
