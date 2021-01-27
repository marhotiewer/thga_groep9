#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "cScreen.h"
#include "Button.h"
/// @file


/// \class MainMenu
/// \brief
/// Main Menu class
/// \details
/// The class for the main menu.
class MainMenu : public cScreen
{
	private:
		std::vector<Button*> buttons;///< A vector of all the buttons on the main screen.
		bool isFullScreen = false;///< \brief bool if SFML window is full screen. 
		sf::RenderWindow* window;///<Pointer to the SFML window. [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		sf::Sprite background;///<SFML Sprite for the background of the main menu. (is loaded from AssetManager in the constructor of this class). \image html menu_image.png
		AssetManager& assets;///<Reference to the AssetManager. To load textures. 
		sf::Event event;///<SFML Event is for handling for keyboard inputs and window resising. [SFML Event Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php)
		sf::Sprite logo;///<SFML Sprite of the logo sceen on the main menu(is loaded from AssetManager in the constructor of this class). \image html logo.png
		//sf::Music* backgroundMusic;///< Background music of the MainMenu.
		sf::Sound clickSound;///< Sound plays when the player presses a button.
		void matchBackground();///< Function to reset background placement. 
		~MainMenu();
	public:
		/// <summary>
		/// Constructor or MainMenu class. 
		/// The Constructor loads all the buttons on the screen.
		/// </summary>
		/// <param name="window">The pointer to the current SFML window of the game.</param>
		/// <param name="assets">AssetManager required for textures</param>
		MainMenu(sf::RenderWindow* window, AssetManager& assets);

		/// <summary>
		/// Function that checks if a next screen need to show.
		/// </summary>
		/// <param name="deltaTime">The time elapsed for one frame.</param>
		/// <returns></returns>
		Screen update(float deltaTime);

		/// <summary>
		/// Function that as executed will toggle the SFML window to full screen.
		/// </summary>
		void toggleFullscreen();

		/// <summary>
		/// Main loop of the MainMenu class. 
		/// This function will be executed for showing the main menu.
		/// This function will return if a next screen need to show or the application need to exit. 
		/// </summary>
		/// <returns>Next screen to run(probably the game).</returns>
		Screen run() override;

		/// <summary>
		/// SFML Event handeler.
		/// [SFML Event Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php)
		/// </summary>
		/// <returns>If a next screen need to show. !!!!!</returns>
		Screen pollEvents();

		/// <summary>
		/// Function that checks if the SFML window is running
		/// [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		/// </summary>
		/// <returns>If SFML window is running</returns>
		bool running();

		/// <summary>
		/// Function that draws everything on the screen.
		/// Uses #window [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
		/// </summary>
		void render();
};

#endif
