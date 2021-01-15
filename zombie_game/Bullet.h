#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

#include "Static.h"
#include "Entity.h"
#include "Player.h"

class Bullet : public Entity
{
	public:
		Bullet(AssetManager& assets, std::vector<Entity*>& entities, std::vector<Static*>& statics, sf::Vector2f startPos, sf::Vector2f direction, Player* player);
		void update(sf::RenderWindow& window, float deltaTime) override;
		Drawable* move(sf::Vector2f delta) override;
	private:
		sf::Vector2f direction;
		Player* owner;
};

#endif
