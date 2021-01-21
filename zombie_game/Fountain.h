#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Fountain : public Static
{
public:
	Fountain(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
