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
		/// Constructor of the Zombie
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Spawn position of the zombie</param>
		/// <param name="player">Pointer to the Player.(to get to location to follow to player).</param>
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
		
		/// <summary>
		/// Function to damage the Zombie. 
		/// If the zombie dies. The player is rewarded with 50 points.
		/// </summary>
		/// <param name="dmg">damage to the Zombie.</param>
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

		/// <summary>
		/// Function to play a sound of a Zombie.
		/// </summary>
		void playAttackSound();
	private:
		Player* player;///<Pointer to the player class.
		sf::Sound* attackSounds[4];///< Array of sounds that a zombie makes.
		sf::Clock zombieClock;///< Clock used for Zombie sounds.
		int randomSoundTime;///< integer containing a random number till 5(0-5). 
};

#endif
