#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

#include "Drawable.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Floor.h"
#include "Wall.h"
#include "Tree.h"
#include "Fence.h"
#include "HouseFence.h"
#include "Water.h"
#include "Shed.h"
#include "Tent.h"
#include "Fountain.h"
#include "Wood.h"
#include "Campfire.h"
#include "Hills1.h"
#include "Hills2.h"
#include "PoliceAgent.h"
#include "Lamp.h"
#include "Invisible.h"
#include "Rocks.h"
#include "Perk1.h"
#include "Bush.h"
#include "BushRotated.h"
#include "Sandbag.h"

class Game {
	public:
		Game();
		~Game();
		void update(float deltaTime);
		void toggleFullscreen();
		void pollEvents();
		bool running();
		void render();
	private:
		std::vector<Drawable*> objects;
		bool noKeyPressed = false;
		bool isFullScreen = false;
		sf::RenderWindow* window;
		float elapsedTime = 0.f;
		AssetManager assets;
		bool debug = false;
		sf::Event event;
		Player *player;
};

#endif
