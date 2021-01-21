#ifndef ROCKS_H
#define ROCKS_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Rocks : public Static
{
public:
	Rocks(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
