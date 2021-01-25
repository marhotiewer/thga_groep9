#ifndef BUSHROTATED_H
#define BUSHROTATED_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class BushRotated : public Static
{
	public:
		BushRotated(AssetManager& assets, sf::Vector2f pos);
		sf::FloatRect getHitbox() override;
};

#endif
