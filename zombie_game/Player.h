#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Entity.h"

class Player : public Entity
{
	public:
		Player(AssetManager& assets, sf::Vector2f pos);
		void move(sf::Vector2f delta);
		void updateLookDirection(sf::RenderWindow &window);
};

#endif
