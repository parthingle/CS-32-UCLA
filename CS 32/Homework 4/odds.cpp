
void removeOdds(vector<int>& v)
{
	for (vector<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		if (*p % 2 != 0)
		{
			vector<int>::iterator temp = v.erase(p);
			p = temp;
			if (p != v.begin()) //This is because otherwise with each deletion, one iteration will get skipped
				p--;
		}
	}
}
