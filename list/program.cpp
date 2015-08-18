#include <iostream>
#include "list.h"
using namespace std;

void main()
{
	//Sample Code
	List mylist;
	mylist.pushToHead('k');
	mylist.pushToHead('e');
	mylist.pushToHead('n');

	cout << "Original: ";
	mylist.print();
	cout << endl;

	cout << "Push tail: ";
	mylist.pushToTail('y');

	mylist.print();
	cout << endl;

	mylist.popTail();
	cout << "Pop tail: ";
	mylist.print();
	cout << endl;

	mylist.reverse();
	cout << "After reverse: ";
	mylist.print();
	cout << endl;

	mylist.search('e');
	cout << endl;

	system("pause");

	//TO DO! Write a program that tests your list library - the code should take characters, push them onto a list, 
	//- then reverse the list to see if it is a palindrome!
	
}