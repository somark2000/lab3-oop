#pragma once
#include "node.h"
using namespace std;

class Btree
{
	friend class Node;
private:
	Node* root;//radacina arborelui
public:
	//constructor
	Btree();

	//destuctor
	~Btree();

	//searches a node in the three
	bool search(int key);

	//adds a new node to the tree
	bool insert(int key,Node tree);

	//deletes a node
	bool dellete(int key, Node tree);

	//
	string inorder(Node n);

	//
	string preorder(Node n);

	//
	string postorder(Node n);

	//counts the nodes
	int countNodes(Node n);

	//counts the edges
	int countEdges(Node n);

	//returns the height of ??(a node in)?? the binary tree
	int height(Node n);
};
