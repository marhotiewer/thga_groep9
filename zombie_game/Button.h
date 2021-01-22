#ifndef BUTTON_H
#define BUTTON_H

#include "Static.h"
/// @file


/// \enum ButtonType
/// \brief modes for buttons for the main menu. 
enum class ButtonType {
	Play,///<If pressed, the game wil start.
	Quit,///<If pressed, the game will close.
	Options,///<If pressed, The player can edit the options. 
	Scores,///<If pressed, the scores will show up on the screen. 
	None///<The button is not pressed
};


/// \class Button
/// \brief 
/// Class for main menu button.
/// \details
/// Class used for the buttons of the main menu. 
/// This class inhert from Drawable. 
/// \image html buttons.png
class Button : public Drawable
{
	public:
		/// <summary>
		/// The constructor loads the texture of AssetManager the texture: buttonTexture
		/// </summary>
		/// <param name="assets">AssetManager required for textures</param>
		/// <param name="pos">Position of the button</param>
		/// <param name="type">Type of the button of type enum class buttonType.</param>
		Button(AssetManager& assets, sf::Vector2f pos, ButtonType type);
		
		/// <summary>
		/// This function checks if the move hovers above the button. 
		/// And changes the isButtonSelected bool. 
		/// This function also updates the sprite to a texture of a pressed button. 
		/// </summary>
		/// <param name="mousePos">SFML position of the mouse.</param>
		void buttonSelected(sf::Vector2f mousePos);
		
		/// <summary>
		/// Function that checks if mouse is pressed and if true returns, the correct type of the button.
		/// </summary>
		/// <returns>What type of enum class buttonType the button is pressed</returns>
		ButtonType buttonPressed();
	private:
		bool isButtonSelected = false;///< Bool if button pressed.
		ButtonType type;///<Type of the button of type enum class buttonType.
};

#endif
