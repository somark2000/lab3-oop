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

void Btree::do_remove(int key)
{
	remove(key, root);
}

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

void Btree::remove(int key,Node* n)
{
	if (root == NULL) //arborele e gol
	{
		cout << "The tree is empty\n";
		return;
	}
	else
	{   //cautam nodul
		Node* current = root;
		Node* parent = NULL;
		while (current != NULL and key != current->key)
		{
			parent = current;
			if (key > current->key)
				current = current->right;
			else
				current = current->left;
		}
		if (key == current->key) //daca l-am gasit
		{
			if (current->left == NULL and current->right == NULL)//nu are copii
			{
				if (key < parent->key)
					parent->left = NULL;
				else
					parent->right = NULL;
				delete current;
			}
			else if(current->left == NULL or current->right == NULL)// are un copil
			{
				if (current->left == NULL)
					parent->left = current->right;
				else
					parent->right = current->left;
				delete current;
			}
			else
			{
				Node* temp = minValueNode(current->right);
				current->key = temp->key;
				delete temp;
			}
		}
		else //nu l-am, gasit
		{
			cout << "There is no such element to be removed\n";
			return;
		}
	}

	/*
	//cautam elementul de sters
	if (key < root->key)
		remove(key,root->left); 
	else if (key > root->key)
		remove(key,root->right);
	else
	{
		// daca are cel mult un fiu 
		if (root->left == NULL)
		{
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node 
		root->key = temp->key;

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->key);
	}*/

	
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