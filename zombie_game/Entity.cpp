#include "Entity.h"

Entity::Entity(AssetManager& assets, std::vector<Entity*>& entities, std::vector<Static*>& statics) : Drawable(assets), entities(entities), statics(statics)
{
	// init
}

void Entity::draw(sf::RenderWindow* window)
{
	window->draw(this->sprite);
}

sf::Vector2f Entity::getPos()
{
	return this->sprite.getPosition();
}

sf::Vector2i Entity::getSize()
{
	return this->sprite.getTextureRect().getSize();
}
