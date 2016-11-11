#include "Card.h"

Card::Card()
{
    //ctor
}


Card::~Card()
{
    //dtor
}

void Card::setCardValue(char myCard)
{
    if(isdigit(myCard))
    {
        card = myCard;
        value = (char)myCard - 48;
    }
    else if(myCard == 'k' || myCard == 'q' || myCard == 'j' || myCard == 't')
    {
        card = myCard;
        value = 10;
    }
    else
    {
        //We have a ace.
        card = 'a';
        value = 11;
    }
}

int Card::evaluateAces(vector<Card> cards, int totalScore)
{
    for(int i = 0; i < cards.size(); i++)
    {
        if(cards.at(i).card == 'a')
        {
            cards.at(i).value = 1;
            totalScore -= 10;

            if(!checkIfBusted(totalScore))
            {
                return totalScore;
            }
        }
    }
    return totalScore;
}

bool Card::checkIfBusted(int total)
{
    return total > 21;
}


int Card::evaluateHand(vector<Card> cards)
{
    //printHand(cards);
    int totalScore = 0;
    for(int i = 0; i < cards.size(); i++)
    {
        totalScore += cards.at(i).value;
    }

    if(!checkIfBusted(totalScore))
    {
        return totalScore;
    }
    return evaluateAces(cards, totalScore);
}

void Card::printHand(vector<Card> cards)
{
    cout << "Printing mode" << endl;
    for(int i = 0; i < cards.size(); i++)
    {
        cout << cards.at(i).card << endl;
    }
}
