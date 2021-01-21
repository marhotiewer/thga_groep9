#include "Lamp.h"

Lamp::Lamp(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.lampTexture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Lamp::getHitbox()
{
	sf::Vector2f spritePos = this->getPos() + sf::Vector2f(0,-80);
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(30, 30);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}