#include "Drawable.h"

Drawable::Drawable(AssetManager& assets) : assets(assets)
{
	// init
}

sf::FloatRect Drawable::getHitbox()
{
    return sf::FloatRect(this->getPos(), sf::Vector2f(this->getSize()));
}

bool Drawable::isColliding(Drawable& drawable)
{
    sf::FloatRect r1p = drawable.getHitbox();
    sf::FloatRect r2p = this->getHitbox();

    if (r2p.left + r2p.width >= r1p.left &&   // r1 right edge past r2 left
        r2p.left <= r1p.left + r1p.width &&   // r1 left edge past r2 right
        r2p.top + r2p.height >= r1p.top &&   // r1 top edge past r2 bottom
        r2p.top <= r1p.top + r1p.height) {   // r1 bottom edge past r2 top
        return true;
    }
    return false;
}
