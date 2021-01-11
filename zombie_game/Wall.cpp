#include "Wall.h"

Wall::Wall(AssetManager& assets, sf::Vector2f pos, sf::Vector2f size) : Static(assets)
{
	this->sprite.setTexture(assets.wallTexture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	this->sprite.setPosition(pos);
}
