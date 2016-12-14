

bool pathExists(int a[][10], int sr, int sc, int er, int ec)
{
	if ((sr == er) && (sc == ec))
	{
		return true;
	}
	a[sr][sc] = '0';//update it as "already visited"

	if (a[sr - 1][sc] == '.')
	{
		if (pathExists(a, sr - 1, sc, er, ec))
		{
			return true;
		}
	}
	if (a[sr+1][sc] == '.')
	{
		if (pathExists(a, sr + 1, sc, er, ec))
		{
			return true;
		}
	}
	

	if (a[sr][sc-1] == '.')
	{
		if (pathExists(a, sr, sc - 1, er, ec))
		{
			return true;
		}
	}
	if (a[sr][sc+1] == '.')
	{
		if (pathExists(a, sr, sc + 1, er, ec))
		{
			return true;
		}
	}
		

	return false;

}


