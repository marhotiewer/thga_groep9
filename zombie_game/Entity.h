#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Drawable.h"
#include "Static.h"

class Entity : public Drawable
{
	public:
		Entity(AssetManager& assets, std::vector<Drawable*>& objects) : Drawable(assets), objects(objects) {}
		virtual void update(sf::RenderWindow* window, float deltaTime) = 0;
		void draw(sf::RenderWindow* window) override;
		virtual Drawable* move(sf::Vector2f delta);
		virtual void damage(int dmg) override;
	protected:
		std::vector<Drawable*>& objects;
		float deltaTime = 0;
		sf::Vector2f delta;
		int health = 1;
		int frame = 0;
};

#endif
