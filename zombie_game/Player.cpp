#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos) : Entity(assets)
{
	this->sprite.setTexture(assets.skeletonSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(17, 15, 30, 46));
	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(pos);
}

void Player::move(sf::Vector2f delta)
{
	this->sprite.setPosition(this->getPos()+delta);
}

#include <iostream>

void Player::updateLookDirection(sf::RenderWindow &window)
{
	sf::Vector2f playerPos = this->getPos();
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	int angle = int(atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x) * 57.29577951308232286f);
	int anglediff = (angle + 180 + 360) % 360 - 180;

	if (anglediff <= 45 && anglediff >= -45) {
		// facing right
		this->sprite.setTextureRect(sf::IntRect(21, 207, 20, 47));
	}
	else if (anglediff <= -45 && anglediff >= -145) {
		// facing up
		this->sprite.setTextureRect(sf::IntRect(17, 15, 30, 46));
	}
	else if (anglediff <= 145 && anglediff >= -145) {
		// facing down
		this->sprite.setTextureRect(sf::IntRect(17, 143, 30, 47));
	}
	else {
		// facing left
		this->sprite.setTextureRect(sf::IntRect(23, 79, 20, 47));
	}
	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
}
