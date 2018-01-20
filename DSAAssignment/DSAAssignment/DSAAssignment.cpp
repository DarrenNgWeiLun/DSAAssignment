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
void opt1(BST &tree, int queueLength);
void opt2(BST &tree);

void main()
{
	Queue intQueue;
	string search;
	BST tree;
	string option;
	int queueLength;
	int sum = 0;
	int dequeueItem;

	try { // try-catch for the whole program
		cout << "Please enter a integer:";
		getline(cin, search);
		int searchInInt = stoi(search);

		// if statement to make sure the user does not enter any crazy number or less than zero.
		if (searchInInt > 1000 || searchInInt < 0) {
			cout << "The value that you have entered is not supported by the program!" << endl;
			cout << " Please try again" << endl;
			main();
		}
		 // when the number is not crazy and the number is < 1000 ;
		else {
			for (int i = 1; sum < searchInInt; i++)
			{
				sum += i;
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
				int random = rand() % size + 1;
				intQueue.dequeuePosition(dequeueItem, random);
				tree.insert(dequeueItem);
			}
			bool functionCondition = true;
			while (functionCondition) {
				// print the tree using the printTree() function.
				tree.printTree();
				printMenu();
				
				string option;
				cin >> option;
				int optionInInt = stoi(option);

				switch (optionInInt) {
				case(1):
					opt1(tree, queueLength);
					break;
				case(2):
					opt2(tree);
					break;
				default : 
					cout << "Dont be an idiot" << endl;
					functionCondition = false;
					cout << "Re-test the program again" << endl;
					break;
				}
				 

					/*if (optionInInt == 1)
					{
						int search;
						cout << "Please enter a value to search:";
						cin >> search;
						tree.searchPath(search, queueLength);
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
					else if (optionInInt == 0) {
						exit(0);
						break;
					}


					else
						cout << "Please enter a valid option" << endl;
					system("PAUSE");
					*/
			}
			
		} //ending of 1st else block (checking if the number entered is more than 1000 or less than 0);
	}
	catch (int param) { // catch for the whole program
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		main();
	}
	catch (string param) {
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		main();
	}
	catch (exception &e) {
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		main();
	}
	
    
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

void opt1(BST &tree ,int queueLength ) {
	try {
		int search;
		cout << "Please enter a value to search:";
		cin >> search;
		tree.searchPath(search, queueLength);
		
	}
	catch (exception &e) {
		cout << "There was an error!" << endl;
		cout << "Please try again!" << endl;
		
	}
}

void opt2(BST &tree) {
	int add;
	cout << "Please enter a value to insert to tree:";
	cin >> add;
	tree.insert(add);
}

