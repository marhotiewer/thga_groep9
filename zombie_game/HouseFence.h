#ifndef HOUSEFENCE_H
#define HOUSEFENCE_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class HouseFence : public Static
{
	public:
		HouseFence(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
