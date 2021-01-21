#include "BushRotated.h"

BushRotated::BushRotated(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.bushRotatedTexture);
	this->sprite.setPosition(pos);
}

sf::FloatRect BushRotated::getHitbox()
{
	sf::Vector2f spritePos = this->getPos() + sf::Vector2f(50, 0);
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(50, 400);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
