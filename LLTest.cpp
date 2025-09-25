#include "LL.h"
#include "LL.cpp"
#include <iostream>
using namespace std;

void printList(const LL<string>&);

int main()
{
	LL<string> list;


	list.headInsert("mi");
	list.tailInsert("fa");
	list.tailInsert("sol");
	list.tailInsert("ti");

	list.headInsert("re");
	list.headInsert("do");

	printList(list);

	return 0;
}

void printList(const LL<string>& list)
{
	LL<string>::iterator it;

	for (it = list.begin(); it != list.end(); it++)
		cout << *it << endl;

	cout << endl;

	return;
}