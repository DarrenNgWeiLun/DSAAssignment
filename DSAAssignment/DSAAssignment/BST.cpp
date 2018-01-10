#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <string>
#define MAX(a, b) ((a) > (b) ? ( a) : (b))
using namespace std;
BST::BST()
{
}


BST::~BST()
{
}
int BST::countNodes()
{
	return countNodes(root);
}
int BST::countNodes(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else
	{
		return countNodes(t->left) + countNodes(t->right) + 1;
	}
}
int BST::getHeight()
{
	return getHeight(root);
}
int BST::getHeight(BinaryNode* t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left = getHeight(t->left);
		int right = getHeight(t->right);

		return 1 + MAX(left, right);
	}
}
bool BST::isBalanced()
{
	return isBalanced(root);
}
bool BST::isBalanced(BinaryNode *t)
{
	if (t != NULL)
	{
		if (getHeight(t) < 4)
		{
			int leftHeight = getHeight(t->left);
			int rightHeight = getHeight(t->right);

			if (abs(leftHeight - rightHeight) <= 1)
				return true;
			else
				return false;
		}
		else
			return (isBalanced(t->left) && isBalanced(t->right));
	}
	else
		return true;
}
bool BST::isEmpty()
{
	return isEmpty(root);
}
bool BST::isEmpty(BinaryNode* t)
{
	return (t == NULL);
}
BinaryNode* BST::searchPath(ItemType target)
{
	return search(root, target);
}
BinaryNode* BST::searchPath(BinaryNode* t, ItemType target)
{
	if (t == NULL)
	{
		cout << "Item not found" << endl;// item not found
		return NULL;
	}
	else
	{
		if (root->item == target)
		{
			cout << "Root" << endl;
			return t;
		}
		else
		{
			if (t->item == target)// item found
			{
				return t;
			}
			else
				if (target < t->item)  // search in left subtree
				{
					cout << "L" << endl;
					return search(t->left, target);
					
				}
				else         // search in right subtree
				{
					cout << "R" << endl;
					return search(t->right, target);
					
				}
		}
	}

}
BinaryNode* BST::search(ItemType target)
{
	return search(root, target);
}

BinaryNode* BST::search(BinaryNode* t, ItemType target)
{
	if (t == NULL)	         // item not found
		return NULL;
	else
	{
		if (t->item == target) // item found
			return t;
		else
			if (target < t->item)  // search in left subtree
				return search(t->left, target);
			else                   // search in right subtree
				return search(t->right, target);
	}

}
void BST::insert(ItemType item)
{
	insert(root, item);
}
void BST::insert(BinaryNode* &t, ItemType item)
{
	if (search(item) == NULL)
	{
		if (t == NULL)
		{
			BinaryNode *newNode = new BinaryNode;
			newNode->item = item;
			newNode->left = NULL;
			newNode->right = NULL;
			t = newNode;
		}
		else
			if (item < t->item)
				insert(t->left, item);  // insert in left subtree
			else
				insert(t->right, item); // insert in right subtree
	}
	else
	{
		cout << "Item could not be added because it already exists!" << endl;
	}
}
void BST::inorder()
{
	return inorder(root);
}
void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);         // traverse left subtree
		cout << t->item << endl;  // process the item
		inorder(t->right);        // traverse right subtree
	}
}
void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->item << endl;  // process the item
		inorder(t->left);         // traverse left subtree
		inorder(t->right);        // traverse right subtree
	}
}
void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);         // traverse left subtree
		inorder(t->right);        // traverse right subtree
		cout << t->item << endl;  // process the item
	}

}

void BST::remove(ItemType target)
{
	remove(root, target);
}

void BST::remove(BinaryNode* &t, ItemType target)
{
	// search for the node to be deleted

	BinaryNode* current = t;
	BinaryNode* parent = NULL;
	bool isLeftChild = false;
	bool found = false;
	while ((!found) && (current != NULL))
	{
		if (target == current->item)
		{
			found = true;
		}
		else
		{
			parent = current;
			if (target < current->item)
			{
				current = current->left;	// go to left subtree
				isLeftChild = true;
			}
			else
			{
				current = current->right;	// go to right subtree
				isLeftChild = false;
			}
		}
	}

	if (found)
	{
		// -----------------------  case 1 : node is a leaf ------------------------
		if (current->left == NULL && current->right == NULL)
		{
			if (current == t)	// node to be deleted is a root
				t = NULL;
			else
				if (isLeftChild)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		else
			// -----------------------  case 2 : node has only 1 child  ----------------
			if (current->left == NULL)
			{
				if (isLeftChild)
					parent->left = current->right;
				else
					parent->right = current->right;;
			}
			else
				if (current->right == NULL)
				{
					if (isLeftChild)
						parent->left = current->left;
					else
						parent->right = current->left;;
				}
				else
					// -----------------------  case 3 : node has 2 children  ------------------
				{
					// find the successor ( rightmost child in the node’s left subtree)
					BinaryNode* successor = current->left;
					while (successor->right != NULL)
						successor = successor->right;
					// replace the node’s item with that of the successor
					int n = successor->item;
					// delete the successor (either case 1 or case 2)
					remove(t, n);
					// replace the node’s item with that of the successor
					current->item = n;
				}
	}
}
void BST::printLevelOrder()
{
	return printLevelOrder(root);
}
void BST::printLevelOrder(BinaryNode*t)
{
	int h = getHeight(t);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(t, i);
}

/* Print nodes at a given level */
void BST::printGivenLevel(BinaryNode* t, int level)
{
	if (t == NULL)
		return;
	if (level == 1)
		printf("%d ", t->item);
	else if (level > 1)
	{
		printGivenLevel(t->left, level - 1);
		printGivenLevel(t->right, level - 1);
	}
}
