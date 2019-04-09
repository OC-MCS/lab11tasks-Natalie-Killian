#include <iostream>
#include <fstream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList list;

	ifstream intFile;
	intFile.open("Integ;erList.txt");

	for (int i = 0; i < 5; i++)
	{
		while (intFile >> list.insertNode(i))
		{

		}
	}
	

	list.insertNode(10);
	list.appendNode(40);
	list.insertNode(30);
	list.insertNode(25);
	list.deleteNode(30);
	list.displayList();

	 
	return 0;
}
