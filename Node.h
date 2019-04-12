#ifndef NODE_H
#define NODE_H

#include "Animal.h"

class Node
{
public:
	Node();
	Node(Animal data);
	Node(Animal data, Node *next, Node *previous);
	Animal data;
	Node *next;
	Node *previous;
};

#endif