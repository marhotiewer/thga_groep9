#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Drawable.h"

class Entity : public Drawable
{
	public:
		Entity(AssetManager &assets);
		void draw(sf::RenderWindow *window) override;
		sf::Vector2f getPos() override;
		sf::Vector2i getSize() override;
		//virtual void update(float deltaTime) = 0;
	protected:
		sf::Sprite sprite;
};

#endif
