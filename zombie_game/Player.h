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
/// Class of the Player
/// \details
/// Class used for the player. 
/// This Class inhert from Entity. 
/// Default health is 10 lives.
class Player : public Entity
{
	public:
		/// <summary>
		/// The constructor of the Player class.
		/// The constructor loads the texture from de AssetManager.
		/// Default health is 10 lives.
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
		/// Function to draw the hud. The hud wil contain: Healt, Time and Points
		/// </summary>
		///<param name="window">The pointer to the current SFML window of the game.</param>
		void draw_hud(sf::RenderWindow* window);

		/// <summary>
		/// Function to add points to the Player. 
		/// Function used when zombies 
		/// </summary>
		/// <param name="points">points to add to the player.</param>
		void addPoints(int points);

		/// <summary>
		/// Function to get the amount of points the plays has. 
		/// </summary>
		/// <returns>Amount of points the plays has.</returns>
		int getPoints();

		~Player();
	private:
		HUD hud;///< On screen information.like, points, time and healt.
		sf::Sound walkingSound;///< sound of the player walking.
		sf::Sound handGunSound;///< Sound of the handgun.
		HudInfo info;///< The struct that contains the player information like, points and time.
};

#endif
