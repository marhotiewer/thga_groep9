#include "Bullet.h"

Bullet::Bullet(AssetManager& assets, std::vector<Entity*>& entities, std::vector<Static*>& statics, sf::Vector2f startPos, sf::Vector2f direction, Player* player) : Entity(assets, entities, statics)
{
	this->sprite.setTexture(assets.bulletSprite);
	this->sprite.setPosition(startPos);
	this->direction = direction;
	this->owner = player;
}

void Bullet::update(sf::RenderWindow& window, float deltaTime)
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
	for (Static* _static : this->statics) if (_static->isColliding(*this, this->delta)) this->damage(1);

	for (Entity* _entity : this->entities) {
		if (_entity&& _entity != this && _entity != this->owner && _entity->isAlive() && _entity->isColliding(*this, this->delta)) {
			_entity->damage(1);
			this->damage(1);
		}
	};
	this->delta = delta;
	return nullptr;
}
