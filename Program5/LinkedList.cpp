#include "LinkedList.h"
#include <exception>
#include <iostream>



LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

void LinkedList::append(Animal data) {
	if (this->size == 0) {
		Node *newNode;
		newNode = new Node(data);
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		Node *newNode;
		newNode = new Node(data, nullptr, this->tail);
		this->tail->next = newNode;
		this->tail = newNode;
	}
	this->size++;
}

void LinkedList::prepend(Animal data) {
	if (this->size == 0) {
		Node *newNode;
		newNode = new Node(data);
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		Node *newNode;
		newNode = new Node(data, this->head, nullptr);
		this->head->previous = newNode;
		this->head = newNode;
	}
	this->size++;
}

Animal LinkedList::pop() {
	if (this->size > 0) {
		Node *lastNode = this->tail;
		this->tail = this->tail->previous;
		if (this->tail != nullptr) {
			this->tail->next = nullptr;
		}
		else {
			this->head = nullptr;
		}
		Animal data = lastNode->data;
		delete lastNode;
		this->size--;
		return data;
	}
	else {
		std::cout << "Index out of bounds Error\n";
		std::terminate();
	}
}

Animal LinkedList::pop(int index) { //UNIT TEST!!!
	if (index < 0) {
		index = this->size - index;
	}
	if (index < 0 || index >= this->size) {
		std::cout << "Index out of bounds Error\n";
		std::terminate();
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	Animal data = temp->data;

	if (temp->next == nullptr) {
		temp->previous->next = nullptr;
		this->tail = temp->previous;
	}
	else {
		temp->previous->next = temp->next;
	}

	if (temp->previous == nullptr) {
		temp->next->previous = nullptr;
		this->head = temp->next;
	}
	else {
		temp->next->previous = temp->previous;
	}
	
	delete temp;

	return data;
}

void LinkedList::print() {
	Node *temp;
	temp = this->head;
	std::cout << "[";
	while (temp != nullptr) {
		if (temp != this->tail) {
			std::cout << temp->data.toString() << "\n, ";
		}
		else {
			std::cout << temp->data.toString() << "]\n";
		}
		temp = temp->next;
	}
}

void LinkedList::reversePrint() {
	Node *temp;
	temp = this->tail;
	std::cout << "[";
	while (temp != nullptr) {
		if (temp != this->head) {
			std::cout << temp->data.toString() << ", ";
		}
		else {
			std::cout << temp->data.toString() << "]\n";
		}
		temp = temp->previous;
	}
}

int LinkedList::getSize() {
	return this->size;
}

LinkedList::~LinkedList()
{
	Node *currNode;
	currNode = this->head;
	while (currNode != nullptr) {
		Node *nextNode;
		nextNode = currNode->next;
		this->head = nextNode;
		delete currNode;
		this->size--;
		currNode = nextNode;
	}
}
