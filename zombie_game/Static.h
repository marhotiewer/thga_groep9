#ifndef STATIC_H
#define STATIC_H

#include "AssetManager.h"
#include "Drawable.h"

class Static : public Drawable
{
	public:
		Static(AssetManager &assets);
		void draw(sf::RenderWindow *window) override;
		sf::Vector2f getPos() override;
		sf::Vector2i getSize() override;
	protected:
		sf::Sprite sprite;
};

#endif
