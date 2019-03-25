#ifndef CARD_H
#define CARD_H

#include "vector.h"

class Card
{
public:
	Card();
	Card(int cardValue, char suit[]);
	void setCardSuit(char suit[]);
	void setCardValue(int cardValue);
	int getCardValue();
	vector<char> getCardId();
private:
	int cardValue;
	vector<char> cardId;
};

#endif