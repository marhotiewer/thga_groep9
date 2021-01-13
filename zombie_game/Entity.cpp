#include "Entity.h"

Entity::Entity(AssetManager& assets) : Drawable(assets)
{
	// init
}

void Entity::draw(sf::RenderWindow* window)
{
	window->draw(this->sprite);
}

sf::Vector2f Entity::getPos()
{
	return this->sprite.getPosition() + this->delta;
}

sf::Vector2i Entity::getSize()
{
	return this->sprite.getTextureRect().getSize();
}
