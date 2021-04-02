//
//  DeckOfCards.cpp
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#include <ctime>
#include <iostream>
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
    for (int s = 0; s < 4; s++)
    {
        for (int f = 0; f < 13; f++)
        {
            deck[cardIndex] = Card(f, s);
            cardIndex++;
        }
    }
}

void DeckOfCards::shuffle()
{
    srand(static_cast<unsigned>(time(0))); //  figured this was the best way forward
    int randCard1, randCard2;
    Card temp;
    for (int c = 0; c < 3 * cardIndex; c++)
    { //Three times the number of cards seems to be enough to randomize
        randCard1 = rand() % (cardIndex);
        randCard2 = rand() % (cardIndex);

        //  could have used a swap here, but defined it just to be safe.
        temp = deck[randCard1];
        deck[randCard1] = deck[randCard2];
        deck[randCard2] = temp;
    }
}

Card DeckOfCards::dealCard()
{
    if (moreCards())
    {
        cardIndex--;
        return deck[cardIndex];
    }
    else
    {
        //  Was for debugging purposes.
        throw runtime_error("Deck is empty. Check Code.");
    }
}

bool DeckOfCards::moreCards()
{
    bool notLastCard = true;
    if (cardIndex == 0)
    {
        notLastCard = false;
    } 
    return notLastCard;
}
