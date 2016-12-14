#ifndef HISTORY_H
#define HISTORY_H

#include"Arena.h"
class History
{
	Arena h_Arena;

public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;
};

#endif
