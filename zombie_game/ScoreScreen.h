#ifndef ScoreScreen_H
#define ScoreScreen_H

#include <iostream>
#include <map>
#include <iterator>
#include <json.hpp>
#include <fstream>
#include "cScreen.h"
#include "AssetManager.h"
#include "Button.h"

///@file

/// \class MainMenu
/// \brief
/// Main Menu class
/// \details
/// The class for the main menu.
class ScoreScreen : public cScreen
{
private:
	std::vector<Button*> buttons;///<A vector of all the buttons on the main screen.
	bool isFullScreen = false;///< \brief bool if SFML window is full screen. 
	sf::RenderWindow* window;///<Pointer to the SFML window. [SFML window Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)
	sf::Sprite background;///<SFML Sprite for the background of the main menu. (is loaded from AssetManager in the constructor of this class). \image html menu_image.png
	AssetManager& assets;///<Reference to the AssetManager. To load textures. 
	sf::Event event;///<SFML Event is for handling for keyboard inputs and window resising. [SFML Event Documentation](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php)
	sf::Sprite logo;///<SFML Sprite of the logo sceen on the main menu(is loaded from AssetManager in the constructor of this class). \image html logo.png
	sf::Sprite scoreBoard;///< Sprite of the scoreboard. In the sprite there is place for 8 scores. Used in the displayScores function of this class. \image html scoreboard.png
	std::vector<sf::Text> scoreTextVector;///< Vector of SFML Text with scores. Is cleaned when the run function ends.
	std::multimap<int, std::string, std::greater<int>>::iterator last;///< Iterator to last item in the multimap. In code the iterator is not greater than 8, because there are 8 places in the score board. 
	void matchBackground();///< Function to reset background placement. 
	void displayScores();///< Function to diplay scores in the scores board.
	void toggleFullscreen();///< Function that as executed will toggle the SFML window to full screen.
public:
	/// <summary>
	/// Constructor or MainMenu class. 
	/// The Constructor loads all the buttons on the screen.
	/// </summary>
	/// <param name="window">The pointer to the current SFML window of the game.</param>
	/// <param name="assets">AssetManager required for textures</param>
	ScoreScreen(sf::RenderWindow* window, AssetManager& assets);

	/// <summary>
	/// Function that checks if a next screen need to show.
	/// </summary>
	/// <param name="deltaTime">The time elapsed for one frame.</param>
	/// <returns>Return a Screen if a next screen need to show. Otherwise return Screen::None</returns>
	Screen update(float deltaTime);

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
	/// <returns>If a next screen need to show. returm enum class Screen</returns>
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
