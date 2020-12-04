#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML/Graphics.hpp"

class GameObject {
	public:
		virtual void draw(sf::RenderWindow &window) = 0;
		virtual void update(std::vector<std::unique_ptr<GameObject>>& gameObjects) = 0;
		virtual sf::Vector2f getPosition() = 0;
};

#endif
