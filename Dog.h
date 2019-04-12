#ifndef DOG_H
#define DOG_H
#include "Animal.h"
class Dog :
	public Animal
{
public:
	Dog(string name, int age, string favoriteToy);
	string toString();

private:
	string favoriteToy;
};

#endif