#include "Set.h"

Set::Set()
{
	m_size = 0;//Initialize with size 0
	dummy = new Node;//create a 'dummy' node to be used as a starting and ending point
	head = dummy;//Point the head to this dummy node	
	dummy->m_next = dummy;//Point the m_next 
	dummy->m_prev = dummy;//and m_prev to itself to initialize a circular LL

}

Set::Set(const Set & other)
{
	m_size = 0;//Initialize with size 0
	dummy = new Node;//create a 'dummy' node to be used as a starting and ending point
	head = dummy;//Point the head to this dummy node	
	dummy->m_next = dummy;//Point the m_next 
	dummy->m_prev = dummy;//and m_prev to itself to initialize a circular LL

	Node* q;
	///ItemType b;
	q = other.head;
	Node* p = q;
	q=q->m_next;//Point q to the first element of the other LL
	while (q != p)//This loop runs until q points to the head of other
	{
		insert(q->m_data);//insert individual elements into the newly initialize LL ///NOTE: the size of the new LL is updated one at a tiime when elements are inserted into to it
		q = q->m_next;
	}
}

Set & Set::operator=(const Set & rhs)
{
	Set temp(rhs);//create a new Set initialized as an identical to rhs
	swap(temp);//this new Set is swapped with this
	//once temp leaves its namespace, the destructor deletes it appropriately
	
	return *this;

}

Set::~Set()
{
	Node* p = head;//assigns a pointer to the head of the Set
	Node* q = p;
	p = p->m_next;//creates another pointer that points to head, and the original pointer points to head->m_next
	while (p != head)//until the forward pointer reaches head again...
	{
		q = p; 
		p = p->m_next;
		delete q;//p propogates to the next Node, and q deletes the previous
	}
	delete p;//finally the dummy node is deleted
}


bool Set::contains(const ItemType & value) const
{
	bool chk = false;
	Node* p;
	p = head->m_next;//assigns the new node pointer to the first element of the LL
	while (p != head)
	{
		if (p->m_data == value)//if the value of the m_data of the node p is currently pointing to is equal to the value
		{
			chk = true;//chk is made true
		}
		p = p->m_next;//p is traversed through the LL until it reaches head again
	}
	return chk;
}

bool Set::get(int pos, ItemType & value) const
{
	bool chk = (pos<m_size);//if the position entered is greater than the number of elements in the LL, chk=false
	
	if (chk == true)//if the pos entered is valid...
	{
		Node* p;
		p = head->m_next;//p is assigned to the first element in the LL
		int i = pos;
		while (i > 0)
		{
			p = p->m_next;//p is traversed throught the LL until it points to element pos 
			i--;
		}
		value = p->m_data;//once the right node is reached, its value is assigned to 'calue'
	}
	return chk;
}


void Set::swap(Set & other)
{
	//swapping the head variables
	Node* temp;
	temp = head;
	head = other.head;
	other.head = temp;

	//due to the structure of the LL, just by swapping the head pointers, we can essentially swap the entire Set

	//swapping the m_size variable values
	int t;
	t = m_size;
	m_size = other.m_size;
	other.m_size = t;

}

Node* Set::getHead() const
{
	return head;//returns head
}

int Set::size() const
{
	return m_size;//returns size
}

bool Set::insert(const ItemType& value)
{
	bool chk = false;

	chk = (!contains(value));//to check if the value is already in the Set

	if (chk == true)//if not...
	{
		Node* newguy = new Node;//New node is created
		newguy->m_data = value;//an assigned the value 'value'

		head->m_prev->m_next = newguy;//the pointer from the previous element's m_next pointer variable is assigned the address to the new element

		newguy->m_prev = head->m_prev;//the new node's m_prev pointer variable is assigned the address of the hed's original m_prev pointer variable

		head->m_prev = newguy;//and the head's new m_prev now points to the new node

		newguy->m_next = head;//and the new node's m_next pointer variable noe points to head

		m_size++;//m_size is incremented
	}
	
	return chk;
}

bool Set::erase(const ItemType & value)
{
	bool chk = contains(value);
	
	if (chk == true)//the code doesn't proceed if the user asks to delete an element that isn't in the LL
	{
		Node* p;
		p = head->m_next;
		while (p->m_data != value)
		{
			p = p->m_next;//A pointer is run throughout the LL to point to the element we have to delete
		}

		p->m_prev->m_next = p->m_next;//The m_next variable of the element before the condemned element is reassigned to the element after the condemned element

		p->m_next->m_prev = p->m_prev;//And the m_prev variable of the element after the condemned element is reassigned to the element before the condemned element 

		//the forward and reverse links now skip over the element we want to delete

		delete p;//now we can safely delete the required Node
		m_size--;//the size is decremented
	}
	return chk;
}

void Set::dump() const
{
	Node* p;
	p = head->m_next;
	while (p != head)
	{
		cout << p->m_data << endl;
		p = p->m_next;
	}
	cout << "********************" << endl;
}

bool Set::empty() const
{
	bool chk = true;
	if (m_size > 0)
	{
		chk = false;//returns false if the Set is not empty, true otherwise
	}
	return chk;
}

/////////////////////////NON MEMBER FUNCTIONS///////////////////////////////////////////

void unite(const Set & s1, const Set & s2, Set & result)
{
	result = s1;//All elements from the first set are assigned to result
	Node* p = s2.getHead();//a pointer pointing to the head of the second Set is created

	p = p->m_next;//assigned to the first element of the second Set

	while (p != s2.getHead())//this block loops till we reach the head of s2 again
	{
		if (result.contains(p->m_data)==false)//if the element from s2 is NOT there in s1...
		{
			result.insert(p->m_data);//it is inserted into result
		}
		p = p->m_next;
	}

	///void functions don't return anything
}

void subtract(const Set & s1, const Set & s2, Set & result)
{
	result = s1;
	Node* p = s2.getHead();//Like the unite function, result is equated to s1, and a pointer the head of s2 is created

	p = p->m_next;//assigned to the first element of s2

	while (p != s2.getHead())//the loop runs till p has traversed all elements of s2
	{
		if (result.contains(p->m_data))//if that particular element exists in s1...
		{
			result.erase(p->m_data);//it is erased from it
		}
		p = p->m_next;
	}
	///again, this function doesn't return a value
}

