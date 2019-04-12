#include "Cat.h"



Cat::Cat(string name, int age, bool isOutdoor)
{
	this->name = name;
	this->age = age;
	this->isOutdoor = isOutdoor;
	this->dailyFee = 25;
	this->type = "Cat";
}

string Cat::toString() {
	string s = Animal::toString();
	s += "Indoor/Outdoor: ";
	if (this->isOutdoor) {
		s += "Outdoor\n";
	}
	else {
		s += "Indoor\n";
	}
	return s;
}

