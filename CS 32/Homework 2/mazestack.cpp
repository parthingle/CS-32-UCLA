#include<stack>
#include<queue>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
	// Return true if there is a path from (sr,sc) to (er,ec)
	// through the maze; return false otherwise
	bool ans = false;
	std::stack<Coord> m_stack;
	Coord start(sr, sc);
	Coord end(er, ec);
	m_stack.push(start);
	maze[sr][sc] = '0';
	int i = 1;

	while (m_stack.size()>0)
	{
		
		int r_curr = m_stack.top().r();
		int c_curr = m_stack.top().c();
		cout << r_curr << ", " << c_curr << endl;
		m_stack.pop();
		
		if (r_curr == er&&c_curr == ec)
		{
			ans = true;
			break;
		}
		

		if (maze[r_curr - 1][c_curr] == '.')
		{ 
			Coord north(r_curr - 1, c_curr);
			m_stack.push(north);
			maze[r_curr ][c_curr-1] = '0';
			//cout << r_curr << ", " << c_curr << " north" << endl;
			//r_curr--;
			//cout << r_curr << ", " << c_curr <<" north\n****************************************"<< endl;
			cout << "north" << endl;
		}
		if (maze[r_curr][c_curr+1 ] == '.')
		{
			Coord east(r_curr, c_curr + 1);
			m_stack.push(east);
			maze[r_curr][c_curr + 1] = '0';
		//	cout << r_curr << ", " << c_curr << " east" << endl;
			//c_curr++;
			//cout << r_curr << ", " << c_curr <<" east\n******************************************"<< endl;
			cout << "east" << endl;
		}
		if (maze[r_curr+1][c_curr] == '.')
		{
			Coord south(r_curr + 1, c_curr);
			m_stack.push(south);
			maze[r_curr + 1][c_curr] = '0';
			//cout << r_curr << ", " << c_curr << " south" << endl;
			//r_curr++;
			//cout << r_curr << ", " << c_curr <<" south\n*****************************************"<< endl;
			cout << "south" << endl;
		}
		if (maze[r_curr][c_curr-1] == '.')
		{
			Coord west(r_curr, c_curr - 1);
			m_stack.push(west);
			maze[r_curr][c_curr - 1] = '0';
			//cout << r_curr << ", " << c_curr << " west" << endl;
			//c_curr--;
			
			//cout << r_curr << ", " << c_curr <<" west\n********************************************"<< endl;
			cout << "west" << endl;
		}
		cout << "********** " << i << " **********" << endl;
		i++;
	}
	return ans;
}