#include "Button.h"
#include <iostream>

Button::Button(AssetManager& assets, sf::Vector2f pos, buttonType type):
	Drawable(assets),
	type(type)
{
	this->isButtonSelected = false;
	this->sprite.setPosition(pos);
	this->sprite.setTexture(assets.buttonTexture);
	switch (type) {
		case buttonType::play:
			// load correct texture
			this->sprite.setTextureRect({ 0, 0, 111, 54 });
			break;
		case buttonType::quit:
			this->sprite.setTextureRect({ 0, 54, 111, 54 });
			break;
		case buttonType::options:
			this->sprite.setTextureRect({ 0, 108, 111, 54 });
			break;
		case buttonType::scores:
			this->sprite.setTextureRect({ 0, 162, 111, 54 });
			break;
		default: 
			// This should never happen
			std::cout << "Button type not implemented!" << std::endl;
			exit(1);
	}
	this->position = this->sprite.getGlobalBounds();
}

void Button::buttonSelected(sf::Vector2f mousePos) {
	//std::cout <<  (this->position.left < mousePos.x) << ", " << ((this->position.width + this->position.left) > mousePos.x) << ", " << (this->position.top < mousePos.y) << ", " << ((this->position.height + this->position.top) > mousePos.y) << std::endl;
	if ( this->position.contains(mousePos) && !this->isButtonSelected) {
		// Change button to selected state
		sf::IntRect textureRect = this->sprite.getTextureRect();
		textureRect.left += 111;
		this->sprite.setTextureRect(textureRect);
		this->isButtonSelected = true;
	}
	else if( !(this->position.contains(mousePos)) && this->isButtonSelected) {
		// Change button to unselected state
		sf::IntRect textureRect = this->sprite.getTextureRect();
		textureRect.left -= 111;
		this->sprite.setTextureRect(textureRect);
		this->isButtonSelected = false;
	}
}

buttonType Button::buttonPressed() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->isButtonSelected) {
		return this->type;
	}
	else return buttonType::none;
}

void Button::draw(sf::RenderWindow* window) {
	window->draw(sprite);
}