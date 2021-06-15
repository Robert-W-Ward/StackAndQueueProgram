#pragma once
#include <string>
using namespace std;

//From the lecture slides
struct Node
{
	int data;
	string name;
	Node* next;
	


	Node():data(0), next(nullptr){}
	Node(int data):data(data),next(nullptr){}
	Node(int data,string name):data(data),name(name),next(nullptr){}
	Node(int data, Node* next ):data(data),next(next){}
	Node(int data, Node* next , string name):data(data),next(next),name(name){}
	
	
	//except for this part
	void setNextNode(Node cur,Node* next){}
	void setNodeData(Node cur, int data){}
	
	
};

