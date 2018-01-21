#pragma once
#include <string>
#include "BinaryNode.h"
#include "Queue.h"
// Team Member : Haiqel (s10172619H) and Darren (s10175470)
// All functions are equally important
class BST
{
private:
	BinaryNode* root;
public:
	BST();
	~BST();
	// search an item in the binary search tree
	BinaryNode* search(ItemType target);
	BinaryNode* search(BinaryNode* t, ItemType target);

	BinaryNode* searchPath(ItemType target,int queueLength);
	BinaryNode* searchPath(BinaryNode* t, ItemType target, int queueLength);
	// add an item to the binary search tree
	void insert(ItemType item);
	void insert(BinaryNode* &t, ItemType item);

	// delete an item from the binary search tree
	void remove(ItemType target);
	void remove(BinaryNode* &t, ItemType item);

	// traverse the binary search tree in inorder
	void inorder();
	void inorder(BinaryNode* t);

	// traverse the binary search tree in preorder
	void preorder(BinaryNode* t);

	// traverse the binary search tree in postorder
	void postorder(BinaryNode* t);

	// compute the height of the binary search tree
	int getHeight();
	int getHeight(BinaryNode* t);

	// count the number of nodes in the binary search tree
	int countNodes();
	int countNodes(BinaryNode* t);

	// check if the binary search tree is empty
	bool isEmpty();
	bool isEmpty(BinaryNode* t);

	// check if the binary search tree is balanced
	bool isBalanced();
	bool isBalanced(BinaryNode* t);

	void printLevelOrder(Queue &q);
	void printLevelOrder(BinaryNode*t, Queue &q);
	void printGivenLevel(BinaryNode*t, int level, Queue &q);

	void printTree();
	void printTree(BinaryNode*t,int space);

	void insertNode(BinaryNode* u);
	void insertNode(BinaryNode* &t, BinaryNode* u);

	
};

