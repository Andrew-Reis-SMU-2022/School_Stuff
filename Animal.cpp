#include "Animal.h"



Animal::Animal()
{

}

string Animal::toString() {
	string s = "Animal: " + this->type + '\n';
	s += "Name: " + this->name + '\n';
	s += "Age: " + to_string(this->age) + '\n';
	s += "Fee: " + to_string(this->dailyFee) + '\n';
	return s;
}
