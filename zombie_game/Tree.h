#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>
#include "Static.h"

class Tree : public Static
{
public:
	Tree(AssetManager& assets, sf::Vector2f pos);
};

#endif
