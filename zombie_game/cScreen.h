#ifndef CSCREEN_H
#define CSCREEN_H

enum class screen {
	mainMenu,
	inGame,
	pauseMenu,
	optionsMenu,
	scores,
	none
};

class cScreen {
public:
	virtual screen run() = 0;
};

#endif
