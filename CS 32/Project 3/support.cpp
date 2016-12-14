#include "support.h"
#include"provided.h"
Coord & Coord::operator=(const Coord & rhs)
{
	if (this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
	}
	return *this;
}


char draw(int i) 
{
	switch (i)
	{
	case -1:
		return ' ';
		break;

	case 0:
		return 'R';
		break;

	case 1:
		return 'B';
		break;
	default:
		return ' ';
		break;
	}
}

bool hasSpot(const Scaffold& scaf, int col)
{
	bool ans = false;
	for (int i = 1; i <= scaf.levels(); i++)
	{
		if (scaf.checkerAt(i, col) == -1)
		{

		}
	}
	return ans;
}



bool completed(Scaffold* grid, int& winner, int n) 
{
	bool ans = false;
	//ans = true;

	bool hasN = false;
	bool thisTest = true;

	//To check if 
	if (hasN == false)
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
	if (hasN == false)

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
	if (hasN == false)
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

	if (hasN == false)
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




/*int rater(Scaffold& s, int clr, int n)
{
	
	if
	{

	}
}*/

int opp(int i)
{
	if (i == BLACK)
	{
		return RED;
	}
	else
		return BLACK;
}

/*
int determineBestComputerMove(Scaffold& s, int depth, int clr, int n, stack<int>& ratings)
{
	for (int i = 1; i <= s.cols(); i++)
	{
		
		if (s.makeMove(i, clr))
		{
			s.makeMove(i, clr);
			int a;

			if (completed(&s, a, n))
			{
				if (a == clr)
				{
					ratings.push(i);
					
					return 1;
				}
				if (a == opp(clr))
					return -1;
				if (a == TIE_GAME)
					return 0;
			}
			else
			{
				return determineBestHumanMove(s, depth + 1, opp(clr), n, ratings);
			}
		}
	}
}

int determineBestHumanMove(Scaffold& s, int depth, int clr, int n, stack<int>& ratings)
{
	for (int i = 1; i <= s.cols(); i++)
	{

		if (s.makeMove(i, clr))
		{
			s.makeMove(i, clr);
			int a;

			if (completed(&s, a, n))
			{
				if (a == clr)
				{
					ratings.push(i);
					
					return 1;
				}
				if (a == opp(clr))
					return -1;
				if (a == TIE_GAME)
					return 0;
			}
			else
			{
				return determineBestComputerMove(s, depth + 1, opp(clr), n, ratings);
			}
		}
	}
}
*/