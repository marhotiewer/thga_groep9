#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>

#include "AssetManager.h"
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
	public:
		Player(AssetManager& assets, sf::Vector2f pos, std::vector<Drawable*>& object);
		void update(sf::RenderWindow* window, float deltaTime) override;
		void debug_draw(sf::RenderWindow* window) override;
		sf::FloatRect getHitbox() override;
		void shoot(sf::Vector2f direction);
	private:
		sf::Sound walkingSound;
};

#endif
