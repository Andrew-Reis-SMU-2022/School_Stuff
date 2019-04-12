#include "Dog.h"



Dog::Dog(string name, int age, string favoriteToy)
{
	this->name = name;
	this->age = age;
	this->favoriteToy = favoriteToy;
	this->dailyFee = 50;
	this->type = "Dog";
}

string Dog::toString() {
	string s = Animal::toString();
	s += "Favorite Toy: " + this->favoriteToy + '\n';
	return s;
}
