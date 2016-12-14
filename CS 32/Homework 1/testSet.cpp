#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
	Set uls;
	assert(uls.insert(10));
	assert(uls.insert(20));
	assert(uls.size() == 2);
	assert(uls.contains(20));
	ItemType x = 30;
	assert(uls.get(0, x) && (x == 10 || x == 20));
	ItemType x2 = 40;
	assert(uls.get(1, x) && (x == 10 || x == 20) &&
		x != x2);
}

int main()
{
	Set s;
	assert(s.empty());
	ItemType x = 9876543;
	assert(!s.get(42, x) && x == 9876543); // x unchanged by get failure
	s.insert(123456789);
	assert(s.size() == 1);
	assert(s.get(0, x) && x == 123456789);

	Set s2;
	ItemType i;
	for ( i = 0; i < 100; i++)
	{
		assert(s2.insert(i));
	}
	i++;
	assert(!s2.insert(i));

	//Testing swap() function/////////////////////////////////////////////////////
	Set t1;

	for (int i = 0; i < 5; i++)
	{
		t1.insert(i);
	}

	Set t2;

	for (int j = 0; j < 3; j++)
	{
		t2.insert(j);
	}
	assert(t1.size() == 5);
	assert(t2.size() == 3);

	t1.swap(t2);

	assert(t1.size() == 3);
	assert(t2.size() == 5);
	//swap() function test completed//////////////////////////////////////

	Set t3;
	for (int i = 0; i < 100; i++)
	{
		assert(t3.insert(i));//checks if 100 values can be safely entered
	}

	Set t4;
	for (i = 0; i < 100; i++)
	{
		assert(t4.insert(i));//checks if 100 values can be safely entered
	}

	assert(!t3.insert(2000));//t3 is already full
	assert(!t3.insert(3000));//t4 is already full

	assert(t4.erase(50));//removes 50 from the Set

	assert(t4.size() == 99);//checks if size reduces to 99

	assert(!t4.contains(50));//checks if 50 is removed

	ItemType k;
	Set t5;
	t5.insert(45);
	t5.get(0, k);
	assert(k == 45);//checks if the value 45 was properly inserted in set t3 and retrieved with the get function

	test();

	cout << "Passed all tests" << endl;
}