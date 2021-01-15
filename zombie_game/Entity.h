#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Drawable.h"
#include "Static.h"

class Entity : public Drawable
{
	public:
		Entity(AssetManager& assets, std::vector<Entity*>& entities, std::vector<Static*>& statics) : Drawable(assets), entities(entities), statics(statics) {}
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;
		void draw(sf::RenderWindow* window) override;
		virtual Drawable* move(sf::Vector2f delta);
		virtual void damage(int dmg) override;
		bool isAlive();
	protected:
		std::vector<Entity*>& entities;
		std::vector<Static*>& statics;
		float deltaTime = 0;
		sf::Vector2f delta;
		bool alive = true;
		int health = 1;
		int frame = 0;
};

#endif
