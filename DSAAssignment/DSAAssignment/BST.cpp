#include "stdafx.h"
#include "BST.h"
#include <iostream>
#include <string>

#include <iomanip>  

#define COUNT 10
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
	if (t == NULL) // if the node does not exists
		return 0; // no nodes <3
	else
	{
		return countNodes(t->left) + countNodes(t->right) + 1;
		// recursion is used here.
		// very accurate;
	}
}
int BST::getHeight()
{
	return getHeight(root);
}
int BST::getHeight(BinaryNode* t) // get the level of the tree.
{
	// need this for the queue function so that we can traverse the tree through each level / height
	if (t == NULL)
		return 0;
	else
	{
		int left = getHeight(t->left);
		int right = getHeight(t->right);

		return 1 + MAX(left, right); //1 is technically the root before recursion
	}
}
bool BST::isBalanced()
{
	return isBalanced(root);
}
bool BST::isBalanced(BinaryNode *t)
{
	// change the isBlanced code from week 8 is easier to understand
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
BinaryNode* BST::searchPath(ItemType target,int queueLength)
{
	return searchPath(root, target,queueLength);
}
BinaryNode* BST::searchPath(BinaryNode* t, ItemType target,int queueLength)
{
	if (queueLength < target)
	{
		cout << "Item Not Found" << endl;
		return NULL;
	}
	else
	{
	if (t == NULL)
	{
		// item not found
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
					return searchPath(t->left, target,queueLength);

				}
				else         // search in right subtree
				{
					cout << "R" << endl;
					return searchPath(t->right, target,queueLength);

				}
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
	if (search(item) != NULL)
	{
		cout << "Item already exist in tree!" << endl;
	}
	if (search(item) == NULL)
	{
		if (t == NULL)
		{
			BinaryNode *newNode = new BinaryNode;
			newNode->item = item;
			newNode->left = NULL;
			newNode->right = NULL;
			t = newNode;
			cout << "Item has been added!"<<endl;
		}
		else
			if (item < t->item)
				insert(t->left, item);  // insert in left subtree
			else
				insert(t->right, item); // insert in right subtree
	}


}
void BST::insertNode(BinaryNode* u)
{
	return insertNode(root,u);
}
void BST::insertNode(BinaryNode* &t,BinaryNode* u)
{
	t->right = u;
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
		//if value is root.
		if (current->item == root->item)
		{
			if (current->left == NULL && current->right !=NULL)
			{
				current->right = root;
				cout << "Item has been deleted" << endl;
			}
			else if (current->right == NULL && current->left != NULL)
			{
				current->left = root;
				cout << "Item has been deleted" << endl;
			}
			else if(current->right != NULL && current->left != NULL)
			{
				current->left == root;
				insertNode(current->right);
				cout << "Item has been deleted" << endl;
			}


		}
		// -----------------------  case 1 : node is a leaf ------------------------
		if (current->left == NULL && current->right == NULL)
		{
			if (current == t)	// node to be deleted is a root
				t = NULL;
			else
				if (isLeftChild)
				{
					parent->left = NULL;
					cout << "Item has been deleted" << endl;
				}

				else
				{
					parent->right = NULL;
					cout << "Item has been deleted" << endl;
				}
		}
		else
			// -----------------------  case 2 : node has only 1 child  ----------------
			if (current->left == NULL)
			{
				if (isLeftChild)
				{
					parent->left = current->right;
					cout << "Item has been deleted" << endl;
				}

				else
				{
					parent->right = current->right;
					cout << "Item has been deleted" << endl;
				}
			}
			else
				if (current->right == NULL)
				{
					if (isLeftChild)
					{
						parent->left = current->left;
					}
					else
					{
						parent->right = current->left;;
					}
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
	else
	{
		cout << "Item could not be found in tree" << endl;
	}
}
void BST::printLevelOrder(Queue &q)
{
	return printLevelOrder(root, q);
}
void BST::printLevelOrder(BinaryNode*t, Queue &q)
{
	int h = getHeight(t);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(t, i, q);
}

/* Print nodes at a given level */
void BST::printGivenLevel(BinaryNode* t, int level, Queue &q)
{
	if (t == NULL)
		return;
	if (level == 1)
	{
		q.enqueue(t->item);
		
	}
	else if (level > 1)
	{
		printGivenLevel(t->left, level - 1, q);
		printGivenLevel(t->right, level - 1, q);
	}
}

void BST::printTree()
{
	return printTree(root,0);
}
void BST::printTree(BinaryNode *t, int space)
{
	if (t == NULL)
		return;
	space += COUNT;

	printTree(t->right, space);

	printf("\n");

	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", t->item);

	printTree(t->left, space);
}



