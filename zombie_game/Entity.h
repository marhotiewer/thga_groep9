#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Drawable.h"
#include "Static.h"

class Entity : public Drawable
{
	public:
		Entity(AssetManager &assets, std::vector<Entity*>& entities, std::vector<Static*>& statics);
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;
		virtual void draw(sf::RenderWindow *window) override;
		sf::Vector2i getSize() override;
		sf::Vector2f getPos() override;
	protected:
		std::vector<Entity*>& entities;
		std::vector<Static*>& statics;
		sf::Vector2f delta;
		sf::Sprite sprite;
};

#endif
