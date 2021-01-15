#include "Zombie.h"

Zombie::Zombie(sf::Vector2f pos, Player* player, AssetManager& assets, std::vector<Drawable*>& objects) : Entity(assets, objects), player(player)
{
	this->sprite.setTexture(this->assets.zombieSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	this->sprite.setPosition(pos);
	this->type = Type::Enemy;
	this->health = 10;
}

void Zombie::debug_draw(sf::RenderWindow* window)
{
	Drawable::debug_draw(window);

	if (this->player->isActive()) {
		sf::Vertex line1[] = {
			sf::Vertex(this->getPos() + sf::Vector2f(this->getSize()) / 2.f, sf::Color::Cyan),
			sf::Vertex(this->player->getPos() + sf::Vector2f(this->player->getSize()) / 2.f, sf::Color::Cyan)
		};
		window->draw(line1, 2, sf::Lines);
	}
}

void Zombie::update(sf::RenderWindow* window, float deltaTime)
{
	sf::Vector2f distance(this->player->getPos() - this->getPos());
	float length = sqrt((distance.x * distance.x) + (distance.y * distance.y));
	this->move({distance.x / length, distance.y / length});

	int direction = 0;	// default = facing towards you

	if (this->delta.x < 0.f)		direction = 1; // facing left
	else if (this->delta.x > 0.f)	direction = 2; // facing right
	else if (this->delta.y < 0.f)	direction = 3; // facing up
	else if (this->delta.y > 0.f)	direction = 0; // facing down

	if ((this->deltaTime += deltaTime) >= 0.05f) {
		if (++this->frame == 3) this->frame = 0;
		this->sprite.setTextureRect({ this->frame * 35, direction * 50, 34, 49 });
		this->deltaTime = 0.f;
	}
	
	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.move(this->delta);
		this->delta = { 0.f, 0.f };
	}
}

Drawable* Zombie::move(sf::Vector2f delta)
{
	Drawable* object = Entity::move(delta);
	if(object == this->player) object->damage(1);
	return object;
}

sf::FloatRect Zombie::getHitbox()
{
	sf::Vector2f spriteSize(this->getSize());
	sf::Vector2f spritePos(this->getPos());
	sf::Vector2f hitBoxSize(25, 15);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
