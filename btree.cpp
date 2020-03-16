#include <iostream>
#include <string>
#include "btree.h"
#include "node.h"
using namespace std;


Btree::Btree()
{
	row = 0;
	root = NULL;
}

Btree::~Btree()
{
	delete root;
}


bool Btree::insert(int key, Node tree)
{
	return false;
}

bool Btree::dellete(int key, Node tree)
{
	return false;
}



int Btree::height(Node n)
{
	return n.lvl;
	//return row;
}

