#pragma once
#ifndef TEXTLOG_H
#define TEXTLOG_H

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <string>
#include <vector>

using namespace std;

class TextLog
{
public:
	TextLog();
	~TextLog();

	int maxx;
	int maxy;
	bool Oblivious = FALSE;
	vector<string> Lines;

	void PushPop(string pushed);
	void printLog();
};
#endif //TEXTLOG_H

