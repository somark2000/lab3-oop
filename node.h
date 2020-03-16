#pragma once
using namespace std;

class Btree;
class Node
{
private:
	int key;//key value
	Node* left;//son from left
	Node* right;//son from right
	int lvl;//current height of the tree
	friend class Btree;

public:
	Node();
	~Node();
};
