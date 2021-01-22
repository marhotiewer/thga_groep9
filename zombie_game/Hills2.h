#ifndef HILLS2_H
#define HILLS2_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Hills2 : public Static
{
	public:
		Hills2(AssetManager& assets, sf::Vector2f pos);
		sf::FloatRect getHitbox() override;
};

#endif
