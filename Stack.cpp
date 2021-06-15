#include <iostream>
//#include "Stack"
#include "Node.h"
#include "Stack.h"
ostream& operator<<(ostream& os, const Stack& s)
{
	os << s.Top->name;
	return os;
}
void Stack::push(int data,string name)
{
	
	//from the lecture slides
	Node* tmp = new Node(data,name);

	tmp->next = Top;

	Top = tmp;
	this->ElementCount++;
}
bool Stack::pop()
{
	//from the lecture slides
	Node* tmp = Top;

	if(Top == nullptr)return false;

	Top = Top->next;

	delete tmp;

	this->ElementCount--;
	return true;
}
bool Stack::peek(int &data)
{

	if(Top == nullptr)return false;

	data = Top->data;
	return true;
}

Stack::~Stack()
{
	//from lecture slides
	Node* tmp = Top;
	
	while(tmp != nullptr)
	{
		Top = Top->next;
		try
		{

		delete tmp;//read access exception here on the second consecutive remove of a stack and also in queue and i dont know why
		}
		catch(const std::exception&)
		{
			cout << "Could not delete stack";
		}
		tmp = Top;
	}
}


