
//1
bool allTrue(const string a[], int n)//WORKS
{
	if (n <= 0)
	{
		return true;
	}
	if (somePredicate(a[0]))
	{
		if (n == 1)
		{	
			return true;
		}
		return allTrue(a+1, n - 1);
	}
	return false;
}

//2
int countFalse(string a[], int n)//WORKS
{
	if (n > 1)
	{
		if (somePredicate(a[0]))
		{
			return countFalse(a + 1, n - 1);
		}
		else
		{
			return (1 + countFalse(a + 1, n - 1));
		}
	}
	else
	{
		return 0;
	}
}


//3
int indexOfLeast(const string a[], int n)//WORKS
{
	if (n == 1)
		return 0;

	if (n <= 0)
		return -1;

	if (a[n - 1] < a[indexOfLeast(a, n - 1)])
		return n - 1;

	return indexOfLeast(a, n - 1);
}

//4
int firstFalse(const string a[], int n)//WORKS
{

	if (n < 0)
		return 0;
	if (n == 0)
		return -1;

	if(n>0)
		if (somePredicate(a[0]))
		{
			return firstFalse(a + 1, n - 1);
		}
		else
		{
			return n - 1;
		}

}

//5
int includes(string a1[], int n1, string a2[], int n2)//WORKS
{
	if (n2 > n1)
	{
		return false;
	}

	if (n2 == 0)
	{
		return true;
	}

	if (a1[0] == a2[0])
		return includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
	else
		return includes(a1 + 1, n1 - 1, a2, n2);

}




