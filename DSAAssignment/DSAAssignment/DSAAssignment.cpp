// DSAAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Queue.h"
#include <stdlib.h> 
#include <time.h> 
#include "BST.h"
using namespace std;
void printMenu();

int main()
{
	Queue intQueue;
	string search;
	BST tree;
	string option;
	int queueLength;
	int sum = 0;
	int dequeueItem;
	cout << "Please enter a integer:";
	getline(cin,search);
	int searchInInt = stoi(search);
	for (int i=1; sum < searchInInt; i++)
	{
		sum +=i;
		intQueue.enqueue(i);
	}
	queueLength = intQueue.size();
	cout << "Binary Tree would contain:";
	intQueue.displayItems();
	cout << endl;
	cout << endl;
	cout << endl;
	while (!intQueue.isEmpty())
	{
		int size = intQueue.size();
		srand(time(NULL));
		int random = rand() % size+ 1;
		intQueue.dequeuePosition(dequeueItem, random);
		tree.insert(dequeueItem);
	}
	tree.printTree();
		printMenu();
		getline(cin, option);
		int optionInInt = stoi(option);
		if (optionInInt == 1)
		{
			int search;
			cout << "Please enter a value to search:";
			cin >> search;
			tree.searchPath(search,queueLength);
		}
		else if (optionInInt == 2)
		{
			int add;
			cout << "Please enter a value to insert to tree:";
			cin >> add;
			tree.insert(add);
		}
		else if (optionInInt == 3)
		{
			int remove;
			cout << "Please enter a value to remove from tree:";
			cin >> remove;
			tree.remove(remove);

		}
		else if (optionInInt == 4)
			tree.inorder();
		else if (optionInInt == 5)
		{
			int nodeNumber;
			Queue sampleQueue;
			cout << "Please enter the Nth Node:" << endl;
			cin >> nodeNumber;
			tree.printLevelOrder(sampleQueue);
			
			
			cout << "Value of " << nodeNumber << "th Node is :" << sampleQueue.getNItem(nodeNumber) << endl;
		}
		else if (optionInInt == 0)
			exit(0);

		else
			cout << "Please enter a valid option" << endl;
	system("PAUSE");
    return 0;
}



void printMenu()
{
	cout << "-------------------Menu-------------------" << endl;
	cout << "Option 1: Search for value in tree" << endl;
	cout << "Option 2: Add a value to tree" << endl;
	cout << "Option 3: Remove a value from tree" << endl;
	cout << "Option 4: Display value in ascending order" << endl;
	cout << "Option 5: Find the Nth Node" << endl;
	cout << "Option 0: Close Program" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Please enter a option:";
}

