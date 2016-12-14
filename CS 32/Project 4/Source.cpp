#include "tree.h"
const int N = 5;

void createDelta(istream& oldf, istream& newf, ostream& deltaf)
{
	string olds2;
	string olds = "";

	while (getline(oldf, olds2))
	{
		olds += olds2;
		//olds += '\n';
	}

	string news2;
	string news = "";

	while (getline(newf, news2))
	{
		news += news2;
		//news += '\n';
	}

	int i = 0;
	BST oldTree;

	while (i + N < olds.size())
	{
		string temp = olds.substr(i, N);
		oldTree.add(temp, i);
		cout << temp << endl;;
		i++;
	}
	cout << "\n\n" << endl;
	vector<string> newL;

	int j = 0;
	int newlen = 0;

	while (j + N <= news.size())
	{
		string temp = news.substr(j, N);
		newL.push_back(temp);
		cout << temp << endl;
		j += N;
		newlen++;
	}
	cout << "\n\n" << endl;
	i = 0;
	int q = newlen%N;
	while (i < newlen)
	{

		if (oldTree.find(newL[i]) == -1)
		{
			string temp = "";
			int thisLen = 0;

			while (i < newlen&&oldTree.find(newL[i]) == -1)
			{
				temp += newL[i];
				i++;
				thisLen++;
			}
			deltaf << "A" << thisLen*N << ":" << temp;
		}
		else
		{
			int k = oldTree.find(newL[i]);
			int thisLen = 0;
			while (i < newlen && oldTree.find(newL[i]) != -1)
			{
				thisLen++;
				i++;
			}
			deltaf << "C" << thisLen*N << "," << k;
		}

	}

}


bool applyDelta(istream& oldf, istream& deltaf, ostream& newf)
{
	bool valid = true;
	string olds2;
	string olds = "";

	while (getline(oldf, olds2))
	{
		olds += olds2;
	}
	string delta2;
	string delta = "";

	while (getline(deltaf, delta2))
	{
		delta += delta2;
	}

	int xyz = 0;
	while (delta.size() != 0)
	{
		cout << "loop run no: " << xyz << endl;

		if (delta[0] == 'A')
		{
			delta = delta.substr(1);
			if (!isdigit(delta[0]))
			{
				cout << "Invalid 1\n";
				valid = false;
				break;
			}
			int len = 0;
			while (delta.size()!=0&&isdigit(delta[0]))
			{
				int curr = delta[0] - '0';
				len = (10 * len) + curr;
				delta = delta.substr(1);
			}
			cout << len << endl;
			if (delta[0] != ':')
			{
				cout << "Invalid 2\n";
				valid = false;
				break;
			}
			delta = delta.substr(1);
			string temp = delta.substr(0, len);
			newf << temp;
			delta=delta.substr(len);
		}
		else if (delta[0] == 'C')
		{
			delta = delta.substr(1);
			if (!isdigit(delta[0]))
			{
				cout << "Invalid 3\n";
				valid = false;
				break;
			}
			int len = 0;
			while (delta.size()!=0&&isdigit(delta[0]))
			{
				int curr = delta[0] - '0';
				len = (10 * len) + curr;
				delta = delta.substr(1);
			}
			cout << len << endl;
			if (delta[0] != ',')
			{
				cout << "Invalid 4\n";
				valid = false;
				break;
			}
			delta = delta.substr(1);
			if (!isdigit(delta[0]))
			{
				cout << "Invalid 5\n";
				valid = false;
				break;
			}

			int off = 0;
			while (delta.size()!=0&&isdigit(delta[0]))
			{
				int curr = delta[0] - '0';
				off = (10 * off) + curr;
				delta = delta.substr(1);
			}
			cout << off << endl;
			string temp = olds.substr(off, len);
			newf << temp;
		}
		else
		{
			cout << "Invalid X" << endl;
			cout << delta[0] << endl;
			break;
		}


		xyz++;
	}

	return valid;
}



int main()
{
	ifstream fileold("smallmart1.txt");
	ifstream filenew("smallmart2.txt");

	ofstream newf("newf.txt");
	//ofstream logf("logf.txt");
	cout << "No problem" << endl;
	createDelta(fileold, filenew, newf);
	cout << "done" << endl;

	/*ifstream delt("newf.txt");
	ifstream oldf("smallmart1.txt");

	ofstream newf("output.txt");
	if ((!delt) || (!oldf) || (!newf))
	{
		cout << "file open error" << endl;
		return 0;
	}
	cout << "files opened!" << endl;
	assert(1 > 0);
	assert(applyDelta(oldf, delt, newf));
	cout << "done" << endl;*/
}
