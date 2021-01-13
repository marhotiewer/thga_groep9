#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <array>
#include "AssetManager.h"
#include "Entity.h"

class Player : public Entity
{
	public:
		Player(AssetManager& assets, sf::Vector2f pos);
		void update(sf::RenderWindow& window, float deltaTime);
		void move(sf::Vector2f delta);
	private:
		float currentTime = 0;
		int counter = 0;

		int direction = 0;
		int mode = 0;

		std::array<std::array<std::array<sf::IntRect, 6>, 2>, 4> playerAnimation;
};

#endif
