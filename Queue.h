#pragma once
#include "Node.h"
//from lecture slides
class Queue
{
	Node* first;
	Node* last;
	int ElementCount;
	string name;
public:
#pragma region Constructors/Destructors
	Queue():first(nullptr),last(nullptr),ElementCount(0){}
	Queue(string name):name(name),first(nullptr),last(nullptr),ElementCount(0){}
	~Queue();
#pragma endregion
#pragma region FunctionPrototypes
	void push(int data,string name);
	bool pop();
	bool peek(int& data);
	friend ostream& operator<<(ostream& os, const Queue& q);
#pragma endregion
#pragma region getters/setters
	string getName(){return name;}
	int getEleCount()
	{
		try
		{
			return ElementCount;
		}
		catch(...)
		{

		};
	}
#pragma endregion
};


