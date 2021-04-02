//
//  DeckOfCards.h
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#ifndef DeckOfCards_h
#define DeckOfCards_h

#include "Card.h"

class DeckOfCards
{
private:
    Card deck[52];
    Card currentCard;
    int cardIndex = 0;

public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards();
};

#endif /* DeckOfCards_h */
