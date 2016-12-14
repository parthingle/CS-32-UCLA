#include "SSNSet.h"

SSNSet::SSNSet()
{
	Set my_Set;

}

bool SSNSet::add(ItemType ssn)
{
	return my_Set.insert(ssn);


}

int SSNSet::size() const
{
	int i= my_Set.size();
	return i;
}

void SSNSet::print() const
{
	for (int i = 0; i < size(); i++)
	{
		ItemType temp;
		my_Set.get(i, temp);
		cout << temp << endl;
	}
}
