#ifndef SANDBAG_H
#define SANDBAG_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Sandbag : public Static
{
public:
	Sandbag(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
