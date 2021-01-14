#include "Drawable.h"

Drawable::Drawable(AssetManager& assets) : assets(assets) {}

sf::FloatRect Drawable::getHitbox()
{
    return sf::FloatRect(this->getPos(), sf::Vector2f(this->getSize()));
}

bool Drawable::isColliding(Drawable& drawable, sf::Vector2f delta)
{
    sf::FloatRect h1 = drawable.getHitbox();
    h1.left += delta.x;
    h1.top += delta.y;

    return h1.intersects(this->getHitbox());
}

void Drawable::debug_draw(sf::RenderWindow* window, sf::Color color)
{
    sf::FloatRect rect = this->getHitbox();

    sf::Vertex lines[5] = {
        sf::Vertex(sf::Vector2f(rect.left, rect.top), color),
        sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top), color),
        sf::Vertex(sf::Vector2f(rect.left + rect.width, rect.top + rect.height), color),
        sf::Vertex(sf::Vector2f(rect.left, rect.top + rect.height), color),
        sf::Vertex(sf::Vector2f(rect.left, rect.top), color)
    };

    window->draw(lines, 5, sf::LinesStrip);
}
