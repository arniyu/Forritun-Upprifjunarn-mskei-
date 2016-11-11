#include <iostream>
#include "Card.h"

using namespace std;

const int MAXSIZE = 5;
const int MINSIZE = 2;

bool evaluateHandSize(int handSize)
{
    return handSize <= MAXSIZE && handSize >= MINSIZE;
}

void prompt()
{
    cout << "Scoring a blackjack hand" << endl;
    cout << "------------------------" << endl;
    cout << "Number of cards (min 2, max 5): " << endl;
}

int main()
{
    char again = 'y';

    while(again == 'y' || again == 'Y')
    {
        char cardInput;
        int handSize;
        vector<Card> cards;
        prompt();
        cin >> handSize;

        if(!evaluateHandSize(handSize))
        {
            cout << "Invalid number of cards!" << endl;
        }
        else
        {
            for(int i = 1; i <= handSize; i++)
            {
                cout << "Card no. " << i << ": ";
                cin >> cardInput;
                Card card;
                card.setCardValue(cardInput);
                cards.push_back(card);
            }
            Card card;
            int score = card.evaluateHand(cards);
            cout << "The score of the hand is: " << score << endl;

            if(card.checkIfBusted(score))
            {
                cout << "Busted!" << endl;
            }
        }
        cout << "Score again?" << endl;
        cin >> again;
    }
    return 0;
}
