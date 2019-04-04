#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList list;

	list.insertNode(10);
	list.appendNode(40);
	list.insertNode(30);
	list.insertNode(25);
	list.deleteNode(30);
	list.displayList();

	 
	return 0;
}
