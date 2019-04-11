#include <iostream>
#include <fstream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList list;
	int temp;

	ifstream intFile;
	intFile.open("IntegerList.txt");

	// Task 3 Code to read from file and add to the list
	while (intFile >> temp)
	{
		list.insertNode(temp);
	}	

	list.displayList();
	intFile.close();

	// Task 1 Code to add to the list
	/*list.insertNode(10);
	list.appendNode(40);
	list.insertNode(30);
	list.insertNode(25);
	list.deleteNode(30);
	list.displayList();*/

	 
	return 0;
}
