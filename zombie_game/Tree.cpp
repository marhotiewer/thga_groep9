#include "Tree.h"

Tree::Tree(AssetManager& assets, sf::Vector2f pos) : Static(assets)
{
	this->sprite.setTexture(assets.treeTexture);
	this->sprite.setPosition(pos);
}
