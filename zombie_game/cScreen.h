#ifndef CSCREEN_H
#define CSCREEN_H

enum class Screen {
	MainMenu,
	Game,
	OptionsMenu,
	PauseMenu,
	Scores,
	None
};

class cScreen {
	public:
		virtual Screen run() = 0;
};

#endif
