#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
	public:
		AssetManager();
		sf::Texture zombieSpriteMap;
		sf::Texture adamSpriteMap;
		sf::Texture floorTexture;
		sf::Texture bulletSprite;
		sf::Texture wallTexture;
		sf::Texture treeTexture;
		sf::SoundBuffer walkingSound;
};

#endif
