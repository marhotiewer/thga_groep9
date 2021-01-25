#ifndef PERK1_H
#define PERK1_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Perk1 : public Static
{
	public:
		Perk1(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
