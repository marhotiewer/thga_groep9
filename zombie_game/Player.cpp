#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos, std::vector<Drawable*>& objects) : Entity(assets, objects)
{
	this->sprite.setTexture(this->assets.adamSpriteMap);
	this->sprite.setTextureRect({ (0 * 192) + this->frame * 32, 80, 32, 48 });
	this->sprite.setPosition(pos);
	this->type = Type::Player;
	this->health = 10;
}

void Player::debug_draw(sf::RenderWindow* window)
{
	Drawable::debug_draw(window);

	sf::Vertex cross_line1[] = {
		sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, 0)).x, window->mapPixelToCoords(sf::Vector2i(0, 0)).y), sf::Color::Red),
		sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(window->getSize().x, window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(window->getSize().x, window->getSize().y)).y), sf::Color::Red)
	};
	sf::Vertex cross_line2[] = {
		sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(window->getSize().x, 0)).x, window->mapPixelToCoords(sf::Vector2i(window->getSize().x, 0)).y), sf::Color::Red),
		sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(0, window->getSize().y)).y), sf::Color::Red)
	};

	window->draw(cross_line1, 2, sf::Lines);
	window->draw(cross_line2, 2, sf::Lines);
}

sf::FloatRect Player::getHitbox()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(25, 15);

	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}

void Player::shoot(sf::Vector2f direction)
{
	this->objects.push_back(new Bullet(this->assets, this->objects, this->getPos() + sf::Vector2f(this->getSize()) / 2.f, direction));
}

void Player::update(sf::RenderWindow* window, float deltaTime)
{
	sf::Vector2f playerPos = (this->getPos()) + sf::Vector2f(this->getSize()) / 2.f;
	sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition(*window));

	int anglediff = (int(atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x) * 57.29577951308232286f) + 180 + 360) % 360 - 180;
	int direction = 3, mode = 80;	// default = idle, facing towards you
	float timeStep = 0.15f;			// default = idle speed

	if (anglediff <= 45 && anglediff >= -45)		direction = 0; // facing right
	else if (anglediff <= -45 && anglediff >= -145) direction = 1; // facing up
	else if (anglediff <= 145 && anglediff >= -145)	direction = 3; // facing down
	else											direction = 2; // facing left

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		timeStep = 0.05f;	// walking speed
		mode = 144;			// walking animation

		if (this->delta.x >  1.f || this->delta.y >	 1.f ||
			this->delta.x < -1.f || this->delta.y < -1.f)
				timeStep = 0.04f; // running speed
	}

	if ((this->deltaTime+=deltaTime) >= timeStep) {
		if (++this->frame == 6) this->frame = 0;
		this->sprite.setTextureRect({ (direction * 192) + this->frame * 32, mode, 32, 48 });
		this->deltaTime = 0.f;
	}

	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		sf::View view = window->getView();
		this->sprite.move(deltaTime * this->delta * 100.f);
		view.move(deltaTime * this->delta * 100.f);
		window->setView(view);
		this->delta = { 0.f, 0.f };
	}
}
