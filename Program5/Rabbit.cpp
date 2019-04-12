#include "Rabbit.h"



Rabbit::Rabbit(string name, int age, int numberOfCarrots)
{
	this->name = name;
	this->age = age;
	this->numberOfCarrots = numberOfCarrots;
	this->dailyFee = 15;
	this->type = "Rabbit";
}


string Rabbit::toString() {
	string s = Animal::toString();
	s += "Number of Carrots / Day: " + to_string(this->numberOfCarrots) + '\n';
	return s;
}

