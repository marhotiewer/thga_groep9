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
		/// <param name="pos">Spawn position of the zombie</param>
		/// <param name="player">Pointer to the player.(to get to location to follow to player).</param>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="objects">A vector of pointers of all the Drawable, is used for collision detection.</param>
		Zombie(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos, Player* player, std::vector<Drawable*>& objects);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="deltaTime"></param>
		void update(float deltaTime) override;
		
		/// <summary>
		/// Draws to the window the outlines of objects, used for debugging purpose.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		void debug_draw(sf::RenderWindow* window) override;
		
		/// <summary>
		/// Function to check Zombie can move to new position(old position+deta).
		/// </summary>
		/// <param name="delta">Delta is now much difference to new position</param>
		/// <returns>Pointer to drawable if colliding.</returns>
		Drawable* move(sf::Vector2f delta) override;
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		sf::FloatRect getHitbox() override;
		void playAttackSound();
	private:
		Player* player;///<
		sf::Sound* attackSounds[4];
		sf::Clock* zombieClock;
		int randomSoundTime;
};

#endif
