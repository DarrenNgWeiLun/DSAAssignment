#pragma once
#include <iostream>
#include <string>
using namespace std;
/** ADT queue - Pointer-based implementation. */
typedef int ItemType;
// Team Member : Haiqel (s10172619H) and Darren (s10175470)
// All functions are equally important
class Queue
{
private:
	/** A node on the queue. */
	struct Node
	{
		/** A data item on the queue. */
		ItemType item;
		/** Pointer to next node.     */
		Node    *next;
	}; // end Node

	   /** Pointer to front node in the queue. */
	Node *frontNode;
	/** Pointer to back node in the queue. */
	Node *backNode;

public:

	/** Default constructor. */
	Queue();

	/** Destructor. */
	~Queue();

	// Queue operations:
	bool isEmpty();
	bool enqueue(ItemType item);
	bool dequeue();
	bool dequeue(ItemType& item);
	void getFront(ItemType& item);
	void displayItems();
	int size();
	bool dequeuePosition(ItemType& item, ItemType position);
	int getNItem(int n);
}; // end Queue
   // End of header file.
