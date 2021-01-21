#ifndef SHED_H
#define SHED_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Shed : public Static
{
public:
	Shed(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
