#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp> ///needed for sf::Texture
/// @file

/// \brief
/// AssetManager
/// \details
/// The asset manager is responsible for loading images SFML textures(sf::Texture).
/// If a class need a texture from the asset manager, the asset manager need to given by the class by reference. 
/// The image files are in the AssetManager.cpp file. 
/// The asset manager is created in Game.cpp.
class AssetManager
{
	public:
		AssetManager();
		sf::Texture zombieSpriteMap;///< \brief Zombie sprite map  \image html zombie.png
		sf::Texture adamSpriteMap;///< \brief Player sprite map \image html player.png
		sf::Texture floorTexture;///< \brief Texture of a Floor.
		sf::Texture bulletSprite;///< \brief Texture of a Bullet.
		sf::Texture wallTexture;///< \brief Texture of a Wall.
		sf::Texture treeTexture;///< \brief Texture for one Tree.
};

#endif //ASSETMANAGER_H
