#ifndef BUSH_H
#define BUSH_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Bush : public Static
{
public:
	Bush(AssetManager& assets, sf::Vector2f pos);
	sf::FloatRect getHitbox() override;
};

#endif
