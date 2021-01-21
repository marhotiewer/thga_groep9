#include "Bush.h"

Bush::Bush(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.bushTexture);
	this->sprite.setPosition(pos);
}

sf::FloatRect Bush::getHitbox()
{
	sf::Vector2f spritePos = this->getPos() + sf::Vector2f(0, -50);
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(400, 50);
	return sf::FloatRect(sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y), hitBoxSize);
}
