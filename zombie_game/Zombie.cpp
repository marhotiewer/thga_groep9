#include "Zombie.h"

Zombie::Zombie(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics) : Entity(assets, entities, statics)
{
	this->sprite.setTexture(this->assets.zombieSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 27, 47));
	this->sprite.setPosition(pos);

	this->zombieAnimation = {
		std::array<sf::IntRect, 3> { //up
			sf::IntRect(0, 0, 27, 47),
			sf::IntRect(28, 95, 27, 47),
			sf::IntRect(28, 46, 27, 47)
		},
		std::array<sf::IntRect, 3> { //down
			sf::IntRect(55, 0, 24, 47),
			sf::IntRect(78, 0, 24, 47),
			sf::IntRect(55, 46, 24, 47)
		},
		std::array<sf::IntRect, 3> { //left
			sf::IntRect(102, 93, 29, 47),
			sf::IntRect(102, 46, 29, 47),
			sf::IntRect(102, 0, 29, 47)
		},
		std::array<sf::IntRect, 3> { //right
			sf::IntRect(132, 93, 29, 47),
			sf::IntRect(132, 46, 29, 47),
			sf::IntRect(132, 0, 29, 47)
		}
	};
}

void Zombie::update(sf::RenderWindow& window, float deltaTime)
{
	if (!this->alive) return;

	{
		// Walking animation test
		static bool toggle = false;
		if (this->getPos().x < 600 && !toggle) this->move(sf::Vector2f(1.0f, 0.f));
		else if (!toggle) toggle = !toggle;
		if (this->getPos().x > 15 && toggle) this->move(sf::Vector2f(-1.0f, 0.f));
		else if (toggle) toggle = !toggle;
	}

	int direction = -1;

	if (this->delta.x < 0.f)
		direction = 2;
	else if (this->delta.x > 0.f)
		direction = 3;
	else if (this->delta.y < 0.f)
		direction = 0;
	else if (this->delta.y > 0.f)
		direction = 1;

	this->currentTime += deltaTime;
	if (this->currentTime >= 0.05f) {
		this->currentTime = 0.f;
		this->zombieAnimationIndex++;

		if (this->zombieAnimationIndex == 3) {
			this->zombieAnimationIndex = 0;
		}
	}

	if(direction != -1)
		this->sprite.setTextureRect(this->zombieAnimation[direction][zombieAnimationIndex]);
	else
		this->sprite.setTextureRect(this->zombieAnimation[1][0]);

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.setPosition(this->getPos() + this->delta);
		this->delta = sf::Vector2f(0.f, 0.f);
	}
}

Entity* Zombie::move(sf::Vector2f delta)
{
	if (!this->alive) return nullptr;
	Entity* entity = Entity::move(delta);
	if(entity != nullptr) entity->damage(1);
	return entity;
}
