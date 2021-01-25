#ifndef WOOD_H
#define WOOD_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Wood : public Static
{
	public:
		Wood(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
