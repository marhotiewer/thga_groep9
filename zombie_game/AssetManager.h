#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
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
		AssetManager();///< \brief Constructor load all the textures of variables into memory.
		sf::Texture homescreenBackgroundTexture;///< \brief home screen background. \image html menu_image.png 
		sf::Texture HUD_bottom_right;///< \brief hud of the game. \image html hud_bottom_right.png
		sf::Texture zombieSpriteMap;///< \brief Zombie sprite map.  \image html zombie.png
		sf::Texture buttonTexture;///< \brief Texture of a button. \image html buttons.png
		sf::Texture adamSpriteMap;///< \brief Player sprite map. \image html player.png
		sf::Texture gameLogoTexture;///< \brief logo of the game. \image html logo.png
		sf::Texture treeTexture;///< \brief Texture for one Tree. \image html tree.png
		sf::Texture bulletSprite;///< \brief Texture of a Bullet.
		sf::Texture floorTexture;///< \brief Texture of a Floor.
		sf::Texture wallTexture;///< \brief Texture of a Wall.
		sf::Font arial;///< \brief The font used in the game for text.
		sf::Texture gameOverTexture;///< \brief Texture of the game over text used in the GameOver screen. \image html gameover.png
		sf::Texture scoreBoard;///< \brief Texture of the score board used in the screen: ScoreScreen. \image html scoreboard.png
		sf::Texture policeagentTexture;///< \brief Texture of the police agent(PoliceAgent). Used in the map. \image html policeagent.png
		sf::Texture invisibleTexture;///< \brief Texture of a InvisibleWall. Used in the map. \image html invisible.png
		sf::Texture fountainTexture;///< \brief Texture of a Fountain. Used in the map. \image html fountain.png
		sf::Texture campfireTexture;///< \brief Texture of the Campfire. Used in the map. \image html campfire.png
		sf::Texture sandbagTexture;///< \brief Texture of the Sandbag. Used in the map. \image html sandbag.png
		sf::Texture hills1Texture;///< \brief Texture of the normal hill(Hils1). Used in the map. \image html hills.png
		sf::Texture hills2Texture;///< \brief Texture of a hill(Hils2) with a waterfall. Used in the map. \image html hills2.png
		sf::Texture fenceTexture;///< \brief Texture of the Fence. Used in the map. \image html fence.png
		sf::Texture houseFenceTexture;///< \brief Texture of the House fence. Used in the map. \image html fenceHouse.png
		sf::Texture waterTexture;///< \brief Texture of the Water. Used in the map. \image html water.png
		sf::Texture perk1Texture;///< \brief Texture of the perk(Perk1). Used in the map. \image html perk1.png
		sf::Texture shedTexture;///< \brief Texture of the shed. Used in the map. \image html shed.png
		sf::Texture tentTexture;///< \brief Texture of the tent. Used in the map. \image html tent.png
		sf::Texture woodTexture;///< \brief Wood texture. Used in the map. \image html wood.png
		sf::Texture lampTexture;///< \brief Texture of a lamp. Used in the map. \image html lamp.png
		sf::Texture rockTexture;///< \brief Texture of a rocks. Used in the map. \image html rocks.png
		sf::Texture bushTexture;///< \brief Texture of a bush. Used in the map. \image html bush.png
		sf::Texture bushRotatedTexture;///< \brief Texture of a rotated bush. Used in the map. \image html bushRotated.png
};

#endif //ASSETMANAGER_H
