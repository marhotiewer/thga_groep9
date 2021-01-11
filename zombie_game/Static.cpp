#include "Static.h"

Static::Static(AssetManager& assets) : Drawable(assets)
{
	// init
}

void Static::draw(sf::RenderWindow *window)
{
	window->draw(this->sprite);
}

sf::Vector2f Static::getPos()
{
	return this->sprite.getPosition();
}

sf::Vector2i Static::getSize()
{
	return this->sprite.getTextureRect().getSize();
}
