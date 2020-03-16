#pragma once
#include "node.h"
using namespace std;
#include <algorithm>

class Btree
{
	friend class Node;
private:
	Node* root;//radacina arborelui element fals
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
	void do_remove(int key);
	void remove(int key,Node* n);

	//searhes for the node with the smallest value
	Node* minValueNode(Node* n);

	//inorder
	void print_inorder();
	void inorder(Node* n);

	//preorder
	void print_preorder();
	void preorder(Node* n);

	//postorder
	void print_postorder();
	void postorder(Node* n);

	//counts the nodes
	int countNodes(Node* n);
	int countNodes();

	//counts the edges
	int countEdges(Node* n);
	int countEdges();

	//returns the height of a tree
	int height(Node* n);
	int height();
};