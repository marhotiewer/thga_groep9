#include "Zombie.h"

Zombie::Zombie(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics, Player* player) : Entity(assets, entities, statics), player(player)
{
	this->sprite.setTexture(this->assets.zombieSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 27, 47));
	this->sprite.setPosition(pos);

	this->zombieAnimation = {
		std::array<sf::IntRect, 3> { //up
			sf::IntRect(0, 148, 34, 49),
			sf::IntRect(34, 148, 34, 49),
			sf::IntRect(69, 148, 34, 49)
		},
		std::array<sf::IntRect, 3> { //down
			sf::IntRect(0, 0, 34, 49),
			sf::IntRect(34, 0, 34, 49),
			sf::IntRect(69, 0, 34, 49)
		},
		std::array<sf::IntRect, 3> { //left
			sf::IntRect(0, 49, 34, 49),
			sf::IntRect(34, 49, 34, 49),
			sf::IntRect(69, 49, 34, 49)
		},
		std::array<sf::IntRect, 3> { //right
			sf::IntRect(0, 99, 34, 49),
			sf::IntRect(34, 99, 34, 49),
			sf::IntRect(69, 99, 34, 49)
		}
	};
}

void Zombie::debug_draw(sf::RenderWindow* window)
{
	if (!this->alive) return;
	Drawable::debug_draw(window);

	sf::Vertex line1[] = {
		sf::Vertex(this->getPos() + sf::Vector2f(this->getSize()) / 2.f, sf::Color::Cyan),
		sf::Vertex(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Color::Cyan)
	};

	window->draw(line1, 2, sf::Lines);
}

void Zombie::update(sf::RenderWindow& window, float deltaTime)
{
	if (!this->alive) return;

	sf::Vector2f distance(this->player->getPos() - this->getPos());
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	this->move({distance.x / length, distance.y / length});

	int direction = -1;

	if (this->delta.x < 0.f)		direction = 2; // facing left
	else if (this->delta.x > 0.f)	direction = 3; // facing right
	else if (this->delta.y < 0.f)	direction = 0; // facing up
	else if (this->delta.y > 0.f)	direction = 1; // facing down

	this->currentTime += deltaTime;
	if (this->currentTime >= 0.05f) {
		this->currentTime = 0.f;
		this->zombieAnimationIndex++;

		if (this->zombieAnimationIndex == 3) {
			this->zombieAnimationIndex = 0;
		}
	}

	if(direction != -1) this->sprite.setTextureRect(this->zombieAnimation[direction][zombieAnimationIndex]);
	else this->sprite.setTextureRect(this->zombieAnimation[1][0]);

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.setPosition(this->getPos() + this->delta);
		this->delta = sf::Vector2f(0.f, 0.f);
	}
}

Entity* Zombie::move(sf::Vector2f delta)
{
	if (!this->alive) return nullptr;
	Entity* entity = Entity::move(delta);
	if(entity == this->player) entity->damage(1);
	return entity;
}

sf::FloatRect Zombie::getHitbox()
{
	sf::Vector2f spriteSize(this->getSize());
	sf::Vector2f spritePos(this->getPos());
	sf::Vector2f hitBoxSize(25, 15);

	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
