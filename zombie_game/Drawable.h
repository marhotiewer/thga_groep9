#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Drawable
{
	public:
		Drawable(AssetManager& assets);
		virtual void debug_draw(sf::RenderWindow* window, sf::Color color);
		virtual void draw(sf::RenderWindow *window) = 0;
		virtual bool isColliding(Drawable& drawable);
		virtual sf::Vector2i getSize() = 0;
		virtual sf::Vector2f getPos() = 0;
		virtual sf::FloatRect getHitbox();
	protected:
		AssetManager& assets;
};

#endif
