#include <iostream>
#include <string>
#include "btree.h"
#include "node.h"
using namespace std;


Btree::Btree()
{
	this->root = NULL;
}

Btree::~Btree()
{
	delete this->root;
}


bool Btree::search(int key)
{

}

bool Btree::insert(int key, Node tree)
{
	//daca este primul element de adaugat, el va fi radacina
	if (this->root = NULL)
	{
		Node* n=new Node();
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		n->lvl = 1;
		this->root = n;
		return true;
	}
	else if(search(tree.key))
	{

	}
	return false;
}

bool Btree::dellete(int key, Node tree)
{
	return false;
}

string Btree::inorder(Node n)
{

}

string Btree::preorder(Node n)
{

}

string Btree::postorder(Node n)
{

}

int Btree::countNodes(Node n)
{

}

int Btree::countEdges(Node n)
{

}

int Btree::height(Node n)
{
	return n.lvl;
	//return row;
}

