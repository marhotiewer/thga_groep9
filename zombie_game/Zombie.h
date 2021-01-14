#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <array>

#include "Entity.h"

class Zombie : public Entity
{
	public:
		Zombie(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics);
		void update(sf::RenderWindow& window, float deltaTime) override;
		Entity* move(sf::Vector2f delta) override;
	private:
		std::array<std::array<sf::IntRect, 3>, 4> zombieAnimation;
		int zombieAnimationIndex = 0;
		float currentTime = 0;
};

#endif
