#include "Drawable.h"

bool Drawable::isColliding(Drawable& drawable, sf::Vector2f delta)
{
    sf::FloatRect h1 = drawable.getHitbox();
    h1 = { h1.left + delta.x, h1.top + delta.y, h1.width, h1.height };
    return h1.intersects(this->getHitbox());
}

void Drawable::debug_draw(sf::RenderWindow* window)
{
    sf::FloatRect _texture(this->getPos(), sf::Vector2f(this->getSize()));
    sf::FloatRect _hitbox(this->getHitbox());

    sf::Vertex texture[5] = {
        sf::Vertex(sf::Vector2f(_texture.left, _texture.top), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(_texture.left + _texture.width, _texture.top), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(_texture.left + _texture.width, _texture.top + _texture.height), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(_texture.left, _texture.top + _texture.height), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(_texture.left, _texture.top), sf::Color::Blue)
    };

    sf::Vertex hitbox[5] = {
        sf::Vertex(sf::Vector2f(_hitbox.left, _hitbox.top), sf::Color::Green),
        sf::Vertex(sf::Vector2f(_hitbox.left + _hitbox.width, _hitbox.top), sf::Color::Green),
        sf::Vertex(sf::Vector2f(_hitbox.left + _hitbox.width, _hitbox.top + _hitbox.height), sf::Color::Green),
        sf::Vertex(sf::Vector2f(_hitbox.left, _hitbox.top + _hitbox.height), sf::Color::Green),
        sf::Vertex(sf::Vector2f(_hitbox.left, _hitbox.top), sf::Color::Green)
    };

    window->draw(hitbox, 5, sf::LinesStrip);
    if (_texture != _hitbox) window->draw(texture, 5, sf::LinesStrip);
}

void Drawable::draw(sf::RenderWindow* window)
{
    window->draw(this->sprite);
}

sf::FloatRect Drawable::getHitbox()
{
    return sf::FloatRect(this->getPos(), sf::Vector2f(this->getSize()));
}

sf::Vector2i Drawable::getSize()
{
    return this->sprite.getTextureRect().getSize();
}


sf::Vector2f Drawable::getPos()
{
    return this->sprite.getPosition();
}

bool Drawable::isActive()
{
    return this->active;
}

float Drawable::Z_Order()
{
    return this->getHitbox().top;
}
