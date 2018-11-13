#include "pch.h"
#include <iostream>
#include <curses.h>
#include <string>
#include "Game.h"

#include "Character.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::newGame() {
	Character newGuy;
}

void Game::printDirectory() {
	mvprintw(0, 0, "(D)eck");
	mvprintw(1, 0, "(I)nventory");
}

void Game::printStats() {
	Character.PrintStats();
}

void Game::printMap() {

}

void Game::printDisplay() {

}

void Game::printLog() {

}

void Game::printDecision() {

}

void Game::showDeckScreen() {

}

void Game::showInventoryScreen() {

}

void Game::showNormalScreen() {
	printDirectory();
	printStats();
	printMap();
	printDisplay();
	printLog();
	printDecision();
}
