#include "Player.h"

Player::Player(AssetManager& assets, sf::Vector2f pos, std::vector<Entity*>& entities, std::vector<Static*>& statics) : Entity(assets, entities, statics)
{
	this->sprite.setTexture(this->assets.adamSpriteMap);
	this->sprite.setTextureRect(sf::IntRect(576, 80, 32, 48));
	this->sprite.setPosition(pos);

	this->playerAnimation = {
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { // up walking
				sf::IntRect(192, 144, 32, 48),
				sf::IntRect(224, 144, 32, 48),
				sf::IntRect(256, 144, 32, 48),
				sf::IntRect(288, 144, 32, 48),
				sf::IntRect(320, 144, 32, 48),
				sf::IntRect(352, 144, 32, 48)
			},
			std::array<sf::IntRect, 6> { // up idle
                sf::IntRect(192, 80, 32, 48),
                sf::IntRect(224, 80, 32, 48),
                sf::IntRect(256, 80, 32, 48),
                sf::IntRect(288, 80, 32, 48),
                sf::IntRect(320, 80, 32, 48),
                sf::IntRect(352, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { // down walking
				sf::IntRect(576, 144, 32, 48),
				sf::IntRect(608, 144, 32, 48),
				sf::IntRect(640, 144, 32, 48),
				sf::IntRect(672, 144, 32, 48),
				sf::IntRect(704, 144, 32, 48),
				sf::IntRect(736, 144, 32, 48)
			},
            std::array<sf::IntRect, 6> { // down idle
                sf::IntRect(576, 80, 32, 48),
                sf::IntRect(608, 80, 32, 48),
                sf::IntRect(640, 80, 32, 48),
                sf::IntRect(672, 80, 32, 48),
                sf::IntRect(704, 80, 32, 48),
                sf::IntRect(736, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { // left walking
				sf::IntRect(384, 144, 32, 48),
                sf::IntRect(416, 144, 32, 48),
                sf::IntRect(448, 144, 32, 48),
                sf::IntRect(480, 144, 32, 48),
                sf::IntRect(512, 144, 32, 48),
                sf::IntRect(544, 144, 32, 48)
			},
			std::array<sf::IntRect, 6> { // left idle
                sf::IntRect(384, 80, 32, 48),
                sf::IntRect(416, 80, 32, 48),
                sf::IntRect(448, 80, 32, 48),
                sf::IntRect(480, 80, 32, 48),
                sf::IntRect(512, 80, 32, 48),
                sf::IntRect(544, 80, 32, 48)
            }
		},
		std::array<std::array<sf::IntRect, 6>, 2> {
			std::array<sf::IntRect, 6> { // right walking
				sf::IntRect(0,   144, 32, 48),
                sf::IntRect(32,  144, 32, 48),
                sf::IntRect(64,  144, 32, 48),
                sf::IntRect(96,  144, 32, 48),
                sf::IntRect(128, 144, 32, 48),
                sf::IntRect(160, 144, 32, 48)
			},
            std::array<sf::IntRect, 6> { // right idle
                sf::IntRect(0,   80, 32, 48),
                sf::IntRect(32,  80, 32, 48),
                sf::IntRect(64,  80, 32, 48),
                sf::IntRect(96,  80, 32, 48),
                sf::IntRect(128, 80, 32, 48),
                sf::IntRect(160, 80, 32, 48)
            }
		}
	};
}

void Player::debug_draw(sf::RenderWindow* window, sf::Color color)
{
	Drawable::debug_draw(window, color);

	const sf::Vertex vertexes[][2] = {
		{
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, 0)).x, window->mapPixelToCoords(sf::Vector2i(0, 0)).y), sf::Color::Red),
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(window->getSize().x, window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(window->getSize().x, window->getSize().y)).y), sf::Color::Red)
		},
		{
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(window->getSize().x, 0)).x, window->mapPixelToCoords(sf::Vector2i(window->getSize().x, 0)).y), sf::Color::Red),
			sf::Vertex(sf::Vector2f(window->mapPixelToCoords(sf::Vector2i(0, window->getSize().y)).x, window->mapPixelToCoords(sf::Vector2i(0, window->getSize().y)).y), sf::Color::Red)
		}
	};

	for (const sf::Vertex* vertex : vertexes) window->draw(vertex, 2, sf::Lines);
}

sf::FloatRect Player::getHitbox()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(25, 15);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}

void Player::update(sf::RenderWindow& window, float deltaTime)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2f playerPos = (this->getPos() - this->delta) + sf::Vector2f(this->getSize()) / 2.f;

	int anglediff = (int(atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x) * 57.29577951308232286f) + 180 + 360) % 360 - 180;
	int direction, mode = 0;
	float timeStep = 0.f;

	if (anglediff <= 45 && anglediff >= -45)
		direction = 3; // facing right
	else if (anglediff <= -45 && anglediff >= -145)
		direction = 0; // facing up
	else if (anglediff <= 145 && anglediff >= -145)
		direction = 1; // facing down
	else
		direction = 2; //facing left

	if (this->delta == sf::Vector2f(0.f, 0.f)) {
		mode = 1; // idle animation
		timeStep = 0.15f;
	}
	else {
		mode = 0; // moving animation

		if (this->delta.x > 1.f || this->delta.y > 1.f || this->delta.x < -1.f || this->delta.y < -1.f)
			timeStep = 0.025f; // running
		else
			timeStep = 0.05f; // walking
	}

	this->currentTime += deltaTime;
	if (this->currentTime >= timeStep) {
		this->currentTime = 0.f;
		this->playerAnimationIndex++;
		
		if (this->playerAnimationIndex == 6) {
			this->playerAnimationIndex = 0;
		}
	}

	this->sprite.setTextureRect(this->playerAnimation[direction][mode][playerAnimationIndex]);
	
	if (this->delta != sf::Vector2f(0.f, 0.f)) {
		this->sprite.setPosition(this->getPos()+this->delta);

		sf::View view = window.getView();
		view.move(this->delta);
		window.setView(view);

		this->delta = sf::Vector2f(0.f, 0.f);
	}
}
