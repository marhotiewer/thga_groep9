#include "Campfire.h"

Campfire::Campfire(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.campfireTexture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Campfire::getHitbox()
{
	sf::Vector2f spritePos = this->getPos() + sf::Vector2f(0,-5);
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(80,65);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
