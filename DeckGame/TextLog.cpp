#include "pch.h"
#include "TextLog.h"

void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted, bool Fuzzy, bool Log);
void manualBox(string typebox, int colorpair);

TextLog::TextLog()
{
	maxx = 32;
	maxy = 13;
	Lines.push_back("#g Defeat the final boss.#o");
}


TextLog::~TextLog()
{
}

void TextLog::PushPop(string pushed) {
	AllLines.push_back(pushed.c_str());

	int size = pushed.size();
	for (int i = 0; i < pushed.size(); i++) {
		if (pushed[i] == '#')
			size-=2;
	}
	if (Lines.size() >= 14) {
		Lines.erase(Lines.begin());
		if(size > maxx)
			Lines.erase(Lines.begin());
		if (size > maxx*2)
			Lines.erase(Lines.begin());
	}
	/*if (Lines.size() >= 13 && size > maxx) {
		Lines.erase(Lines.begin());
	}*/
	Lines.push_back(pushed.c_str());
}

void TextLog::printLog() {
	for (int y = 0; y < maxy+2; y++) {
		mvprintw(y, 44, "                                  ");
	}
		int L = 0;
		int x = 44;
		for (int y = 0; y < Lines.size(); y++) {
			int size = Lines.at(y).size();
			for (int i = 0; i < Lines.at(y).size(); i++) {
				if (Lines.at(y)[i] == '#')
					size -= 2;
			}
			if (L >= 13) {
				/*int size = Lines.at(y).size();
				for (int i = 0; i < Lines.at(y).size(); i++) {
					if (Lines.at(y)[i] == '#')
						size -= 2;
				}*/
				if (size > maxx)
					Lines.erase(Lines.begin());
				Lines.erase(Lines.begin());
				printLog();
				break;
			}

			bool fuzzy = FALSE;
			if (Oblivious)
				fuzzy = TRUE;

			const char* toBePrinted = Lines.at(y).c_str();
			mvprintInSize(L + 1, x, maxx, toBePrinted, fuzzy, TRUE);
			//x = 44;

			/*int size = Lines.at(y).size();
			for (int i = 0; i < Lines.at(y).size(); i++) {
				if (Lines.at(y)[i] == '#')
					size -= 2;
			}*/
			if (size > maxx+2) {
				L++;
				if (size > 2 * (maxx+2))
					L++;
			}
			L++;

		}
}

void TextLog::printAllLog(int starti, int endi) {
	erase();
	
	int y = 1;
	int x = 1;

	bool fuzzy = FALSE;
	if (Oblivious)
		fuzzy = TRUE;
	
	if (endi >= AllLines.size())
		endi = AllLines.size() - 1;
	for (int i = starti; i < endi; i++) {
		if (y < 24) {
			mvprintInSize(y, x, 0, AllLines.at(i).c_str(), fuzzy, FALSE);
		}
		y++;
	}
}
