#include "linkedlist.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

list::list() {
	head = NULL;
}

list::list(string file) {
	head = NULL;

	fstream inData;
	inData.open(file.c_str(), ios::in);
	if (!inData.fail()) {
		string line;
		while( getline(inData, line) ) {  insert(line, -1); }
	}
	inData.close();
}

void list::print()
//Display the list to the computer screen
{
Node* ptr = head;

if(ptr == NULL)
{
cout << "The list is empty!" <<endl;
return;
}

else{
	int i = 1;
	while(ptr != NULL)
	{ cout << i << "> " << ptr->info << endl;
	  i++;
          ptr = ptr->next; 
	}
}
}
void list::append(string value)
//Function used to add new node entries to the list with the parameter of a stringof what to put in the new node. 
{
 Node* ptr = head;
 Node* newNode = new Node();
 newNode->info = value;
 newNode->next = NULL;
 if (ptr == NULL)
{
 head = newNode;
}
else{

 while(ptr->next != NULL)
	{
	 ptr = ptr->next; 
	}
 ptr->next = newNode;
}
}
void list::insert(string line, int linenum)
//Function takes the string to be inputted into the line and the line number of where the string should be inputed then inserts it into the list at the line number specified.
{
  Node* ptr = head; 
  int location = 0;
  Node* prev = NULL;
  
  if(head == NULL)//Case 1: empty list
{
  if (linenum != -1)
{
  for(int i = 1; i < linenum; i++)
  {
   append("");
  } 
   append(line);
}
  else
{
  Node* newnode = new Node();
  newnode->info = line;
  head = newnode;
}
}
else{ //Case 2: list isn't empty
if (linenum != -1)
{
location = 1;
  while( location < linenum && ptr != NULL)
{
	location++;
	//cout <<location;
	prev = ptr;
	ptr = ptr->next;       
}
if(ptr == NULL) //Case where user wants to add line below current line number
{
	for(location; location <linenum; location++)
{
	append("");
}
append(line);
}
else //Case where user adds line anywhere else
{
	Node* newNode = new Node();
	prev->next = newNode;
	newNode->next = ptr;
	newNode->info = line;
}
}
else //linenum == -1
{
Node* ptr = head;
while (ptr->next != NULL) {
ptr = ptr->next;
}
Node* newnode = new Node();

newnode->info = line;
ptr->next = newnode;
}
}
}

void list::remove(int linenum) 
//Function that takes in line number and deletes element at that line number
{

   Node  *delPtr = head;
   Node *prevPtr = NULL;
   // If the list is empty, then do nothing;
   if (delPtr == NULL)
 {
         return;
 }
   //Treat the first Node as a special case... head needs to be updated

   if (linenum == 1)
   {
        head = head->next;
   }
   else
   {
        //Look for the Node to be deleted
	int curr = 1;
        while (delPtr != NULL && curr != linenum) 
        {
            prevPtr = delPtr;
            delPtr = delPtr->next;
	    curr++;
        }
	// line to remove is neither first nor last line
	if (curr == linenum && delPtr != NULL) {
		prevPtr->next = delPtr->next;
		delete delPtr;
	}
	// line to remove is last line
	else if (curr == linenum && delPtr == NULL) {
		prevPtr->next = NULL;
		delete delPtr;
	}
	// line to remove doesn't exist
	else {
		cout << "Sorry. Unable to delete a nonexistent line." << endl;
	}

	
        }
   }

void list::save(string file)
//This function allows the user to write their new output to their input file, overwriting it.
{
fstream outData;
outData.open(file.c_str(),ios::out); //open the specific file for writing
if(!outData.fail()) //If file opens
{
	Node* curr = head;
	while(curr != NULL) //write lines into the file
{
	outData << curr->info << endl;
	curr = curr->next;
}
}
outData.close();
return;
}

void display()
//Displays a help menu to let the user know proper syntax for the program.
{
cout << "-----------------------------------------------------------------" << endl;
cout << "Welcome to my text editor!" << endl;
cout << "	To insert text at the end of the file, type 'I' followed by a space then the text." << endl;
cout << "	To insert text at a certain line number, type 'I' followed by a space and the line number" << endl;
cout << "	To delete a line, type 'D' followed by a space and the line number" <<endl;
cout << " 	To print all the lines, type 'L' and press enter" <<endl;
cout << "	To save the current content, type 'S' and press enter" <<endl;
cout << "	To display this help menu, type 'H' and press enter" <<endl;
cout << "	To copy a line, type 'C' space then a line number" << endl;
cout << "	To paste a line, type 'P' followed by a space and the line number" << endl;
cout << "	To quit, 'Q' and press enter" <<endl;
cout << "-----------------------------------------------------------------" << endl;
}

string list::copy(int linenum)
{
Node* ptr = head;
string clipboard = "";

int counter = 1;
while(ptr->next != NULL && counter < linenum)
        {
        ptr = ptr->next;
	counter++;
        }
if (counter == linenum)//If the linenum is valid
{
 clipboard = ptr->info;
 cout << "Copied!"<<endl;
}

else
{
 cout << "Nothing to copy" <<endl;
}

return clipboard;
}











