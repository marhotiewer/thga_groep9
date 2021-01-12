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

		std::array<sf::IntRect, 9> playerForward;
		std::array<sf::IntRect, 9> playerLeft;
		std::array<sf::IntRect, 9> playerRight;
		std::array<sf::IntRect, 9> playerDown;
};

#endif
