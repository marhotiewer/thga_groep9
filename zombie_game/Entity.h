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
		virtual bool move(sf::Vector2f delta);
	protected:
		std::vector<Entity*>& entities;
		std::vector<Static*>& statics;
		sf::Vector2f delta;
};

#endif
