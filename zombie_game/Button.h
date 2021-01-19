#ifndef BUTTON_H
#define BUTTON_H

#include "Static.h"

enum class buttonType {
	play, quit, options, scores, none
};

class Button : public Drawable
{
private:
	sf::Sprite sprite;
	buttonType type;
	sf::FloatRect position;
	bool isButtonSelected;
public:
	Button(AssetManager& assets, sf::Vector2f pos, buttonType type);
	void buttonSelected(sf::Vector2f mousePos);
	buttonType buttonPressed();
	void draw(sf::RenderWindow* window) override;
};

#endif
