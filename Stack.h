#pragma once
#include "Node.h"
//from lecture slides
 class Stack
{
private:
	Node* Top{};
	string name{};
	int ElementCount;
public:
	
	#pragma region Constructors/Destructors
	
		Stack() :Top(nullptr),name(name),ElementCount(0){}
		
		Stack(string name) :name(name),ElementCount(0){}
	
		~Stack();
		
	#pragma endregion
	#pragma region FunctionsPrototypes
		//From the lecture slides 
		void push(int data,string name);
		bool pop();
		bool peek(int& data);
		friend ostream& operator<<(ostream& os, const Stack& s);
		
	#pragma endregion
	#pragma region getters/setters
		string getName(){return name;}
		
		int getEleCount(){return ElementCount;}
	#pragma endregion
	
		





};

