#ifndef BUTTON_H
#define BUTTON_H

#include "Static.h"

enum class ButtonType {
	Play,
	Quit,
	Options,
	Scores,
	None
};

class Button : public Drawable
{
	public:
		Button(AssetManager& assets, sf::Vector2f pos, ButtonType type);
		void buttonSelected(sf::Vector2f mousePos);
		ButtonType buttonPressed();
	private:
		bool isButtonSelected = false;
		ButtonType type;
};

#endif
