#ifndef INVISIBLEWALL_H
#define INVISIBLEWALL_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class InvisibleWall : public Static
{
public:
	InvisibleWall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
