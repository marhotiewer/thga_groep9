#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class HUD
{
	public:
		HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos);
		void draw(sf::RenderWindow* window);
		void update();
	private:
		sf::RenderWindow* window;
		sf::Sprite bottom_right;
		AssetManager& assets;
};

#endif
