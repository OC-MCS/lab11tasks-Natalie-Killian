#include <iostream>
#include <fstream>
#include "NumberList.h"
using namespace std;

int main()
{
	// Task 4 Code 
	NumberList listA, listB;
	listA.appendNode(10);
	listA.appendNode(20);
	listB.appendNode(15);
	listB.appendNode(40);
	cout << "list A before assign: " << endl;
	listA.displayList();
	cout << "list B before assign: " << endl;
	listB.displayList();
	listA = listB;
	listB.appendNode(50);
	cout << "list A after assign: " << endl;
	listA.displayList();
	cout << "list B after assign: " << endl;
	listB.displayList();

	// Task 5 Code to test tail pointer
		// Appending to empty list
	cout << "Append to an empty list: " << endl;
	NumberList listC;
	listC.appendNode(12);
	listC.displayList();
		// Appending to a pre-existing list
	cout << "Append to pre-existing list (list B): " << endl;
	listB.appendNode(60);
	listB.displayList();
		// Inserting a new node at the end of a list
	cout << "Insert a new node at the end of list B: " << endl;
	listB.insertNode(100);
	listB.displayList();
		// Delete the final node
	cout << "Deleting the final node of list B: " << endl;
	listB.deleteNode(100);
	listB.displayList();
		// Assigning one list to another
	cout << "Assigning one list to another: (ListA = ListB)" << endl;
	cout << "list A before assign: " << endl;
	listA.displayList();
	// assign
	listA = listB;
	cout << "list A after assign: " << endl;
	listA.displayList();


	// Task 3 Code to read from file and add to the list
	/*NumberList list;
	int temp;

	ifstream intFile;
	intFile.open("IntegerList.txt");

	while (intFile >> temp)
	{
		list.insertNode(temp);
	}	

	list.displayList();
	intFile.close();*/

	// Task 1 Code to add to the list
	/*list.insertNode(10);
	list.appendNode(40);
	list.insertNode(30);
	list.insertNode(25);
	list.deleteNode(30);
	list.displayList();*/

	 
	return 0;
}
