#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"

class LinkedList
{
public:
	LinkedList();
	void append(Animal data);
	void prepend(Animal data);
	Animal pop();
	Animal pop(int index);
	int getSize();
	void print();
	void reversePrint();
	~LinkedList();
private:
	int size;
	Node *head;
	Node *tail;
};

#endif