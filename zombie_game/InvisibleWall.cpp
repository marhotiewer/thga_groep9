#include "InvisibleWall.h"

InvisibleWall::InvisibleWall(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size) : Static(assets)
{
	this->sprite.setTexture(assets.invisibleTexture);
	this->sprite.setPosition(pos);
}
