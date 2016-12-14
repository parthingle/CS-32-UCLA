#include<iostream>
#include<cassert>
#include"SSNSet.h"
using namespace std;


int main()
{
	SSNSet s1;

	assert(s1.add(123456));//testing add() function
	assert(s1.add(654321));
	assert(s1.add(234432));
	assert(!s1.add(123456));//testing if the underlying Set functions work correctly
	assert(s1.size() == 3);//testin size() function

	s1.print();


}