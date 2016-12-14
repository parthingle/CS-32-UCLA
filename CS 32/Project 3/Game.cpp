// Game.cpp

#include "provided.h"
#include"support.h"

class GameImpl
{
public:
	GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black);
	bool completed(int& winner) const;
	bool takeTurn();
	void play();
	int checkerAt(int c, int r) const;
private:
	Scaffold* grid;// = new Scaffold(1, 1);;
	Player* R;
	Player* B;
	int n;
	int turn;
};

GameImpl::GameImpl(int nColumns, int nLevels, int N, Player* red, Player* black)
{
	grid = new Scaffold(nColumns, nLevels);
	n = N;
	R = red;
	B = black;
	turn = RED;
}

bool GameImpl::completed(int& winner) const
{
	bool ans = false;
	//ans = true;

	bool hasN = false;
	bool thisTest = true;
		
	//To check if 
	if (hasN==false)
	{
		for (int i = 1; i <= grid->cols(); i++)
		{
			thisTest = true;
			for (int j = 1; j <= grid->levels() + 1 - n; j++)
			{
				if (grid->checkerAt(i, j) != -1)
				{
					for (int k = 0; (k < n) && thisTest; k++)
					{
						if (grid->checkerAt(i, j) != grid->checkerAt(i, j + k)) { thisTest = false; }
					}
					if (thisTest == true)
					{
						winner = grid->checkerAt(i, j);
						hasN = true;
						goto end;
					}
				}
			}
		}
	}
	if (hasN==false)

	{
		for (int i = 1; i <= grid->cols() + 1 - n; i++)
		{
			thisTest = true;
			for (int j = 1; j <= grid->levels(); j++)
			{
				if (grid->checkerAt(i, j) != -1)
				{
					for (int k = 0; (k < n) && thisTest; k++)
					{
						if (grid->checkerAt(i, j) != grid->checkerAt(i + k, j)) { thisTest = false; }
					}
					if (thisTest == true)
					{
						winner = grid->checkerAt(i, j);
						hasN = true;
						goto end;
					}
				}
			}
			
		}
	}
	//l to r up diag
	if (hasN==false)
	{
		for (int i = 1; i <= grid->cols() + 1 - n; i++)
		{
			thisTest = true;
			for (int j = 1; j <= grid->levels() + 1 - n; j++)
			{
				if (grid->checkerAt(i, j) != -1)
				{
					for (int k = 0; (k < n) && thisTest; k++)
					{
						if (grid->checkerAt(i, j) != grid->checkerAt(i + k, j + k)) { thisTest = false; }
					}
					if (thisTest == true)
					{
						winner = grid->checkerAt(i, j);
						hasN = true;
						goto end;
					}
				}
			}
		}
	}

		//l to r down diag

	if (hasN==false)
	{
		for (int i = 1; i <= grid->cols() + 1 - n; i++)
		{
			thisTest = true;
			for (int j = 1; j <= grid->levels() + 1 - n; j++)
			{
				if (grid->checkerAt(i, j) != -1)
				{
					for (int k = 0; (k < n) && thisTest; k++)
					{
						if (grid->checkerAt(i, j) != grid->checkerAt(i + k, j - k)) { thisTest = false; }
					}
					if (thisTest == true)
					{
						winner = grid->checkerAt(i, j);
						hasN = true;
						goto end;
					}
				}
			}
		}
		
	}
	end:

		ans = hasN;
	
		if ((grid->numberEmpty() == 0) && (ans == false))
		{
			winner = TIE_GAME;
			ans = true;
		}

	return ans;  //  This is not always correct; it's just here to compile
}

bool GameImpl::takeTurn()
{
	bool ans=true;
	int a;
	if (completed(a))
	{
		ans = false;
	}
	else
	{
		if (turn == RED)
		{
			grid->makeMove(R->chooseMove(*grid,n,RED), RED);
			turn = BLACK;
		}
		else
		{
			grid->makeMove(B->chooseMove(*grid, n, BLACK), BLACK);
			turn = RED;
		}
	}
	return ans;  //  This is not always correct; it's just here to compile
}

void GameImpl::play()
{
	int a;
	while (!completed(a))
	{
		grid->display();
		cout << endl;
		takeTurn();
	}
	

	switch (a)
	{
	case RED:
		cout << "RED WINS!" << endl;
		break;
	case BLACK:
		cout << "BLACK WINS" << endl;
		break;
	default:
		cout << "TIE!" << endl;
		break;
	}
}

int GameImpl::checkerAt(int c, int r) const
{
	return grid->checkerAt(c,r);  //  This is not always correct; it's just here to compile
}

//******************** Game functions *******************************

// These functions simply delegate to GameImpl's functions.
// You probably don't want to change any of this code.

Game::Game(int nColumns, int nLevels, int N, Player* red, Player* black)
{
	m_impl = new GameImpl(nColumns, nLevels, N, red, black);
}

Game::~Game()
{
	delete m_impl;
}

bool Game::completed(int& winner) const
{
	return m_impl->completed(winner);
}

bool Game::takeTurn()
{
	return m_impl->takeTurn();
}

void Game::play()
{
	m_impl->play();
}

int Game::checkerAt(int c, int r) const
{
	return m_impl->checkerAt(c, r);
}
