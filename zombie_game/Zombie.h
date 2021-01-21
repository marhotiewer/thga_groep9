#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <array>

#include "Entity.h"
#include "Player.h"
/// @file


// \class Zombie
/// \brief
/// Zombie class 
/// \details
/// Class of the Zombie. 
class Zombie : public Entity
{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Spawn position of the zombie</param>
		/// <param name="player">Pointer to the player.(to get to location to follow to player).</param>
		/// <param name="objects">A vector of pointers of all the Drawable, is used for collision detection.</param>
		Zombie(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos, Player* player, std::vector<Drawable*>& objects);
		
		/// <summary>
		/// Updates the location and animation of the Zombie
		/// </summary>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		void update(float deltaTime) override;
		
		/// <summary>
		/// Draws to the window the outlines of objects, used for debugging purpose.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		void debug_draw(sf::RenderWindow* window) override;
		

		void damage(int dmg) override;

		/// <summary>
		/// Function to check Zombie can move to new position(old position+deta).
		/// </summary>
		/// <param name="delta">Delta is now much difference to new position</param>
		/// <returns>Pointer to drawable if colliding.</returns>
		Drawable* move(sf::Vector2f delta) override;
		
		/// <summary>
		/// Hitbox
		/// </summary>
		/// <returns>SFML FloatRect of the Zombie</returns>
		sf::FloatRect getHitbox() override;
	private:
		Player* player;///<Pointer to the player class.
};

#endif
