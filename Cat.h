#ifndef CAT_H
#define CAT_H

#include "Animal.h"

using namespace std;

class Cat : public Animal
{
public:
	Cat(string name, int age, bool isOutdoor);
	string toString();

private:
	bool isOutdoor;
};

#endif