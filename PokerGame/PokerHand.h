//
//  PokerHand.h
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#ifndef PokerHand_h
#define PokerHand_h

#include "DeckOfCards.h"

class PokerHand
{
private:
    Card pokerHand[5];

public:
    PokerHand(DeckOfCards &paramDeck);
    PokerHand(Card param1, Card param2, Card param3, Card param4, Card param5);
    void setPokerHand(Card param1, Card param2, Card param3, Card param4, Card param5);
    bool sameFace(Card param1, Card param2);
    bool sameSuit(Card param1, Card param2);
    void swap(Card &c1, Card &c2);
    void sortByFace();
    void sortBySuit();
    bool pair();
    bool twoPair();
    bool threeOfAKind();
    bool fourOfAKind();
    bool flush();
    bool straight();
    string toString();
    Card getPokerHandCard(int);
};

#endif /* PokerHand_h */
