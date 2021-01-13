#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos) : Entity(assets)
{
	this->sprite.setTexture(assets.skeletonSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(17, 15, 30, 46));
	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(pos);

	this->playerForward = {
		sf::IntRect(17,  15, 30, 47),
		sf::IntRect(81,  15, 30, 46),
		sf::IntRect(145, 15, 30, 46),
		sf::IntRect(209, 15, 30, 46),
		sf::IntRect(273, 15, 30, 47),
		sf::IntRect(337, 15, 30, 46),
		sf::IntRect(401, 15, 30, 47),
		sf::IntRect(465, 15, 30, 47),
		sf::IntRect(529, 15, 30, 47)
	};

	this->playerDown = {
		sf::IntRect(17,  143, 30, 47),
		sf::IntRect(81,  143, 30, 47),
		sf::IntRect(145, 143, 30, 47),
		sf::IntRect(209, 143, 30, 47),
		sf::IntRect(273, 143, 30, 47),
		sf::IntRect(337, 143, 30, 47),
		sf::IntRect(401, 143, 30, 47),
		sf::IntRect(465, 143, 30, 47),
		sf::IntRect(529, 143, 30, 47)
	};

	this->playerLeft = {
		sf::IntRect(23,  79, 20, 47),
		sf::IntRect(83,  80, 25, 46),
		sf::IntRect(149, 79, 21, 46),
		sf::IntRect(215, 79, 22, 46),
		sf::IntRect(278, 79, 24, 47),
		sf::IntRect(340, 80, 28, 46),
		sf::IntRect(407, 79, 23, 47),
		sf::IntRect(471, 79, 22, 47),
		sf::IntRect(535, 79, 21, 47)
	};

	this->playerRight = {
		sf::IntRect(21,  207, 20, 47),
		sf::IntRect(84,  208, 25, 46),
		sf::IntRect(150, 207, 21, 46),
		sf::IntRect(211, 207, 22, 46),
		sf::IntRect(274, 207, 24, 47),
		sf::IntRect(336, 208, 28, 46),
		sf::IntRect(402, 207, 23, 47),
		sf::IntRect(467, 207, 22, 47),
		sf::IntRect(532, 207, 21, 47)
	};
}

void Player::move(sf::Vector2f delta)
{
	this->delta = delta;
}

void Player::update(sf::RenderWindow& window, float deltaTime)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2f playerPos = this->getPos();

	int angle = int(atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x) * 57.29577951308232286f);
	int anglediff = (angle + 180 + 360) % 360 - 180;

	if (anglediff <= 45 && anglediff >= -45) {
		// facing right
		this->sprite.setTextureRect(this->playerRight[counter]);
	}
	else if (anglediff <= -45 && anglediff >= -145) {
		// facing up
		this->sprite.setTextureRect(this->playerForward[counter]);
	}
	else if (anglediff <= 145 && anglediff >= -145) {
		// facing down
		this->sprite.setTextureRect(this->playerDown[counter]);
	}
	else {
		// facing left
		this->sprite.setTextureRect(this->playerLeft[counter]);
	}

	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(this->getPos());

	sf::View view = window.getView();
	view.move(this->delta);
	window.setView(view);

	currentTime += deltaTime;
	if (currentTime >= 0.05f && delta != sf::Vector2f(0.f, 0.f)) {
		currentTime = 0.f;
		counter++;
		if (counter >= 9) {
			counter = 0;
		}
	}
	else if (this->delta == sf::Vector2f(0.f, 0.f)) {
		counter = 0;
	}
}
