#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"

class Drawable
{
	public:
		Drawable(AssetManager& assets) : assets(assets) {}
		virtual bool isColliding(Drawable& drawable, sf::Vector2f delta = sf::Vector2f(0.f, 0.f));
		virtual void debug_draw(sf::RenderWindow* window);
		virtual void draw(sf::RenderWindow *window);
		virtual sf::FloatRect getHitbox();
		virtual sf::Vector2i getSize();
		virtual sf::Vector2f getPos();
	protected:
		AssetManager& assets;
		sf::Sprite sprite;
};

#endif
