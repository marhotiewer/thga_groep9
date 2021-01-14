#include "Entity.h"

bool Entity::move(sf::Vector2f delta)
{
	for (Static* _static : this->statics) {
		if (_static->isColliding(*this, sf::Vector2f(delta.x, 0.f))) delta.x = 0.f;
		if (_static->isColliding(*this, sf::Vector2f(0.f, delta.y))) delta.y = 0.f;
	};
	for (Entity* _entity : this->entities) {
		if (_entity != this) {
			if (_entity->isColliding(*this, sf::Vector2f(delta.x, 0.f))) {
				//if (_entity->move(sf::Vector2f(delta.x, 0.f))) return false;
				delta.x = 0.f;
			}
			if (_entity->isColliding(*this, sf::Vector2f(0.f, delta.y))) {
				//if (_entity->move(sf::Vector2f(0.f, delta.y))) return false;
				delta.y = 0.f;
			}
		}
	};
	this->delta = delta;
	return true;
}
