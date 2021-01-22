#ifndef CSCREEN_H
#define CSCREEN_H
/// @file


/// \enum Screen
/// \brief Enum of all the different screen modes
enum class Screen {
	MainMenu,///< Startup screen.
	Game,///< The screen with the game.
	GameOver,
	Scores,///< Screen with scores
	OptionsMenu,///< Screen with options.
	PauseMenu,///< Menu that pause the game.
	None///< None is exit the application.
};


/// \class cScreen
/// \brief
/// Head class for all different screens. 
/// \details
/// This class is used for screen switching. 
/// classes that inhert from this class, need to have a run() function.
class cScreen {
	public:
		/// <summary>
		/// Function that contains the loop of the window. 
		/// </summary>
		/// <returns>The screen to switch to from enum type Screen</returns>
		virtual Screen run() = 0;
};

#endif
