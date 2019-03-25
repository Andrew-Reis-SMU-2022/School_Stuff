#include "Card.h"
#include <cstring>


vector<char> get_card_name(int cardValue) {
	if (cardValue == 2) {
		char name[] = "two";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 3) {
		char name[] = "three";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 4) {
		char name[] = "four";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 5) {
		char name[] = "five";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 6) {
		char name[] = "six";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 7) {
		char name[] = "seven";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 8) {
		char name[] = "eight";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 9) {
		char name[] = "nine";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 10) {
		char name[] = "ten";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 11) {
		char name[] = "jack";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 12) {
		char name[] = "queen";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 13) {
		char name[] = "king";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else if (cardValue == 14) {
		char name[] = "ace";
		vector<char> vName(name, strlen(name));
		return vName;
	}
	else {
		char name[] = "ERROR";
		vector<char> vName(name, strlen(name));
		return vName;
	}
}

Card::Card()
{
	this->cardValue = 0;
}

Card::Card(int cardValue, char suit[]) {
	this->cardValue = cardValue;
	vector<char> cardName = get_card_name(this->cardValue);
	this->cardId.append(get_card_name(this->cardValue));
	char formatting[] = " of ";
	this->cardId.append(formatting, strlen(formatting));
	this->cardId.append(suit, strlen(suit));
	this->cardId.append('\0');
}

void Card::setCardSuit(char suit[]) {
	Card card(this->cardValue, suit);
	this->cardId = card.cardId;
}

void Card::setCardValue(int cardValue) {
	this->cardValue = cardValue;
	char *newCardName = get_card_name(cardValue);
	this->cardId.replace(0, this->cardId.find(' '), newCardName, strlen(newCardName));
}

int Card::getCardValue() {
	return this->cardValue;
}

vector<char> Card::getCardId() {
	return this->cardId;
}



