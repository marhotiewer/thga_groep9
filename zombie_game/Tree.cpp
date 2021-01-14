#include "Tree.h"

Tree::Tree(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.treeTexture);
	this->sprite.setPosition(pos);
}

sf::Vector2f Tree::getHitBoxPos()
{
	sf::Vector2f spritePos = this->getPos();
	sf::Vector2f spriteSize = sf::Vector2f(this->getSize());
	sf::Vector2f hitBoxSize = sf::Vector2f(this->getHitBoxSize());
	return sf::Vector2f(spritePos.x + (spriteSize.x / 2.f) - hitBoxSize.x / 2.f, spritePos.y + spriteSize.y - hitBoxSize.y);
}

sf::Vector2i Tree::getHitBoxSize()
{
	return sf::Vector2i(25, 20);
}
