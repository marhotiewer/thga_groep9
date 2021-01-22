#ifndef FENCE_H
#define FENCE_H

#include <SFML/Graphics.hpp>

#include "Static.h"

class Fence : public Static
{
	public:
		Fence(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size);
};

#endif
