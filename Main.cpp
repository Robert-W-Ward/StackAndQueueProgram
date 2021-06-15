/*
Student Name: Robert Ward
Student NetID: rww189
Compiler Used: Visual Studio
Program Description:
reads in commands from the console or from a text file to execute funtions 
that push or pop on stacks and queues and find,remove and display stacks and queues 
*/
#pragma once;
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;



//input to hold the entire input line
string input;
//token to hold each individual work from the input line after its chopped with getline
string cmd;
//string to hold the command keyword
string TOKEN;
//string stream to hold every line from a give text file
stringstream textFileLines;
//file stream to read and manipulate files
fstream InFile;
//textline to hold the text line from the console
string  textline;
//ticketNum to how the incoming number for the
int  ticketNum;



//bool to control while loop
bool isRunning = true;

//Vector of Stacks initialized on the heap
vector<Stack>* Stacks = new vector<Stack>();
///Vector of Queus initialized on the heap
vector<Queue>* Queues = new vector<Queue>();





//display function to display Stacks and queues and the number of elements
void display()
{
	//check if either vector is empty
	if(!Stacks->empty() || !Queues->empty())
	{
		//loops through stack vector
		for(unsigned int i = 0; i < Stacks->size(); i++)
		{
			//prints out stack name and number of elements
			cout << "\tstack "<<Stacks->at(i).getName()<<" containing "<<Stacks->at(i).getEleCount()<<" elements"<<endl;
		}
		//loops through queue vector
		for(unsigned int j = 0; j < Queues->size(); j++)
		{
			//prints out queue name and number of elements
			cout << "\tqueue " << Queues->at(j).getName() << " containing " << Queues->at(j).getEleCount() << " elements" << endl;
		}
	}
	else
	{
		//displays if no containers exist
		cout << "No containers found"<<endl;
	}	
}
//checks incoming name against the names of existing stacks or queues and if it finds a match returns true
bool isNameDupe(string nameTOcheck)
{
	//checks if both vectors are empty
	if(Stacks->empty()&&Queues->empty())
	{
		
		return false;
	}
	else
	{
		//if not empty loop through them until Stack or queue with respective name is found and return true
			for(unsigned int i = 0; i < Stacks->size(); i++)
			{
				if(nameTOcheck == Stacks->at(i).getName())
				{
					
					return true;

				}
				else
				{
					continue;
				}
			}

		
		
			for(unsigned int j = 0; j < Queues->size(); j++)
			{
				if(nameTOcheck == Queues->at(j).getName())
				{
					return true;
				}
				else
				{
					continue;
				}
			}
		
return false;
	}
}
//finds the stack of the name and returns the address 
Stack* find(string name,int n)
{

	for(unsigned int i = 0; i < Stacks->size(); i++)
	{
		if(name == Stacks->at(i).getName())
		{

			return &Stacks->at(i);

		}
		else
		{
			continue;
		}
	}
	
	return 0;
}
//finds the queue of the name and returns the address
Queue* find(string name)
{
	for(unsigned int j = 0; j < Queues->size(); j++)
	{
		if(name == Queues->at(j).getName())
		{
			return &Queues->at(j);
		}
		else
		{
			continue;
		}
	}
	return 0;
}
//removes the stack or queue with the given name
void remove(string token)
{
	//loops through vector until name of given stack is found and deletes it 
	for(auto itr = Stacks->begin(); itr != Stacks->end(); itr)
	{
		//index
		int index = distance(Stacks->begin(),itr);
		//checks if stack at current index value's name is equal to the give name
		if(Stacks->at(index).getName() == token)
		{
			//erases the stack 
			itr = Stacks->erase(itr);
			
			   
		}
		else
		{
			break;
		}
	}
	for(auto itr2 = Queues->begin(); itr2 != Queues->end(); itr2)
	{
		int index = distance(Queues->begin(), itr2);
		if(Queues->at(index).getName() == token)
		{
			itr2=Queues->erase(itr2);
			
			
		}
		else
		{
			break;
		}

	}
}
//load the selected file
string loadFile(string filename)
{
	//attempts to open file
	InFile.open(filename);
	//checks if the file with the name was opened
	if(InFile.is_open())
	{
		cout << "File opened successfully!" << endl;
		//loop to get every line of the file
		while(getline(InFile, textline, '\n'))
		{
			textFileLines << textline<<" ";			
		}
		InFile.close();
	}
	else
	{
		cerr << "File could not be opened or located" << endl;
	}
	//returns string containing contents of the textFileLines Stream
	return textFileLines.str();
}
//parse the commands wether from console or text file
void parse(string ss){
	
	
	stringstream ss2(ss);

		//loop to go through each word of command
		while(getline(ss2,input,' ')){
			//if not blank
			if(input != "")
			{
				
				
			}
			//if first word equals exit
			if(input == "exit")
			{
				//exit the program
				cout << "GOODBYE!";
				isRunning = false;
			}
			//if first word equals display
			else if(input == "display")
			{
				//call display 
				display();
			}
			//if first word equals create
			else if(input == "create")
			{
				//get next word
				getline(ss2, TOKEN, ' ');
				//if next word equals stack
				if(TOKEN == "stack")
				{
					//get what they want to call the stack 
					getline(ss2, TOKEN,' ');
					//check if the name they want is available
					if(isNameDupe(TOKEN))//returns true if they name they entered is an already exsisting name ie is a dupe
					{
						
						cout << "Container with name already exsists" << endl;
					}
					else
					{
						//creates the stack at the end of the vector 
						Stacks->emplace_back(TOKEN);
						cout << "Successfully created the stack " <<TOKEN<< endl;
					}
					//clears the stringstream for next loop iteration
					ss.clear();
				}
				//if first word equals queue
				else if(TOKEN == "queue")
				{
					//gets the name of the queue
					getline(ss2, TOKEN, ' ');
					//checks if the name is a dupe
					if(isNameDupe(TOKEN))
					{
						//if it is inform the user
						cout << "Container with name already exsists" << endl;
					}
					else
					{
						//if it isnt create the queue with that name
						Queues->emplace_back(TOKEN);
						//inform the user of success
						cout << "Successfully created the queue " << TOKEN<<endl;
					}
					//clear the string stream for next loop iteration
					ss.clear();
				}
			}
			//check if command is push 
			else if(input == "push")
			{
				//gets the account name
				getline(ss2, TOKEN, ' ');
				//stores the account name into a temporary string variable
				string acntName = TOKEN;
				//gets the ticket number
				getline(ss2, TOKEN, ' ');
				//stores the ticket number into a temp string variable
				string ticketstring = TOKEN;
				//try to convert ticket number from string type to int type
				try
				{
					ticketNum = stoi(ticketstring);
				}

				catch(const std::exception&)
				{
					cout << "Failed to convert ticket number"<<endl;
				}
				//checks if format of command is still in check 
				getline(ss2, TOKEN, ' ');
				//if the next word after ticket num fits the format
				if(TOKEN == "into")
				{
					//gets the name of stack or queue the user wants to push into
					getline(ss2, TOKEN, ' ');
					//checks is Stack or queue with that nam exists
					if(isNameDupe(TOKEN))
					{
						//trys to find the stack of the given name
						if(find(TOKEN, 1))
						{
							//push into the stack
							find(TOKEN, 1)->push(ticketNum, acntName);
							//inform the user of success
							cout << "Pushed user " << acntName << " @ " << "ticket " << ticketNum << " into container " << find(TOKEN, 1)->getName()<<endl;
						}
						else
						{
							//push into a queue of that name otherwise
							find(TOKEN)->push(ticketNum, acntName);
							//inform user of success
							cout << "Pushed user " << acntName << " @ " << "ticket " << ticketNum << " into container " << find(TOKEN)->getName()<<endl;
						}
					}
				}

			}
			//if command equals pop
			else if(input == "pop")
			{
			//get the name of container user wants to pop
				getline(ss2, TOKEN, ' ');
				//checks if container with name exists
				if(isNameDupe(TOKEN))
				{
					//checks if  Stack with name has any elements
					if(find(TOKEN,1)&&find(TOKEN, 1)->getEleCount() > 0)
					{
						//pops off the top element of the stack
						find(TOKEN, 1)->pop();
						//informs user of success
						cout << "Successfully pop'd from the container " << TOKEN << endl;
					}
					//checks if Queue with name has any elements
					else if(find(TOKEN) && find(TOKEN)->getEleCount() > 0)
					{
						//pops off the front element of the queue
						find(TOKEN)->pop();
						//informs user of success
						cout << " Successfully pop'd from the container " << TOKEN << endl;
					}
					else
					{
						//informs user of failure
						cout << "Cant pop from an empty container" << endl;
					}
				}

			}
			//if command equals find
			else if(input == "find")
			{
			//gets the name of what container to find
				getline(ss2, TOKEN, ' ');
				//checks if container with that name exists
				if(isNameDupe(TOKEN))
				{
					if(find(TOKEN, 1))
					{
						//prints info about the container
						cout << "The containter " << TOKEN << " contains " << find(TOKEN, 1)->getEleCount() << " elements and is a stack" << endl;
					}
					else if(find(TOKEN))
					{
						cout << "The contairner " << TOKEN << " contains " << find(TOKEN)->getEleCount() << " elements and is a queue" << endl;
					}

				}
				else
				{
					//informs user of failure
					cout << "The container " << TOKEN << " doesn't exist" << endl;
				}
			}
			//if command equals remove
			else if(input == "remove")
			{
			//get which container to remove
				getline(ss2, TOKEN, ' ');
			//check if container exists
				if(isNameDupe(TOKEN))
				{
					if(find(TOKEN, 1))
					{				
						//removes stack with that name and informs user of success
							remove(TOKEN);
							cout << TOKEN << " removed" << endl;
					}
					else if(find(TOKEN))
					{
						//removes queue with that name and informs user of success
						remove(TOKEN);
						cout << TOKEN << " removed"<<endl;
					}
				}
			}
			//if command is load 
			else if(input == "load")
			{
			//get the name of the file to load
				getline(ss2, TOKEN, ' ');
			//parse the lines from the file 
				parse(loadFile(TOKEN));
			}
			else
			{
			// if something is entered that cant be understood
			cout << "Please enter a valid command"<<endl;
				return;
			}
		}
		
}
//main 
int main()
{
	
	while(isRunning)
	{
		//prompt
		cout << ">>";
		//gets the whole input line
		getline(cin, input);
		stringstream ss;
		//puts the whole input line into ss to be separated
		ss << input;
		//parses line word by word and executes accordingly
		parse(ss.str());

	}
}