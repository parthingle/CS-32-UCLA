
void removeBad(list<Movie*>& li)
{
	list <Movie*>::iterator it1, it3;
	it1 = li.begin();

	while (it1 != li.end())
	{
		if ((*it1)->rating() <= 50)
		{
			delete *it1;
			it1 = li.erase(it1);
			if (it1 != li.begin())
				it1--;		
		}
		it1++;
	}
}

