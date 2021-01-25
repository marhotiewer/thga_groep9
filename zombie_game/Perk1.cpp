#include "Perk1.h"

Perk1::Perk1(AssetManager& assets, sf::Vector2f pos, sf::Vector2i size) : Static(assets)
{
	this->sprite.setTexture(assets.perk1Texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	this->sprite.setPosition(pos);
}
