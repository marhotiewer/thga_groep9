#include "Entity.h"

Drawable* Entity::move(sf::Vector2f delta)
{
	Drawable* drawable = nullptr;
	for (Static* _static : this->statics) {
		if (_static->isColliding(*this, sf::Vector2f(delta.x, 0.f))) {
			drawable = _static;
			delta.x = 0.f;
		}
		if (_static->isColliding(*this, sf::Vector2f(0.f, delta.y))) {
			drawable = _static;
			delta.y = 0.f;
		}
	};
	for (Entity* _entity : this->entities) {
		if (_entity != this && _entity->isAlive()) {
			if (_entity->isColliding(*this, sf::Vector2f(delta.x, 0.f))) {
				drawable = _entity;
				delta.x = 0.f;
			}
			if (_entity->isColliding(*this, sf::Vector2f(0.f, delta.y))) {
				drawable = _entity;
				delta.y = 0.f;
			}
		}
	};
	this->delta = delta;
	return drawable;
}

void Entity::damage(int dmg)
{
	if ((this->health -= dmg) <= 0) {
		this->alive = false;
	}
}

void Entity::draw(sf::RenderWindow* window)
{
	Drawable::draw(window);
}

bool Entity::isAlive()
{
	return this->alive;
}
