#include <iostream>
#include <cstring>
#include "vector.h" //my own personal library!
#include "Card.h"

using namespace std;

int main() {
	char hearts[] = "hearts";
	Card card1(14, hearts);
	cout << "Card Value = " << card1.getCardValue() << '\n';
	cout << "Card Id = " << card1.getCardId().getList() << '\n';
	system("pause");
	return 0;
}
