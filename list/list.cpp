#include <iostream>
#include "list.h"
using namespace std;

List::~List() {
	for(Node *p; !isEmpty(); ) {
		p=head->next;
		delete head;
		head = p;
	}
}

void List::pushToHead(char el)
{
	head = new Node(el, head);
	if(tail==0)
	{
		tail = head;
	}
}
void List::pushToTail(char el)	//DONE
{
	//TO DO!

	if (head == NULL) //if list is empty
	{
		tail = head = new Node(el);
	}
	else
		{
			tail->next = new Node(el);
			tail = tail->next;	//update tail pointer
		}
}
char List::popHead()
{
	char el = head->data;
	Node *tmp = head;
	if(head == tail)
	{
		head = tail = 0;
	}
	else
	{
		head = head->next;
	}
	delete tmp;
	return el;
}

char List::popTail()	//DONE
{
	// TO DO!
	char el = tail->data;
	Node *tmp;

	if (head == tail) 
	{   
		delete head;
		head = tail = 0;
	}
		else 
		{                
			//Find before-tail node.
			for (
				tmp = head;				//point to head
				tmp->next != tail;		//until next node isn't tail
				tmp = tmp->next			//move temp to next node
				);						//now temp point at tail (hope so).

			delete tail;
			tail = tmp;      //before-tail node become tail.
			tail->next = 0;
		}
	return NULL;
}

bool List::search(char el)
{
	// TO DO! (Function to return True or False depending if a character is in the list.

	Node* temp = head;

	while (temp != NULL) {		//traverse through list
		//found target
		if (temp->data == el)
		{
			cout << "Found the letter: " << el;
			return temp;
		}
		//move to next node
		temp = temp->next;
	}

	cout << el << "is not in the list.";
	return NULL;
}

void List::reverse()	//DONE
{
	// TO DO! (Function is to reverse the order of elements in the list.

	Node *tempCur = head, *rest = NULL, *tempNext = NULL;
	
	if (head == NULL)	//If list is empty.
	{return;}
	
	tail = head;		//Swap between head and tail node to reverse.
	rest = head->next;	//Take out head ndoe

	while (rest != NULL)
	{ 
		tempNext = rest;			//Take out the next node
		rest = rest->next;		//Update poiter of temp node
		tempNext->next = tempCur;		//Add the taken out node to the new list 
		tempCur = tempNext;			//Update temp node
	}
	head = tempCur;
	tail->next = NULL;


}
void List::print()
{
	if(head  == tail)
	{
		cout << head->data;
	}
	else
	{
		Node *tmp = head;
		while(tmp!=tail)
		{
			cout << tmp->data;
			tmp = tmp->next;
		}
		cout << tmp->data;
	}
}