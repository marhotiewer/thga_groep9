#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Campfire : public Static
{
public:
	Campfire(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
