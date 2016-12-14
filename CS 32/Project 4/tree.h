
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<math.h>
#include<queue>
#include<cassert>
using namespace std;




class BST
{
private:
	struct Node
	{
		Node* left;
		Node* right;
		string substr;
		int offset;
		Node()
		{
			this->left = nullptr;
			this->right = nullptr;
		}
		Node(string sr, int off) :left(nullptr), right(nullptr), substr(sr), offset(off)
		{}

	};
	Node* root;
	void add2(Node* root, string str, int off)
	{
		if (str < root->substr)
		{
			if (root->left == nullptr)
				root->left = new Node(str, off);
			else
				add2(root->left, str, off);
		}
		else if(str>root->substr)
		{
			if (root->right == nullptr)
				root->right = new Node(str, off);
			else
				add2(root->right, str, off);
		}
		else
		{
			;
		}
	}
	void deleteAll(Node* head)
	{
		if (head->left != nullptr)
			deleteAll(head->left);
		if (head->right != nullptr)
			deleteAll(head->right);

		delete head;

	}

	int find2(Node *root, string data)
	{
		if (root->substr == data)
		{
			return root->offset;
		}
		if (root->substr > data)
		{
			if (root->left != nullptr)
				return find2(root->left, data);
			else
				return -1;
		}
		if (root->substr < data)
		{
			if (root->right != nullptr)
				return find2(root->right, data);
			else
				return -1;
		}
		else
			return -1;

	}

public:

	BST()
	{}

	~BST()
	{
		deleteAll(this->root);
	}

	int find(string sub)
	{
		return find2(root, sub);
	}
	void setOff(Node* root, int newOff) { root->offset = newOff; }

	void add(string str, int off)
	{
		if (root == nullptr)
			root = new Node(str, off);
		else
			add2(root, str, off);
	}
};