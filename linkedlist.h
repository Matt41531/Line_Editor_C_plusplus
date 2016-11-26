#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

void display();

class Node 
{
public:
Node(){next = NULL;}; //Constructor
Node* next;
std::string info; 
};

class list
{
public:
list();
list(std::string file);
void save(std::string file);
void insert(std::string, int linenum);
void remove(int);
void print();
void append(std::string);
std::string copy(int linenum);

Node* head;
};

#endif


