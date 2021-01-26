#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
/// @file
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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
		sf::Texture homescreenBackgroundTexture;///< \brief home screen background. \image html menu_image.png 
		sf::Texture HUD_bottom_right;///< \brief hud of the game. \image html hud_bottom_right.png
		AssetManager();///< \brief Constructor load all the textures of variables into memory.
		sf::Texture zombieSpriteMap;///< \brief Zombie sprite map.  \image html zombie.png
		sf::Texture buttonTexture;///< \brief Texture of a button. \image html buttons.png
		sf::Texture adamSpriteMap;///< \brief Player sprite map. \image html player.png
		sf::Texture gameLogoTexture;///< \brief logo of the game. \image html logo.png
		sf::Texture treeTexture;///< \brief Texture for one Tree. \image html tree.png
		sf::Texture bulletSprite;///< \brief Texture of a Bullet.
		sf::Texture floorTexture;///< \brief Texture of a Floor.
		sf::Texture wallTexture;///< \brief Texture of a Wall.
		//sf::Texture treeTexture;///< \brief Texture for one Tree. \image html tree.png
		sf::Font arial;
		sf::Texture gameOverTexture;
		sf::Texture scoreBoard;
		sf::Texture policeagentTexture;
		sf::Texture bushRotatedTexture;
		sf::Texture invisibleTexture;
		sf::Texture fountainTexture;
		sf::Texture campfireTexture;
		sf::Texture sandbagTexture;
		sf::Texture hills1Texture;
		sf::Texture hills2Texture;
		sf::Texture fenceTexture;
		sf::Texture houseTexture;
		sf::Texture waterTexture;
		sf::Texture perk1Texture;
		sf::Texture shedTexture;
		sf::Texture tentTexture;
		sf::Texture woodTexture;
		sf::Texture lampTexture;
		sf::Texture rockTexture;
		sf::Texture bushTexture;
		sf::SoundBuffer mainMenuClickSound;
		sf::SoundBuffer* zombieSounds[4];
		sf::SoundBuffer walkingSound;
		sf::Music mainMenuSoundtrack;
		sf::SoundBuffer handGunSound;
		sf::Music ingameBreezeSound;
};

#endif //ASSETMANAGER_H
