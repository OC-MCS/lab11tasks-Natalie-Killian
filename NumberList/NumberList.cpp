// Implementation file for the NumberList class
#include <iostream>  // For cout
#include "NumberList.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void NumberList::appendNode(int num)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to end of list.
		nodePtr = tail;

		// Find the last node in the list.
			// don't need this with tail pointer
		/*while (nodePtr->next)
			nodePtr = nodePtr->next;*/

		// Insert newNode as the last node.
		nodePtr->next = newNode;
		tail = newNode;
		/*if (tail == nullptr)
		{
			nodePtr = head;
			while (nodePtr->next)
			{
				nodePtr = nodePtr->next;
			}

			tail = nodePtr;
		}
		tail->next = newNode;*/
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void NumberList::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void NumberList::insertNode(int num)
{
	ListNode *newNode;					// A new node
	ListNode *nodePtr;					// To traverse the list
	ListNode *previousNode = nullptr;	// The previous node

										// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void NumberList::deleteNode(int num)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode = nullptr;  // To point to the previous node

									   // If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (tail->value == num)
		{
			tail = previousNode;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

NumberList::~NumberList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

						 // Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

// copy constructor
NumberList::NumberList(const NumberList& other)
{
	ListNode* listptr;

	listptr = other.head;
	head = nullptr;

	while (listptr)
	{
		appendNode(listptr->value);
		listptr = listptr->next;
	}
}

void NumberList::operator= (const NumberList& list)
{
	ListNode* tempNode;
	ListNode* deleteNode;
	ListNode* listptr;

	listptr = list.head;

	deleteNode = this->head;


	while (deleteNode != nullptr)
	{
		tempNode = deleteNode->next;
		delete deleteNode;
		deleteNode = tempNode;
	}

	head = nullptr;

	while (listptr)
	{
		appendNode(listptr->value);
		listptr = listptr->next;
	}

	tail = listptr;
}



