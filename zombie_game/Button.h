#ifndef BUTTON_H
#define BUTTON_H

#include "Static.h"

enum class buttonType {
	play,
	quit,
	options,
	scores,
	none
};

class Button : public Drawable
{
	public:
		Button(AssetManager& assets, sf::Vector2f pos, buttonType type);
		void buttonSelected(sf::Vector2f mousePos);
		buttonType buttonPressed();
	private:
		bool isButtonSelected = false;
		buttonType type;
};

#endif
