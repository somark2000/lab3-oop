#include <iostream>
#include "btree.h"
using namespace std;

Node::Node()
{
	left = NULL;
	right = NULL;
}

Node::~Node()
{
	delete left;
	delete right;
}