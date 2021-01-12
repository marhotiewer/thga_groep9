#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos) : Entity(assets)
{
	this->sprite.setTexture(assets.skeletonSpriteMap);
	this->playerForward[0] = sf::IntRect(17, 15, 30, 47); this->playerForward[1] = sf::IntRect(81, 15, 30, 47); this->playerForward[2] = sf::IntRect(145, 15, 30, 47); this->playerForward[3] = sf::IntRect(209, 15, 30, 46); this->playerForward[4] = sf::IntRect(273, 15, 30, 46); this->playerForward[5] = sf::IntRect(337, 15, 30, 46); this->playerForward[6] = sf::IntRect(401, 15, 30, 46); this->playerForward[7] = sf::IntRect(465, 15, 30, 46); this->playerForward[8] = sf::IntRect(529, 15, 30, 46);
	this->playerDown[0] = sf::IntRect(17, 143, 30, 47); this->playerDown[1] = sf::IntRect(81, 143, 30, 47); this->playerDown[2] = sf::IntRect(145, 143, 30, 47); this->playerDown[3] = sf::IntRect(209, 143, 30, 47); this->playerDown[4] = sf::IntRect(273, 143, 30, 47); this->playerDown[5] = sf::IntRect(337, 143, 30, 47); this->playerDown[6] = sf::IntRect(401, 143, 30, 47); this->playerDown[7] = sf::IntRect(465, 143, 30, 47); this->playerDown[8] = sf::IntRect(529, 143, 30, 47);
	this->sprite.setTextureRect(sf::IntRect(17, 15, 30, 46));
	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(pos);
}

void Player::move(sf::Vector2f delta)
{
	this->delta = delta;
}

#include <iostream>

void Player::update(sf::RenderWindow& window, float deltaTime)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2f playerPos = this->getPos();

	int angle = int(atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x) * 57.29577951308232286f);
	int anglediff = (angle + 180 + 360) % 360 - 180;

	if (anglediff <= 45 && anglediff >= -45) {
		// facing right
		this->sprite.setTextureRect(sf::IntRect(21, 207, 20, 47));
	}
	else if (anglediff <= -45 && anglediff >= -145) {
		// facing up
		this->sprite.setTextureRect(playerForward[counter]);
	}
	else if (anglediff <= 145 && anglediff >= -145) {
		// facing down
		this->sprite.setTextureRect(playerDown[counter]);
	}
	else {
		// facing left
		this->sprite.setTextureRect(sf::IntRect(23, 79, 20, 47));
	}

	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(this->getPos());

	sf::View view = window.getView();
	view.move(this->delta);
	window.setView(view);

	currentTime += deltaTime;
	if (currentTime >= 0.05f && delta != sf::Vector2f(0.f, 0.f)) {
		std::cout << "tick\n";
		currentTime = 0.f;

		counter++;
		if (counter >= 9) {
			counter = 0;
		}
	}
}
