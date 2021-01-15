#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>

#include "AssetManager.h"
#include "Entity.h"

class Player : public Entity
{
	public:
		Player(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics);
		void debug_draw(sf::RenderWindow* window) override;
		void update(sf::RenderWindow& window, float deltaTime) override;
		sf::FloatRect getHitbox() override;
};

#endif
