#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Drawable
{
	public:
		Drawable(AssetManager& assets);

		virtual void draw(sf::RenderWindow *window) = 0;
		virtual sf::Vector2f getPos() = 0;
		virtual sf::Vector2i getSize() = 0;
        virtual sf::Vector2f getHitBoxPos() {
            return this->getPos();
        }
        virtual sf::Vector2i getHitBoxSize() {
            return this->getSize();
        }
        virtual bool isColliding(Drawable& drawable) {
            sf::Vector2f r1p = drawable.getHitBoxPos();
            sf::Vector2i r1s = drawable.getHitBoxSize();

            sf::Vector2f r2p = this->getHitBoxPos();
            sf::Vector2i r2s = this->getHitBoxSize();

            if (r2p.x + r2s.x >= r1p.x &&   // r1 right edge past r2 left
                r2p.x <= r1p.x + r1s.x &&   // r1 left edge past r2 right
                r2p.y + r2s.y >= r1p.y &&   // r1 top edge past r2 bottom
                r2p.y <= r1p.y + r1s.y) {   // r1 bottom edge past r2 top
                return true;
            }
            return false;
        }
	protected:
		AssetManager& assets;
};

#endif
