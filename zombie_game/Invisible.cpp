#include "Invisible.h"

InvisibleWall::InvisibleWall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size) : Static(assets)
{
	this->sprite.setTexture(assets.invisibleTexture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	this->sprite.setPosition(pos);
}
