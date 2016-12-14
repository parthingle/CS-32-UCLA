#include "newSet.h"

Set::Set(int i)
{
	if (i > 0)
	{
		m_size = 0;
		max_size = i;
		m_Set = new ItemType[i];
	}
	else
	{
		cout << "Size cannot be negative or zero!!\nSet not initialized!!\n";
	}
}

Set::Set(const Set & other)
{
	Set temp(other.max_size);
	temp.m_size = other.m_size;

	for (int i = 0; i < other.m_size; i++)
	{
		temp.m_Set[i] = other.m_Set[i];
	}
	swap(temp);
}

Set& Set::operator=(const Set& rhs)
{
	if (this != *rhs)
	{
		Set temp(rhs);
		swap(temp);
	}
	return *this;
}

Set::~Set()
{
	delete [] m_Set;
}

bool Set::empty() const
{
	bool ans = false;
	if (m_size == 0)
	{
		ans = true;
	}
	return ans;
}

int Set::size() const
{
	return m_size;
}

bool Set::contains(const ItemType & value) const
{
	bool chk = false;
	for (int i = 0; i < m_size; i++)
	{
		if (m_Set[i] == value)
		{
			chk = true;
		}
	}
	return chk;
}

bool Set::get(int i, ItemType & value) const
{
	bool ans = false;
	if ((i >= 0) && (i < m_size))
	{
		ans = true;
		value = m_Set[i];
	}
	return ans;
}

void Set::swap(Set & other)
{
	//swapping m_size variable values
	int t1;
	t1 = m_size;
	m_size = other.m_size;
	other.m_size = t1;

	//swapping max_size variable values
	int t2;
	t2 = max_size;
	max_size = other.max_size;
	other.max_size = t2;

	//swapping pointers to the allocated data
	ItemType* ptr;
	ptr = m_Set;
	m_Set = other.m_Set;
	other.m_Set = ptr;

}


bool Set::insert(const ItemType& value)
{
	bool chk = true;

	if ((m_size >= max_size)||(contains(value)==true))
	{
		chk = false;
	}
	if (chk == true)
	{
		m_Set[m_size] = value;
		m_size++;
	}

	return chk;

}

bool Set::erase(const ItemType& value)
{
	bool chk = false;
	int pos,i,q;
	if (contains(value) == true)
	{
		chk = true;
		for (pos = 0; pos < m_size; pos++)
		{
			if (value == m_Set[pos])
			{
				break;
			}
		}

		Set temp(max_size);

		for (i = 0; i < pos;i++)
		{
			temp.m_Set[i] = m_Set[i];
			temp.m_size++;
		}
		q = i;
		i++;

		for (int j = i; j < m_size; j++)
		{
			temp.m_Set[q] = m_Set[j];
			temp.m_size++;
		}
		
		swap(temp);
	}
	return chk;

}
