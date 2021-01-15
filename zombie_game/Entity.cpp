#include "Entity.h"

Drawable* Entity::move(sf::Vector2f delta)
{
	Drawable* drawable = nullptr;
	for (Drawable* object : this->objects) {
		if (object != this && object->isActive() && object->type != Type::Projectile && object->isColliding(*this, delta)) {
			if (object->isColliding(*this, sf::Vector2f(delta.x, 0.f))) delta.x = 0.f;
			if (object->isColliding(*this, sf::Vector2f(0.f, delta.y))) delta.y = 0.f;
			drawable = object;
		}
	};
	this->delta = delta;
	return drawable;
}

void Entity::damage(int dmg)
{
	if ((this->health -= dmg) <= 0) {
		this->active = false;
	}
}

void Entity::draw(sf::RenderWindow* window)
{
	Drawable::draw(window);
}
