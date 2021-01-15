#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"

class Drawable
{
	public:
		enum class Type
		{
			Projectile,
			Player,
			Static,
			Enemy,
			Empty
		};
		Drawable(AssetManager& assets) : assets(assets) {}
		virtual bool isColliding(Drawable& drawable, sf::Vector2f delta = sf::Vector2f(0.f, 0.f));
		virtual void update(sf::RenderWindow* window, float deltaTime) {}
		virtual void debug_draw(sf::RenderWindow* window);
		virtual void draw(sf::RenderWindow *window);
		virtual sf::FloatRect getHitbox();
		virtual void damage(int dmg) {};
		virtual sf::Vector2i getSize();
		virtual sf::Vector2f getPos();
		Type type = Type::Empty;
		bool isActive();
	protected:
		AssetManager& assets;
		bool active = true;
		sf::Sprite sprite;
};

#endif
