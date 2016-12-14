#include "Set.h"

Set::Set()
{
	m_size = 0;
	max_size = DEFAULT_MAX_ITEMS;
	string m_Set[DEFAULT_MAX_ITEMS];

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
int Set::size() const
{
	return m_size;

}

bool Set::empty() const
{
	bool ans = true;
	if (m_size > 0)
	{
		ans = false;
	}
	return ans;
}

bool Set::insert(const ItemType& value) 
{
	bool chk = true;
	for (int i = 0; i < m_size; i++)
	{
		if (m_Set[i] == value)
		{
			chk = false;
		}
	}
	if (chk == true)
	{
		if (m_size < max_size)
		{
			m_Set[m_size] = value;
			m_size++;
		}
		else
		{
			chk = false;
		}
	}
	return chk;
}

bool Set::erase(const ItemType& value)
{
	int position = 0;
	bool chk = false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_Set[i] == value)
		{
			chk = true;
			position = i;
			break;
		}
	}
	if (chk == true)
	{
		ItemType temp;

		for (int j = position; j < m_size-1; j++)
		{
			temp = m_Set[j];
			m_Set[j] = m_Set[j+1];
			
		}
		//m_Set[m_size-1] = 0;
		m_size--;
	}
	return chk;
}

bool Set::contains(const ItemType& value) const
{
	bool ans = false;
	for (int i = 0; i < m_size; i++)
	{
		if (m_Set[i] == value)
		{
			ans = true;
			break;
		}
	}
	return ans;
}

bool Set::get(int i, ItemType& value) const
{
	bool chk = false;
	if ((i >= 0) && (i < m_size))
	{
		chk = true;
		value = m_Set[i];
	}

	return chk;
}

void Set::swap(Set& other)
{
	//Switching m_size variable values
	int tempI;
	tempI = other.m_size;
	other.m_size = m_size;
	m_size = tempI;
	//Swithcing max_size variable values
	int temp2;
	temp2 = max_size;
	max_size = other.max_size;
	other.max_size = temp2;


	//Switching m_Sets
	int runner = 0;

	if (m_size >= other.m_size)
	{
		runner = other.m_size;
	}
	else
	{
		runner = m_size;
	}
	ItemType temp;
	for (int i = 0 ; i < runner; i++)
	{
		temp = m_Set[i];
		m_Set[i] = other.m_Set[i];
		other.m_Set[i] = temp;
	}
	int diff = m_size - other.m_size;

	if (diff < 0)
	{
		diff *= -1;
	}

	if (m_size != other.m_size)
	{
		
		if (m_size > other.m_size)
		{
			for (int k = 0; k < diff; k++)
			{
				m_Set[other.m_size + k] = other.m_Set[other.m_size + k];
				//other.m_Set[other.m_size + k] = 0;
			}
		}
		else
		{
			for (int k = 0; k < diff; k++)
			{
				other.m_Set[m_size + k] = m_Set[m_size + k];
				//m_Set[m_size + k] = 0;
					
			}
		}
	}

}