#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>

#include "AssetManager.h"
#include "Entity.h"
#include "Bullet.h"
#include "HUD.h"

/// @file


/// \class Player
/// \brief
/// Player class 
/// \details
/// Class of the player. 
class Player : public Entity
{
	public:
		/// <summary>
		/// The constructor of the Player class.
		/// The constructor loads the texture from de AssetManager.
		/// Default health is is 10.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Spawn position of the player.{x,y}</param>
		/// <param name="object">A vector of pointers of all the Drawable, is used for collision detection.</param>
		Player(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos, std::vector<Drawable*>& object);
		
		/// <summary>
		/// Updates the direction of the player to set the correct texture of the player on the screen.
		/// This function also updates the correct frame of the animation of the player.
		/// </summary>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		void update(float deltaTime) override;
		
		/// <summary>
		/// Draws to the window the outlines of objects, used for debugging purpose.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		void debug_draw(sf::RenderWindow* window) override;
		
		/// <summary>
		/// Returns the hit box of the player. 
		/// </summary>
		/// <returns>SFML FloatRect hitbox</returns>
		sf::FloatRect getHitbox() override;
		
		/// <summary>
		/// Function used to shoot Enemys. 
		/// </summary>
		/// <param name="direction">Direction to shoot{x,y}</param>
		void shoot(sf::Vector2f direction);

		/// <summary>
		/// 
		/// </summary>
		///<param name="window">The pointer to the current SFML window of the game.</param>
		void draw_hud(sf::RenderWindow* window);


		void addPoints(int points);


		int getPoints();


	private:
		HUD hud;///<On screen information
		HudInfo info;
};

#endif
