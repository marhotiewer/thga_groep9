#include "Bullet.h"

Bullet::Bullet(AssetManager& assets, std::vector<Drawable*>& objects, sf::Vector2f startPos, sf::Vector2f direction) : Entity(assets, objects)
{
	this->sprite.setTexture(assets.bulletSprite);
	this->sprite.setPosition(startPos);
	this->type = Type::Projectile;
	this->direction = direction;
}

void Bullet::update(sf::RenderWindow* window, float deltaTime)
{
	sf::Vector2f distance(this->direction - this->getPos());
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	sf::Vector2f displacement(2.5f * sf::Vector2f(distance.x / length, distance.y / length));

	direction += displacement;
	this->move(displacement);

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.move(this->delta);
		this->delta = { 0.f, 0.f };
	}
}

Drawable* Bullet::move(sf::Vector2f delta)
{
	for (Drawable* object : this->objects) {
		if (object->type != Type::Player && object != this && object->isActive() && object->isColliding(*this, this->delta)) {
			object->damage(1);
			this->damage(1);
		}
	};
	this->delta = delta;
	return nullptr;
}
