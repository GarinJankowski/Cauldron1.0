#include "pch.h"
#include "Deck.h"

WINDOW *makeWindow(int height, int width, int starty, int startx);
int rtd(int multiplier, int power);

Deck::Deck()
{
	
}


Deck::~Deck()
{
}

void Deck::deckScreen() {
	for (int y = 0; y < 14; y++) {
		mvprintw(y, 44, "                                 ");
	}

	vector<Card> screendeck = cardDeck;
	int x = 45;
	int y = 2;

	while(screendeck.size()>0) {
		Card cardnow = screendeck.at(0);
		int counter = 0;
		for (int i = 0; i < screendeck.size(); i++) {
			if (screendeck.at(i).CardName == cardnow.CardName) {
				screendeck.erase(screendeck.begin()+i);
				i--;
				counter++;
			}
		}

		mvprintw(0, 50, "Deck (ESC to exit deck)");

		if (cardnow.CardType == "Attack") {
			attron(COLOR_PAIR(1));
		}
		else if (cardnow.CardType == "Defend") {
			attron(COLOR_PAIR(2));
		}
		else if (cardnow.CardType == "Spell") {
			attron(COLOR_PAIR(3));
		}
		else if (cardnow.CardType == "Special") {
			standend();
		}
		else if (cardnow.CardType == "Negative") {
			attron(COLOR_PAIR(5));
		}

		if (counter == 1)
			mvprintw(y, x, "%s", cardnow.CardName);
		else
			mvprintw(y, x, "%ix %s", counter, cardnow.CardName);
		standend();
		y++;
		if (y > 13) {
			x += 16;
			y = 0;
		}
	}
}

Card Deck::addCard(Card cardToBeAdded) {
	cardDeck.push_back(cardToBeAdded);
	return cardToBeAdded;
}

//rmeove Card from deck
Card Deck::removeCard(Card cardToBeRemoved, Character &guy) {
	for (int i = 0; i < cardDeck.size(); i++) {
		if (cardDeck.at(i).CardName == cardToBeRemoved.CardName) {
			//remove mods from card (probably unnecessary)
			cardDeck.at(i).removeMods(guy);
			cardDeck.erase(cardDeck.begin() + i);
			break;
		}
	}
	return cardToBeRemoved;
}

int Deck::size() {
	return cardDeck.size();
}

Card Deck::at(int i) {
	return cardDeck.at(i);
}
