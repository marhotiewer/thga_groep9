#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <array>

#include "AssetManager.h"
#include "Entity.h"

class Player : public Entity
{
	public:
		Player(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics);
		void debug_draw(sf::RenderWindow* window, sf::Color color) override;
		void update(sf::RenderWindow& window, float deltaTime);
		sf::FloatRect getHitbox() override;
	private:
		std::array<std::array<std::array<sf::IntRect, 6>, 2>, 4> playerAnimation;
		int playerAnimationIndex = 0;
		float currentTime = 0;
};

#endif
