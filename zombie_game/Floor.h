#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>
#include "Static.h"

class Floor : public Static
{
	public:
		Floor(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
