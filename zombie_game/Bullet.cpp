#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow* window, AssetManager& assets, std::vector<Drawable*>& objects, sf::Vector2f startPos, sf::Vector2f direction) : Entity(window, assets, objects)
{
	this->sprite.setTexture(assets.bulletSprite);
	this->sprite.setPosition(startPos);
	this->type = Type::Projectile;
	this->direction = direction;
}

void Bullet::update(float deltaTime)
{
	sf::Vector2f distance(this->direction - this->getPos());
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	sf::Vector2f displacement(2.5f * sf::Vector2f(distance.x / length, distance.y / length));

	direction += displacement;
	this->move(displacement);

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.move(deltaTime * this->delta * 100.f);
		this->delta = { 0.f, 0.f };
	}
}

Drawable* Bullet::move(sf::Vector2f delta)
{
	this->delta = delta;
	for (Drawable* object : this->objects) {
		if (object->type != Type::Player && object != this && object->isActive() && object->isColliding(*this, this->delta)) {
			object->damage(10);
			this->damage(1);
			return object;
		}
	};
	return nullptr;
}
