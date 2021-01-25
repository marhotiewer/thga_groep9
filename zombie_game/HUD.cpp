#include "HUD.h"

HUD::HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos) : assets(assets), window(window)
{
	this->healthText.setFont(assets.arial);
	this->timeText.setFont(assets.arial);
	this->pointsText.setFont(assets.arial);
	this->bottom_right.setTexture(assets.HUD_bottom_right);
	this->bottom_right.setPosition(pos);
	this->healthText.setCharacterSize(28);
	this->timeText.setCharacterSize(28);
	this->pointsText.setCharacterSize(28);
	this->healthText.setFillColor(sf::Color::Green);
	this->timeText.setFillColor(sf::Color::Green);
	this->pointsText.setFillColor(sf::Color::Green);
}

void HUD::draw(sf::RenderWindow* window)
{
	window->draw(this->bottom_right);
	window->draw(this->healthText);
	window->draw(this->timeText);
	window->draw(this->pointsText);
}

void HUD::update(HudInfo info)
{
	const sf::Vector2u window_size(this->window->getSize());
	healthText.setString("health: " + std::to_string(info.health));
	timeText.setString("Time: " + std::to_string(int(info.time)));
	pointsText.setString("Points: " + std::to_string(info.points));
	const sf::Vector2f spriteSize(
		this->bottom_right.getTexture()->getSize().x * this->bottom_right.getScale().x,
		this->bottom_right.getTexture()->getSize().y * this->bottom_right.getScale().y);
	this->healthText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y) }));
	this->timeText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y + 30) }));
	this->pointsText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y + 60) }));
	this->bottom_right.setPosition(this->window->mapPixelToCoords({0, int(window_size.y - spriteSize.y)}));
}
