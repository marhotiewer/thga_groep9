#include "Entity.h"

Entity::Entity(AssetManager& assets, std::vector<Entity*>& entities, std::vector<Static*>& statics) : Drawable(assets), entities(entities), statics(statics)
{
	// init
}

void Entity::move(sf::Vector2f delta)
{
	for (Static* _static : this->statics) {
		if (_static->isColliding(*this, delta)) {
			return;
		}
	};
	for (Entity* _entity : this->entities) {
		if (_entity->isColliding(*this, delta) && _entity != this) {
			return;
		}
	};
	this->delta = delta;
}
