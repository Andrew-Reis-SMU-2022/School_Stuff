#include "Node.h"



Node::Node()
{
	this->next = nullptr;
	this->previous = nullptr;
}

Node::Node(Animal data) {
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

Node::Node(Animal data, Node *next, Node *previous) {
	this->data = data;
	this->next = next;
	this->previous = previous;
}
