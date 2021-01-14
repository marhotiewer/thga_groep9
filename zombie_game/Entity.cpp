#include "Entity.h"

Entity* Entity::move(sf::Vector2f delta)
{
	Entity* drawable = nullptr;

	if (this->alive) {
		for (Static* _static : this->statics) {
			if (_static->isColliding(*this, sf::Vector2f(delta.x, 0.f))) delta.x = 0.f;
			if (_static->isColliding(*this, sf::Vector2f(0.f, delta.y))) delta.y = 0.f;
		};
		for (Entity* _entity : this->entities) {
			if (_entity != this) {
				if (_entity->isColliding(*this, sf::Vector2f(delta.x, 0.f))) {
					//if (_entity->move(sf::Vector2f(delta.x, 0.f))) return false;
					drawable = _entity;
					delta.x = 0.f;
				}
				if (_entity->isColliding(*this, sf::Vector2f(0.f, delta.y))) {
					//if (_entity->move(sf::Vector2f(0.f, delta.y))) return false;
					drawable = _entity;
					delta.y = 0.f;
				}
			}
		};
		this->delta = delta;
	}

	return drawable;
}

void Entity::draw(sf::RenderWindow* window)
{
	if (this->alive) {
		Drawable::draw(window);
	}
}

void Entity::damage(int dmg)
{
	if (this->alive) {
		this->health -= dmg;
		this->alive = health >= 0;
	}
}

bool Entity::isAlive()
{
	return this->alive;
}
