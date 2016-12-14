// Player.cpp

#include "provided.h"
#include"support.h"
#include <string>
#include<ctime>
using namespace std;

class HumanPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

class BadPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

class SmartPlayerImpl
{
public:
	int chooseMove(const Scaffold& s, int N, int color);
};

int HumanPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
	int cn=-1;
	cout << "Column No:\t";
	cin >> cn;
	while ((cn <= 0 || cn > s.cols()))
	{		
		cout << "INVALID CHOICE!!\nTRY AGAIN:\t";
		cin >> cn;
	}
	if (s.numberEmpty() > 0)
	{
		Scaffold other = s;
		bool a = false;

		while (a == false)
		{
			a = other.makeMove(cn, color);
			if (a == false)
			{
				cout << "Column Full!\nTry again: \t";
				cin >> cn;
				while ((cn <= 0 || cn > s.cols()))
				{
					cout << "INVALID CHOICE!!\nTRY AGAIN:\t";
					cin >> cn;
				}
			}

		}
	}

	return cn;  //  This is not always correct; it's just here to compile
}

int BadPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
	int ch = -1;
	if (s.numberEmpty() > 0)
	{
		Scaffold other = s;
		bool a = false;
		
		int col = s.cols();
		int j(1);

		while ((a == false)&&(j<=col))
		{
			a = other.makeMove(j, color);
			if (a == true)
			{
				ch = j;
				break;
			}
			j++;
		}
	}

	return ch;  //  This is not always correct; it's just here to compile
}

int SmartPlayerImpl::chooseMove(const Scaffold& s, int N, int color)
{
	/*	
	Scaffold other=s;
	int depth = 1;
	stack<int> a;


	determineBestComputerMove(other,depth,color,N,a);

	
	int q = a.top();
	Scaffold other2(s);
	for (size_t j = 0; j < a.size(); j++)
	{
		a.pop();
		if (a.top() > q)
		{
			if(other2.makeMove(a.top(),color))
				q = a.top();
		}

	}
	*/
	int ch = -1;
	if (s.numberEmpty() > 0)
	{
		Scaffold other = s;
		bool a = false;

		int col = s.cols();
		int j(1);

		while ((a == false) && (j <= col))
		{
			a = other.makeMove(j, color);
			if (a == true)
			{
				ch = j;
				break;
			}
			j++;
		}
	}


	return ch;  //  This is not always correct; it's just here to compile
}

//******************** Player derived class functions *************************

// These functions simply delegate to the Impl classes' functions.
// You probably don't want to change any of this code.

HumanPlayer::HumanPlayer(string nm)
	: Player(nm)
{
	m_impl = new HumanPlayerImpl;
}

HumanPlayer::~HumanPlayer()
{
	delete m_impl;
}

int HumanPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}

BadPlayer::BadPlayer(string nm)
	: Player(nm)
{
	m_impl = new BadPlayerImpl;
}

BadPlayer::~BadPlayer()
{
	delete m_impl;
}

int BadPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}

SmartPlayer::SmartPlayer(string nm)
	: Player(nm)
{
	m_impl = new SmartPlayerImpl;
}

SmartPlayer::~SmartPlayer()
{
	delete m_impl;
}

int SmartPlayer::chooseMove(const Scaffold& s, int N, int color)
{
	return m_impl->chooseMove(s, N, color);
}
