

int countIncludes(string a1[], int n1, string a2[], int n2)//WORKS
{
	if (n2 == 0)
	{
		return true;
	}

	if (n2 > n1)
	{
		return false;
	}

	if (a1[0] == a2[0])
	{
		return countIncludes(a1 + 1, n1 - 1, a2 + 1, n2 - 1) + countIncludes(a1 + 1, n1 - 1, a2, n2);
	}
	else
	{
		return (countIncludes(a1 + 1, n1 - 1, a2, n2));
	}
}


void exchange(string& x, string& y)
{
	string t = x;
	x = y;
	y = t;
}
void divide(string a[], int n, string divider,
	int& firstNotLess, int& firstGreater)
{
	if (n < 0)
		n = 0;

	// It will always be the case that just before evaluating the loop
	// condition:
	//  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
	//  Every element earlier than position firstNotLess is < divider
	//  Every element from position firstNotLess to firstUnknown-1 is
	//    == divider
	//  Every element from firstUnknown to firstGreater-1 is not known yet
	//  Every element at position firstGreater or later is > divider

	firstNotLess = 0;
	firstGreater = n;
	int firstUnknown = 0;
	while (firstUnknown < firstGreater)
	{
		if (a[firstUnknown] > divider)
		{
			firstGreater--;
			exchange(a[firstUnknown], a[firstGreater]);
		}
		else
		{
			if (a[firstUnknown] < divider)
			{
				exchange(a[firstNotLess], a[firstUnknown]);
				firstNotLess++;
			}
			firstUnknown++;
		}
	}
}


void order(string a[], int n)
{
	if (n <= 1)
	{
		return;
	}
	int firstN, firstG;

	divide(a, n, a[n - 1], firstG, firstN);

	if (firstN < n)
	{
		order(a + firstN, n - firstN);
	}
	if (firstG < n)
	{
		order(a, firstG);
	}
}
