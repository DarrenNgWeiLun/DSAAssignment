#include "stdafx.h"
#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}
bool Queue::isEmpty()
{
	return frontNode == NULL;
}
bool Queue::enqueue(ItemType item)
{
	Node *newNode = new Node();
	newNode->item = item;
	newNode->next = NULL;
	if (isEmpty())
	{
		frontNode = newNode;
	}
	else
	{
		backNode->next = newNode;
	}
	backNode = newNode;
	return true;
}
bool Queue::dequeue()
{
	bool success = !isEmpty();
	if (success)
	{
		Node *temp;

		if (frontNode == backNode)
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
		{
			temp = frontNode;
			frontNode = frontNode->next;
		}

		return true;
	}
	else
	{
		return false;
	}
}
bool Queue::dequeue(ItemType& item)
{
	bool success = !isEmpty();
	if (success)
	{
		Node *temp;
		temp = frontNode;
		item = frontNode->item;
		if (frontNode == backNode)
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
		{
			frontNode = frontNode->next;
			temp->next = NULL;
		}
		return true;
	}
	else
	{
		return false;
	}


}
void Queue::getFront(ItemType& item)
{
	if (!isEmpty())
	{
		item = frontNode->item;
	}
}
void Queue::displayItems()
{
	ItemType item;
	Node *temp;
	temp = frontNode;
	if (!isEmpty())
	{
			while (temp != backNode)
			{
				item = temp->item;
				cout << item << ",";
				temp = temp->next;
			}
			if (temp == backNode)
			{
				item = temp->item;
				cout << item << "." << endl;
			}
		
		
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
int Queue::size()
{
	int size=0;
	Node *temp;
	temp = frontNode;
	if (!isEmpty())
	{
		while (temp != backNode)
		{
			temp = temp->next;
			size++;
		}
		if (temp == backNode)
		{
			size++;
			
		}
	}
	return size;
}
bool Queue::dequeuePosition(ItemType& item, ItemType position)
{
	bool success = !isEmpty();
	Node *previous;
	Node *temp;
	temp = frontNode;
	previous = temp;
	if (position == 1)
	{
		frontNode = frontNode->next;
	}
	for (int i = 1; i < position; i++)
	{
		previous = temp;
		temp = temp->next;
	}
	item = temp->item;
	if (temp == backNode)
	{
		backNode = previous;
	}
	previous->next = temp->next;
	return success;
}
int Queue::getNItem(int n)
{

	Node*temp = frontNode;
	int result;
	
	for (int i = 1; i < n; i++)
	{
		temp = temp->next;
	}
	result = temp->item;
	return result;
}