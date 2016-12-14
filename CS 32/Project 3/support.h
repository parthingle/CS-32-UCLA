#include<iostream>
#include<vector>
#include<stack>
#include"provided.h"
#include<random>

using namespace std;

class Coord
{
	int m_x;
	int m_y;
public:
	Coord(int x, int y) :m_x(x), m_y(y) {}
	Coord() : m_x(0), m_y(0) {}

	int x() { return m_x; }
	int y() { return m_y; }

	Coord& operator=(const Coord& rhs);
};

int opp(int i)
;

char draw(int i);

bool hasSpot(const Scaffold& scaf, int col);

int minimax(Scaffold& s, int col, int depth, int n, int clr);

int determineBestComputerMove(Scaffold& s, int depth, int clr, int n, stack<int>& ratings);
int determineBestHumanMove(Scaffold& s, int depth, int clr, int n, stack<int>& ratings);

int rater(const Scaffold& s, int clr, int n);