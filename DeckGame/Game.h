#pragma once
class Game
{
public:
	Game();
	~Game();

	void newGame();

	//printing functions for updating screen
	void printDirectory();
	void printStats();
	void printMap();
	void printDisplay();
	void printLog();
	void printDecision();

	//functions for showing different screens
	void showDeckScreen();
	void showInventoryScreen();
	void showNormalScreen();
};

