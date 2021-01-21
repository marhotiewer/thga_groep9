#include "Hills1.h"

Hills1 ::Hills1(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.hills1Texture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Hills1::getHitbox()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(700, 240);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}