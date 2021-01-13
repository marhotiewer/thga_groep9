#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos) : Entity(assets)
{
	this->sprite.setTexture(assets.adamSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(17, 15, 30, 46));
	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(pos);

	this->playerAnimation = std::array<std::array<std::array<sf::IntRect, 6>, 2>, 4> {
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { //Forward walking
				sf::IntRect(192, 144, 32, 48),
				sf::IntRect(224, 144, 32, 48),
				sf::IntRect(256, 144, 32, 48),
				sf::IntRect(288, 144, 32, 48),
				sf::IntRect(320, 144, 32, 48),
				sf::IntRect(352, 144, 32, 48)
			},
			std::array<sf::IntRect, 6> { //Forward idle
                sf::IntRect(192, 80, 32, 48),
                sf::IntRect(224, 80, 32, 48),
                sf::IntRect(256, 80, 32, 48),
                sf::IntRect(288, 80, 32, 48),
                sf::IntRect(320, 80, 32, 48),
                sf::IntRect(352, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { //Player Down walking
				sf::IntRect(576, 144, 32, 48),
				sf::IntRect(608, 144, 32, 48),
				sf::IntRect(640, 144, 32, 48),
				sf::IntRect(672, 144, 32, 48),
				sf::IntRect(704, 144, 32, 48),
				sf::IntRect(736, 144, 32, 48)
			},
            std::array<sf::IntRect, 6> { //Player Down idle
                sf::IntRect(576, 80, 32, 48),
                sf::IntRect(608, 80, 32, 48),
                sf::IntRect(640, 80, 32, 48),
                sf::IntRect(672, 80, 32, 48),
                sf::IntRect(704, 80, 32, 48),
                sf::IntRect(736, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { //Player left walking
				sf::IntRect(384, 144, 32, 48),
                sf::IntRect(416, 144, 32, 48),
                sf::IntRect(448, 144, 32, 48),
                sf::IntRect(480, 144, 32, 48),
                sf::IntRect(512, 144, 32, 48),
                sf::IntRect(544, 144, 32, 48)
			},
			std::array<sf::IntRect, 6> { //Player left idle
                sf::IntRect(384, 80, 32, 48),
                sf::IntRect(416, 80, 32, 48),
                sf::IntRect(448, 80, 32, 48),
                sf::IntRect(480, 80, 32, 48),
                sf::IntRect(512, 80, 32, 48),
                sf::IntRect(544, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { //Player right walking
				sf::IntRect(0, 144, 32, 48),
                sf::IntRect(32, 144, 32, 48),
                sf::IntRect(64, 144, 32, 48),
                sf::IntRect(96, 144, 32, 48),
                sf::IntRect(128, 144, 32, 48),
                sf::IntRect(160, 144, 32, 48)
			},
            std::array<sf::IntRect, 6> {//Player right idle
                sf::IntRect(0, 80, 32, 48),
                sf::IntRect(32, 80, 32, 48),
                sf::IntRect(64, 80, 32, 48),
                sf::IntRect(96, 80, 32, 48),
                sf::IntRect(128, 80, 32, 48),
                sf::IntRect(160, 80, 32, 48)
            }
		}
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
		direction = 3;
		//this->sprite.setTextureRect(this->playerRight[][counter]);
	}
	else if (anglediff <= -45 && anglediff >= -145) {
		// facing up
		direction = 0;
		//this->sprite.setTextureRect(this->playerWalkingForward[counter]);
	}
	else if (anglediff <= 145 && anglediff >= -145) {
		// facing down
		direction = 1;
		//this->sprite.setTextureRect(this->playerWalkingDown[counter]);
	}
	else {
		// facing left
		direction = 2;
		//this->sprite.setTextureRect(this->playerWalkingLeft[counter]);
	}
	this->sprite.setTextureRect(this->playerAnimation[direction][mode][counter]);

	this->sprite.setOrigin(this->sprite.getOrigin().x / 2.f, this->sprite.getOrigin().y / 2.f);
	this->sprite.setPosition(this->getPos());

	sf::View view = window.getView();
	view.move(this->delta);
	window.setView(view);

	currentTime += deltaTime;

	if (this->delta == sf::Vector2f(0.f, 0.f)) {
		mode = 1;
	}
	else {
		mode = 0;
	}
	if (currentTime >= 0.05f ) {
		currentTime = 0.f;
		counter++;
		if (counter >= 6) {
			counter = 0;
		}
	}
}
