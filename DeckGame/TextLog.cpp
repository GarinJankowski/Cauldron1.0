#include "pch.h"
#include "TextLog.h"

void mvprintInSize(int starty, int startx, int maxx, const char* toBePrinted);

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
	if (!Oblivious) {
		int L = 0;
		for (int y = 0; y < Lines.size(); y++) {
			if (L >= 13) {
				int size = Lines.at(y).size();
				for (int i = 0; i < Lines.at(y).size(); i++) {
					if (Lines.at(y)[i] == '#')
						size -= 2;
				}
				if (size > maxx)
					Lines.erase(Lines.begin());
				Lines.erase(Lines.begin());
				printLog();
				break;
			}

			mvprintInSize(L + 1, 44, maxx, Lines.at(y).c_str());

			int size = Lines.at(y).size();
			for (int i = 0; i < Lines.at(y).size(); i++) {
				if (Lines.at(y)[i] == '#')
					size -= 2;
			}
			if (size > maxx+2) {
				L++;
				if (size > 2 * (maxx+2))
					L++;
			}
			L++;

		}
	}
}
