// DSAAssignment.cpp : Defines the entry point for the console application.
// Team Member : Haiqel (s10172619H) and Darren (s10175470)
// All functions are equally important
// We have a custom validation called try_stoi to check for conversion errors

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Queue.h"
#include <stdlib.h> 
#include <time.h> 
#include "BST.h"
using namespace std;
void printMenu();
void opt1(BST &tree, Queue queue2);
void opt2(BST &tree);
void opt3(BST &tree);
void opt4(BST &tree);
void opt5(BST &tree);
void opt0();
bool try_stoi(int & i, const string & s);
void mainProgram();


void main()
{
	cout << "Welcome to Darren & Haiqel's Binary Search Tree program!";
	cout << " " << endl;
	cout << "This program will display out a tree data structure based on the number you key in into the program!" << endl;
	cout << " " << endl;
	mainProgram();

}


// just to print the menu
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
	cout << "Please enter an option:";
}

// "Option 1: Search for value in tree"
void opt1(BST &tree ,Queue queue2 ) {

	string search;
	int i;
	cout << "Please enter a value to search:"; //check for validation errors
	cin >> search;
	if (try_stoi(i, search) == true){
		int Search = stoi(search);
		tree.searchPath(Search, queue2);
	}
	else { 
		cout << " " << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "Please enter an integer value!" << endl;
		cout << "Please do not enter any symbols, words or others that are not supported!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		opt1(tree, queue2);
	}
}
// Option 2: Add a value to tree
void opt2(BST &tree) {
	string add;
	int i;
	cout << "Please enter a value to insert to tree:"; //check for validation errors
	cin >> add;
	if (try_stoi(i, add) == true){
		int Add = stoi(add);
		tree.insert(Add);
	}
	else {
		cout << " " << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "Please enter an integer value!" << endl;
		cout << "Please do not enter any symbols, words or others that are not supported!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		opt2(tree);
	}
}
// Option 3: Remove a value from tree
void opt3(BST &tree) {
	string remove;
	int i;
	cout << "Please enter a value to remove from tree:";
	cin >> remove;
	if (try_stoi(i, remove) == true) {
		int Remove = stoi(remove);
		tree.remove(Remove);
	}
	else {
		cout << " " << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "Please enter an integer value!" << endl;
		cout << "Please do not enter any symbols, words or others that are not supported!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		opt3(tree);
	}
	
}
// Option 4: Display value in ascending order
void opt4(BST &tree) {
	tree.inorder();
}

//Option 5: Find the Nth Node
void opt5(BST &tree) {
	string nodeNumber;
	int i;
	Queue sampleQueue;
	cout << "Please enter the Nth Node:";
	cin >> nodeNumber;
	if (try_stoi(i, nodeNumber) == true) {
		int NodeNumber = stoi(nodeNumber);
		tree.printLevelOrder(sampleQueue);
		if(sampleQueue.getNItem(NodeNumber) != -1)
			cout << "Value of " << nodeNumber << "th Node is :" << sampleQueue.getNItem(NodeNumber) << endl;
		else
		{
			cout << "No such node" << endl;
		}
	}
	else {
		cout << " " << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "Please enter an integer value!" << endl;
		cout << "Please do not enter any symbols, words or others that are not supported!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		opt5(tree);
	}
}

//Option 0: Close Program
void opt0() {
	cout << " " << endl;
	cout << "Thank you for using the application!" << endl;
	cout << "Hope to see you again! " << endl;
	system("PAUSE");
	exit(0);
}

// check if conversion of string to int is true
bool try_stoi(int & i, const string & s) {
	try {
		size_t pos;
		i = stoi(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

void mainProgram() {
	try { // try-catch for the whole program
		Queue intQueue;
		string search;
		BST tree;
		string option;
		Queue tempoQueue;
		int queueLength;
		int sum = 0;
		int dequeueItem;
		int i; // used for checking of stoi function
		bool functionCondition = true;
		cout << "Please enter an integer from 1 - 1000: ";
		cin >> search;
		if (try_stoi(i, search) == true) {
			int searchInInt = stoi(search);

			// if statement to make sure the user does not enter any crazy number or less than zero.
			if (searchInInt > 1000 || searchInInt <= 0) {
				cout << "The value that you have entered is not supported by the program!" << endl;
				cout << "Please try again" << endl;
				system("PAUSE");
				cout << " " << endl;
				mainProgram();
			}
			// when the number is not crazy and the number is < 1000 ;
			else {
				for (int i = 1; sum < searchInInt; i++)
				{
					sum += i;
					intQueue.enqueue(i);
				}

				queueLength = intQueue.size();
				tempoQueue = intQueue;
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
				while (functionCondition) {
					// print the tree using the printTree() function.
					cout << "************************************************************************************************************" << endl;
					cout << " " << endl;
					cout << "This is the current structure of the tree that has been created" << endl;
					tree.printTree();
					cout << " " << endl;
					cout << "************************************************************************************************************" << endl;
					cout << " " << endl;
					printMenu();

					string option;
					cin >> option;
					if (try_stoi(i, option) == true) {
						int optionInInt = stoi(option);

						// switch is used to do faster look-up
						switch (optionInInt) {
						case(1):
							opt1(tree, tempoQueue);
							break;
						case(2):
							opt2(tree);
							queueLength++;
							break;
						case(3):
							opt3(tree);
							queueLength--;
							break;
						case(4):
							opt4(tree);
							break;
						case(5):
							opt5(tree);
							break;
						case(0):
							opt0();
							break;
						default:
							cout << "Please enter only from [0] to [5]" << endl;
							functionCondition = true;
							system("PAUSE");
							cout << " " << endl;
							break;
						}
					}
					else {
						cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
						cout << " " << endl;
						cout << "Please do not enter characters, symbols or any other values that are not supported!" << endl;
						cout << "Please enter only from [0] - [5]!" << endl;
						system("PAUSE");
						cout << " " << endl;
						cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
					}
				}

			} //ending of 1st else block (checking if the number entered is more than 1000 or less than 0);
		}
		else {
			cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
			cout << " " << endl;
			cout << "Please do not enter characters, symbols or any other values that are not supported!" << endl;
			cout << "Please enter only integers!" << endl;
			cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
			system("PAUSE");
			cout << " " << endl;
			mainProgram();
		}
	}
	catch (int param) { // catch for the whole program
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		mainProgram();
	}
	catch (string param) {
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		mainProgram();
	}
	catch (exception &e) {
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		cout << "There was an error handling your request!" << endl;
		cout << "Please try again!" << endl;
		cout << " ------------------------------------- ERROR -----------------------------------------------------" << endl;
		system("PAUSE");
		cout << " " << endl;
		mainProgram();
	}


}


// ignore
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
