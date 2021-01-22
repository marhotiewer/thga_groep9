#include "HUD.h"

HUD::HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos) : assets(assets), window(window)
{
	this->bottom_right.setTexture(assets.HUD_bottom_right);
	this->bottom_right.setPosition(pos);
}

void HUD::draw(sf::RenderWindow* window)
{
	window->draw(this->bottom_right);
}

void HUD::update()
{
	const sf::Vector2u window_size(this->window->getSize());
	
	const sf::Vector2f spriteSize(
		this->bottom_right.getTexture()->getSize().x * this->bottom_right.getScale().x,
		this->bottom_right.getTexture()->getSize().y * this->bottom_right.getScale().y);

	this->bottom_right.setPosition(this->window->mapPixelToCoords({0, int(window_size.y - spriteSize.y)}));
}
