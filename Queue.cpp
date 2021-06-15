#include "Queue.h"
#include <iostream>
ostream& operator<<(ostream& os, const Queue& q)
{
	os << q.first->name;
	
	return os;
}
bool Queue::peek(int& data)
{
	if(first == nullptr)return false;
	data = first->data;
	return true;
}
//from the lecture slides
void Queue::push(int data,string name)
{
	Node* tmp = new Node(data,name);

		if(first == nullptr)
		{
			first = tmp;
		}
		else
		{
			last->next = tmp;
		}
		last = tmp;
		this->ElementCount++;
}
//from the lecture slides
bool Queue::pop()
{
	Node* tmp = first;
	if(first==nullptr){return false;}

	first = first->next;
	if(first == nullptr)  last = nullptr;

	delete tmp;

	this->ElementCount--;
	return true;
}
Queue::~Queue()
{
	Node* tmp = first;
	while(tmp!= nullptr)
	{
		
		first = first->next;
		

		try
		{

			delete tmp;//read access exception i dont know how to handle 
		}
		catch(const std::exception&)
		{
			cout << "Could not delete queue";
		}
			tmp = first;
		

		
	}
		last = nullptr;
}