#include "Button.h"
#include <iostream>

Button::Button(AssetManager& assets, sf::Vector2f pos, ButtonType type) : Drawable(assets), type(type)
{
	this->sprite.setTexture(assets.buttonTexture);
	this->sprite.setPosition(pos);

	switch (type) {
		case ButtonType::Play:
			this->sprite.setTextureRect({ 0, 0, 111, 54 });
			break;
		case ButtonType::Quit:
			this->sprite.setTextureRect({ 0, 54, 111, 54 });
			break;
		case ButtonType::Options:
			this->sprite.setTextureRect({ 0, 108, 111, 54 });
			break;
		case ButtonType::Scores:
			this->sprite.setTextureRect({ 0, 162, 111, 54 });
			break;
		default: 
			// This should never happen
			std::cout << "Button type not implemented!" << std::endl;
			exit(1);
	}
}

void Button::buttonSelected(sf::Vector2f mousePos) {
	if ( this->sprite.getGlobalBounds().contains(mousePos) && !this->isButtonSelected) {
		// Change button to selected state
		sf::IntRect textureRect = this->sprite.getTextureRect();
		textureRect.left += 111;
		this->sprite.setTextureRect(textureRect);
		this->isButtonSelected = true;
	}
	else if( !(this->sprite.getGlobalBounds().contains(mousePos)) && this->isButtonSelected) {
		// Change button to unselected state
		sf::IntRect textureRect = this->sprite.getTextureRect();
		textureRect.left -= 111;
		this->sprite.setTextureRect(textureRect);
		this->isButtonSelected = false;
	}
}

ButtonType Button::buttonPressed() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->isButtonSelected) {
		return this->type;
	}
	else return ButtonType::None;
}