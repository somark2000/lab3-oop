#pragma once
#include "node.h"
#include <algorithm>

class Btree
{
	friend class Node;
private:
	Node* root;//radacina arborelui
	Node* left;
	Node* right;
public:
	//constructor
	Btree();
	Btree(Node* root, Node* left, Node* right);

	//destuctor
	~Btree();

	//adds a new node to the tree
	void insert(int key);
	
	//deletes a node
	bool remove(int key);

	//inorder
	void print_inorder();
	void inorder(Node *n);

	//preorder
	void print_preorder();
	void preorder(Node* n);

	//postorder
	void print_postorder();
	void postorder(Node *n);

	//counts the nodes
	int countNodes(Node *n);
	int countNodes();

	//counts the edges
	int countEdges(Node *n);
	int countEdges();

	//returns the height of a tree
	int height(Node *n);
	int height();
};
