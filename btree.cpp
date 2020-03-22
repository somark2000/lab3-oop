#include <iostream>
#include <string>
#include <algorithm>
#include "btree.h"
#include "node.h"
using namespace std;


Btree::Btree()
{
	this->root = NULL;
	this->left = NULL;
	this->right = NULL;
}

Btree::Btree(Node* root, Node* left, Node* right)
{
	this->root = root;
	this->left = left;
	this->right = right;
}


Btree::~Btree()
{
	delete this->root;
}

void Btree::insert(int key)
{
	Node* n = new Node;
	Node* parent;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	parent = NULL;
	if (root == NULL)
	{
		root = n;
	}
	else
	{
		Node* current = root;
		while (current != NULL)
		{
			parent = current;
			if (n->key > current->key)
				current = current->right;
			else
				current = current->left;
		}
		if (n->key < parent->key)
			parent->left = n;
		else
			parent->right = n;
	}
}

//This function calls the removal of a node with a specific key value
void Btree::do_remove(int key)
{
	remove(root,key);
}

//This function returns the the node to be put to replace the deleted one
Node* Btree::minValueNode(Node* n)
{
	Node* current = n;
	Node* parent=current;
	while (current->right != NULL)
	{
		parent = current;
		current = current->right;
	}
	parent->right = NULL;
	return current;
}

//This function does the removal of a node with a specific key value
Node* Btree::remove(Node* root, int key)
{
	if (root == NULL) return root;
	if (key < root->key)
		root->left = remove(root->left, key);
	else if (key > root->key)
		root->right = remove(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = remove(root->right, temp->key);
	}
	return root;
}


/* The inorder function:
1. Check if the current node is empty or null.
2. Traverse the left subtree by recursively calling the in-order function.
3. Display the data part of the root (or current node).
4. Traverse the right subtree by recursively calling the in-order function */

void Btree::print_inorder()
{
	inorder(root);
}


void Btree::inorder(Node* n)
{
	if (n != nullptr)
	{
		if (n->left!=NULL) inorder(n->left);
		cout << " " << n->key << " ";
		if (n->right != NULL) inorder(n->right);
	}
	else
		return;
}

/* The preorder function:
1. Check if the current node is empty or null.
2. Display the data part of the root (or current node).
3. Traverse the left subtree by recursively calling the pre-order function.
4. Traverse the right subtree by recursively calling the pre-order function. */

void Btree::print_preorder()
{
	preorder(root);
}

void Btree::preorder(Node* n)
{
	if (n != nullptr)
	{
		cout << " " << n->key << " ";
		if (n->left) preorder(n->left);
		if (n->right) preorder(n->right);
	}
	else
		return;
}

/* The postorder function:
1. Check if the current node is empty or null.
2. Traverse the left subtree by recursively calling the post-order function.
3. Traverse the right subtree by recursively calling the post-order function.
4. Display the data part of the root (or current node). */

void Btree::print_postorder()
{
	postorder(root);
}

void Btree::postorder(Node* n)
{
	if (n != nullptr)
	{
		if (n->left) postorder(n->left);
		if (n->right) postorder(n->right);
		cout << " " << n->key << " ";
	}
	else
		return;
}

//This function counts, how many nodes are in the tree.
int Btree::countNodes(Node* n)
{
	int count = 1;
	if (n == nullptr)
		return 0;
	else
	{
		count += countNodes(n->left);
		count += countNodes(n->right);
	}
	return count;
}

int Btree::countNodes()
{
	return countNodes(root);
}

//This function counts, how many edges are in the tree.
int Btree::countEdges(Node* n)
{
	if (n == nullptr)
		return 0;
	else
		return countNodes() - 1;
}

int Btree::countEdges()
{
	return countEdges(root);
}

//This function shows the height of a tree.
int Btree::height(Node* n)
{
	if (n == nullptr)
	{
		return -1;
	}
	int left = height(n->left);
	int right = height(n->right);
	return (1 + std::max(left, right));
}

int Btree::height()
{
	return height(root);
}