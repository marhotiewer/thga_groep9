#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <array>

#include "Entity.h"
#include "Player.h"

class Zombie : public Entity
{
	public:
		Zombie(AssetManager& assets, sf::Vector2f pos, std::vector<Drawable*>& objects, Player* player);
		void update(sf::RenderWindow* window, float deltaTime) override;
		void debug_draw(sf::RenderWindow* window) override;
		Drawable* move(sf::Vector2f delta) override;
		sf::FloatRect getHitbox() override;
	private:
		Player* player;
};

#endif
