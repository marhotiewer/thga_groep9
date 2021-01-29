#include "HUD.h"

HUD::HUD(sf::RenderWindow* window, AssetManager& assets, sf::Vector2f pos) : assets(assets), window(window)
{
	this->waveText.setString("Wave: " + std::to_string(this->wave));
	this->bottom_right.setTexture(assets.HUD_bottom_right);
	this->healthText.setFillColor(sf::Color::Red);
	this->pointsText.setFillColor(sf::Color::Red);
	this->timeText.setFillColor(sf::Color::Red);
	this->waveText.setFillColor(sf::Color::Red);
	this->healthText.setFont(assets.arial);
	this->pointsText.setFont(assets.arial);
	this->healthText.setCharacterSize(28);
	this->pointsText.setCharacterSize(28);
	this->timeText.setFont(assets.arial);
	this->waveText.setFont(assets.arial);
	this->bottom_right.setPosition(pos);
	this->timeText.setCharacterSize(28);
	this->waveText.setCharacterSize(28);
}

void HUD::draw(sf::RenderWindow* window)
{
	window->draw(this->bottom_right);
	window->draw(this->healthText);
	window->draw(this->timeText);
	window->draw(this->pointsText);
	window->draw(this->waveText);
}

void HUD::update()
{
	const sf::Vector2u window_size(this->window->getSize());
	
	const sf::Vector2f spriteSize(
		this->bottom_right.getTexture()->getSize().x * this->bottom_right.getScale().x,
		this->bottom_right.getTexture()->getSize().y * this->bottom_right.getScale().y);

	this->pointsText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y + 60) }));
	this->timeText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y + 30) }));
	this->waveText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y + 90) }));
	this->bottom_right.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y) }));
	this->healthText.setPosition(this->window->mapPixelToCoords({ 0, int(window_size.y - spriteSize.y) }));
	
}

void HUD::updateWave(int newWave)
{
	this->waveText.setString("Wave: " + std::to_string(this->wave));
	this->wave = newWave;
}

void HUD::updateText(HudInfo info)
{
	this->healthText.setString("Health: " + std::to_string(info.health));
	this->pointsText.setString("Points: " + std::to_string(info.points));
	this->timeText.setString("Time: " + std::to_string(int(info.time)));
}
