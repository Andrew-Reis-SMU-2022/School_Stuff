#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	virtual string toString();
	
protected:
	string type;
	string name;
	int age;
	int dailyFee;
};

#endif