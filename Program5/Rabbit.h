#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"
class Rabbit :
	public Animal
{
public:
	Rabbit(string name, int age, int numberOfCarrots);
	string toString();

protected:
	int numberOfCarrots;
};

#endif