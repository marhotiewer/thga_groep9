#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include "Static.h"

class Wall : public Static
{
	public:
		Wall(AssetManager& assets, sf::Vector2f pos, sf::Vector2f size);
};

#endif
