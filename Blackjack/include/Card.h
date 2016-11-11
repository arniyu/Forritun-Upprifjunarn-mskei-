#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>

using namespace std;

class Card
{
    public:
        Card();
        ~Card();

        int evaluateHand(vector<Card> cards);
        bool checkIfBusted(int totalScore);
        void setCardValue(char myCard);

    private:
        char card;
        int value;
        int evaluateAces(vector<Card> cards, int totalScore);

        //For debugging!
        void printHand(vector<Card> cards);


};

#endif // CARD_H
