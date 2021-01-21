#include "Hills2.h"

Hills2::Hills2(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.hills2Texture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Hills2::getHitbox()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(750, 240);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}