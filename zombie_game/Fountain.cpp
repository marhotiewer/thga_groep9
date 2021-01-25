#include "Fountain.h"

Fountain::Fountain(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.fountainTexture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Fountain::getHitbox()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(225, 150);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
