#ifndef GAME_H
#define GAME_H
class Arena;
#include"Robot.h"
#include"Player.h"
//#include"globals.h"


class Game
{
public:
	// Constructor/destructor
	Game(int rows, int cols, int nRobots);
	~Game();

	// Mutators
	void play();

private:
	Arena* m_arena;
};


#endif
