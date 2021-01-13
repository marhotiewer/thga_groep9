#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Drawable.h"

class Entity : public Drawable
{
	public:
		Entity(AssetManager &assets);
		virtual void update(sf::RenderWindow& window, float deltaTime) = 0;
		void draw(sf::RenderWindow *window) override;
		sf::Vector2i getSize() override;
		sf::Vector2f getPos() override;
	protected:
		sf::Vector2f delta;
		sf::Sprite sprite;
};

#endif
