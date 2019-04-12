#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList list;
	list.append(Cat("Daisy", 2, false));
	list.append(Dog("Chad", 10, "Ball"));
	list.append(Rabbit("Bob", 1, 5));
	list.print();
	system("pause");
	return 0;
}
