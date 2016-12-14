#ifndef SET_H
#define SET_H

#include<iostream>
#include<string>

using namespace std;
typedef int ItemType;

struct Node
{
	ItemType m_data;
	Node* m_next;
	Node* m_prev;
};

class Set
{
public:


	Set();
	Set(const Set& other);
	Set& operator=(const Set& rhs);
	~Set();
	void dump() const;
	bool empty()const;
	int size() const;
	bool insert(const ItemType& value);
	bool erase(const ItemType& value);
	bool contains(const ItemType& value) const;
	bool get(int pos, ItemType& value) const;
	void swap(Set& other);
	Node* getHead()const;
	
private:
	
	Node* dummy;
	int m_size;
	Node* head;
	

};

void unite(const Set& s1, const Set& s2, Set& result);
void subtract(const Set& s1, const Set& s2, Set& result);


#endif 
