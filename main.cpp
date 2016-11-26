//Program 1
//CS216
//Matthew Rife
//Section 4
//This program is a simple line editor using linked lists where the user can input commands to insert new lines, delete lines, show the lines, rewrite the lines to the txt file, or get help. The program requires a txt file as an arguement. 


#include <string>
#include <iostream>
#include <fstream>
#include "linkedlist.h"
using namespace std;

int main(int argc, char *argv[])
{
        if (argc != 2)
        {
        cout << "Invalid parameters";
        return 1;
        }

list lines = list(argv[1]);

display();
string clipboard = "";
string input = "";
cout << "> ";
cin >> input;

	while(input != "Q"&&input != "q")
{
	if (input == "I"|| input =="i")
{
		int newinput = 0;
		
		cin >> newinput;

		

		if(cin.fail()) //Case when user types I then their string
		{		

		cin.clear();
		string strinput;
		getline(cin, strinput);
		cin.ignore(256,'\n');
		lines.insert(strinput, -1);
		}
		else if ( newinput < 1)
		{
		 cout << "Invalid input" <<endl;
		}
		
		else //Case when user types I and linenumber
		{
		
		
		cout << newinput << "> ";
		string strinput;
		//cout << "Please enter text:";
		cin.ignore(256, '\n');
		getline(cin, strinput);
		lines.insert(strinput, newinput);
		}
}
	else if( input == "D"|| input == "d")
{
		int newinput = 0;
		cin >> newinput;
		if (cin.fail()) //if user enters character that isn't int
		{
		cin.clear();
		cout << "No valid line number" << endl;;
		}
		else 
		{
		int linenumber = 0;
		Node* ptr = lines.head;
		//check if linenumber exists
			while(ptr != NULL)
			{
	        	 linenumber++;
         		 ptr = ptr->next;
			}
			if (newinput <= linenumber)
			{
			lines.remove(newinput);
			}
			else
			{
	 		cout << "line doesn't exist" <<endl;
			}
		}
}	
	else if (input == "L"|| input == "l")

{
		print:
		lines.print();
}
	else if (input == "S"|| input =="s")
{
		lines.save(argv[1]);
		cout << "Save successful!" <<endl;
}
	else if (input == "H"||input == "h")
{
		display();
}
	else if (input == "C"|| input == "c")
	{
		//get input from the C linenum
		//run copy function using linenum
		//cout copied!
		
		int newinput = 0;
                cin >> newinput;
                if (cin.fail()) //if user enters character that isn't int
                {
                cin.clear();
                cout << "No valid line number" << endl;;
                }
		else
		{
		clipboard = lines.copy(newinput);
		}

	}
	else if (input == "P"||input == "p")
	{	
		Node* ptr = lines.head;
		int newinput = 0;
		int linenumber = 0;
                cin >> newinput;
                if (cin.fail()) //if user enters character that isn't int
                {
                cin.clear();
                cout << "No valid line number" << endl;;
                }
		while(ptr != NULL)
                        {
                         linenumber++;
                         ptr = ptr->next;
                        }
		if (newinput <= linenumber)
		{
        	 lines.insert(clipboard,newinput);
		 cout << "Pasted!" << endl;
		}
		

	}
	else
{
		cout << "Invalid input!" <<endl;
}
//cout << "> ";
cin >> input;
}
//end of while
if (input == "Q"||input == "q")
{
                string saveYN = "";
                cout << "Would you like to save? Type 'Y' for yes or 'N' for no." << endl;
                cin >> saveYN;
		while (saveYN != "Y"  && saveYN != "N")
		{
			
			cout << "Invalid input!" <<endl;
			cout << "Would you like to save? Type 'Y' for yes or 'N' for no." << endl;
			cin >> saveYN;
		}
                if (saveYN == "Y")
		{
                        lines.save(argv[1]);
			cout << "Saved!" <<endl;
                        return 0;
		}
		else if(saveYN =="N")
		{			
			cout << "Thanks for using my program!" <<endl;
			return 0;
		}
			
}//for if Q
}//For main

