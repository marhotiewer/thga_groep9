#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>

class AssetManager
{
	public:
		AssetManager();
		sf::Texture zombieSpriteMap;
		sf::Texture adamSpriteMap;
		sf::Texture floorTexture;
		sf::Texture wallTexture;
		sf::Texture treeTexture;
};

#endif
