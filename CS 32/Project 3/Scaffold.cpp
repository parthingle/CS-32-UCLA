// Scaffold.cpp

#include "provided.h"
#include"support.h"
using namespace std;

class ScaffoldImpl
{
	vector<vector<int>> grid;
	int n_cols;
	int n_rows;
	stack<Coord> last;

public:
	ScaffoldImpl(int nColumns, int nLevels);
	int cols() const;
	int levels() const;
	int numberEmpty() const;
	int checkerAt(int column, int level) const;
	void display() const;
	bool makeMove(int column, int color);
	int undoMove();

	int rows() { return n_rows; }
	int cols() { return n_cols; }

};

ScaffoldImpl::ScaffoldImpl(int nColumns, int nLevels)
{
	if (nLevels <= 0 || nColumns <= 0)
	{
		cerr << "Invalid size!!" << endl;
	}
	else
	{
		n_cols = nColumns;
		n_rows = nLevels;
		grid.resize(nLevels);
		for (int i = 0; i < nLevels; i++)
			grid[i].resize(nColumns);

		for (int i = 0; i < nLevels; i++)
		{
			for (int j = 0; j < nColumns; j++)
			{
				grid[i][j] = -1;
			}
		}
	}
	Coord a(0, 0);
	last.push(a);

}

int ScaffoldImpl::cols() const
{
	return n_cols;
}

int ScaffoldImpl::levels() const
{
	return n_rows;
}

int ScaffoldImpl::numberEmpty() const
{
	int ne(0);

	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			if (grid[i][j] == -1)
				ne++;
		}
	}

	return ne;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::checkerAt(int column, int level) const
{
	int ans=-1;
	if ((column > 0) && (column <= n_cols)&&(level>0)&&(level<=n_rows))
	{
		ans = grid[level - 1][column - 1];
	}
	return ans;  //  This is not always correct; it's just here to compile
}

void ScaffoldImpl::display() const
{
	for (int i = n_rows-1; i >=0 ; i--)
	{
		for (int j = 0; j < n_cols; j++)
		{
			cout << "|" << draw(grid[i][j]);
		}
		cout << "|\n";
	}
	for (int i = 0; i < n_cols; i++)
	{
		cout << "+-";
	}
	cout << "+\n";
}

bool ScaffoldImpl::makeMove(int column, int color)
{
	bool ans = false;
	if ((column > 0) && (column <= n_cols))
		ans = false;
	int i;
	for (i = 0; i < n_rows; i++)
	{
		if (grid[i][column - 1] == -1)
		{
			grid[i][column - 1] = color;
			ans = true;
			break;
		}
	}

	if (ans == true)
	{
		Coord a(i, column - 1);
		last.push(a);
	}

	return ans;  //  This is not always correct; it's just here to compile
}

int ScaffoldImpl::undoMove()
{
	int ans = 0;

	if (!last.empty())
	{
		ans = last.top().y()+1;
		int level = last.top().x();
		grid[level][ans - 1] = -1;
		last.pop();
	}

	return ans;  //  This is not always correct; it's just here to compile
}

//******************** Scaffold functions *******************************

// These functions simply delegate to ScaffoldImpl's functions.
// You probably don't want to change any of this code.

Scaffold::Scaffold(int nColumns, int nLevels)
{
	m_impl = new ScaffoldImpl(nColumns, nLevels);
}

Scaffold::~Scaffold()
{
	delete m_impl;
}

Scaffold::Scaffold(const Scaffold& other)
{
	m_impl = new ScaffoldImpl(*other.m_impl);
}

Scaffold& Scaffold::operator=(const Scaffold& rhs)
{
	if (this != &rhs)
	{
		Scaffold temp(rhs);
		swap(m_impl, temp.m_impl);
	}
	return *this;
}

int Scaffold::cols() const
{
	return m_impl->cols();
}

int Scaffold::levels() const
{
	return m_impl->levels();
}

int Scaffold::numberEmpty() const
{
	return m_impl->numberEmpty();
}

int Scaffold::checkerAt(int column, int level) const
{
	return m_impl->checkerAt(column, level);
}

void Scaffold::display() const
{
	m_impl->display();
}

bool Scaffold::makeMove(int column, int color)
{
	return m_impl->makeMove(column, color);
}

int Scaffold::undoMove()
{
	return m_impl->undoMove();
}
