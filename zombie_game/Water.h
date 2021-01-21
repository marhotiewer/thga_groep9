#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Water : public Static
{
public:
	Water(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
