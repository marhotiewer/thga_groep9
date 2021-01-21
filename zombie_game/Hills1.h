#ifndef HILLS1_H
#define HILLS1_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Hills1 : public Static
{
public:
	Hills1(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
