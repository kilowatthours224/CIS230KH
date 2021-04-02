//
//  PokerHand.cpp
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#include <iostream>
#include "PokerHand.h"

PokerHand::PokerHand(DeckOfCards &paramDeck)
{
    for (int c = 0; c < 5; c++)
    {
        pokerHand[c] = paramDeck.dealCard();
    }
}

PokerHand::PokerHand(Card param1, Card param2, Card param3, Card param4, Card param5)
{
    setPokerHand(param1, param2, param3, param4, param5);
}

void PokerHand::setPokerHand(Card param1, Card param2, Card param3, Card param4, Card param5)
{
    //  The specs said to create a method used specifically for setting the hand, but I figured
    //      an overloaded constructor could work as well, so I made both in a way that I thought
    //      would be efficient.
    pokerHand[0] = param1;
    pokerHand[1] = param2;
    pokerHand[2] = param3;
    pokerHand[3] = param4;
    pokerHand[4] = param5;
}

bool PokerHand::sameFace(Card param1, Card param2)
{
    bool sameFaceBool = false;
    if (param1.getFace() == param2.getFace())
    {
        sameFaceBool = true;
    }
    return sameFaceBool;
}

bool sameSuit(Card param1, Card param2)
{
    bool sameSuitBool = false;
    if (param1.getSuit() == param2.getSuit())
    {
        sameSuitBool = true;
    }
    return sameSuitBool;
}

void PokerHand::sortByFace()
{
    //Bubble Sort with getFace method in order ascending
    for (int o = 0; o < 4; o++)
    {
        for (int i = o + 1; i < 5; i++)
        {
            if (pokerHand[o].getFace() < pokerHand[i].getFace())
            {
                swap(pokerHand[o], pokerHand[i]);
            }
        }
    }
}

void PokerHand::sortBySuit()
{
    //Bubble Sort with getSuit method in order ascending
    for (int o = 0; o < 4; o++)
    {
        for (int i = o + 1; i < 5; i++)
        {
            if (pokerHand[o].getSuit() < pokerHand[i].getSuit())
            {
                swap(pokerHand[i], pokerHand[o]);
            }
        }
    }
}

//  This funct may not be working or even may not be getting called

void PokerHand::swap(Card &c1, Card &c2)
{
    Card temp = c1;
    c1 = c2;
    c2 = temp;
}

bool PokerHand::pair()
{
    bool pairBool = false;
    for (int o = 0; o < 4; o++)
    {
        for (int t = o + 1; t < 5; t++)
        {
            if (sameFace(pokerHand[t], pokerHand[o]))
            {
                pairBool = true;
                return pairBool;
            }
        }
    }
    return pairBool;
}

bool PokerHand::twoPair()
{
    bool twoPairBool = false, onePairBool = false;
    Card cardsRemaining[3];
    //  this'll be fun
    /*
        combinatorics?
        create a new array and set the new array to the pokerHand array using a for loop
        using this new data structure, find a pair, and move it to slots 0 and 1
        create a new array with the 3 remaining array elements and repeat the process
        look throught the rest of the array for another pair, and if one is found, set 
            a boolean var = true
    */

    //  finding an existing pair and moving it to the front of the array
    for (int o = 0; o < 4; o++)
    {
        for (int t = o + 1; t < 5; t++)
        {
            if (sameFace(pokerHand[t], pokerHand[o]))
            {
                onePairBool = true;
                swap(pokerHand[o], pokerHand[0]);
                swap(pokerHand[t], pokerHand[1]);
            }
        }
    }

    //  Can't have two pairs without one pair first
    if (onePairBool)
    {
        //  copying the remaining elements to a new array to be checked for a pair.
        for (int j = 2; j < 5; j++)
        {
            cardsRemaining[j - 2] = pokerHand[j];
        }

        //  checking the remaining cards for a pair.

        for (int o = 0; o < 2; o++)
        {
            for (int t = o + 1; t < 3; t++)
            {
                if (sameFace(cardsRemaining[t], cardsRemaining[o]))
                {
                    twoPairBool = true;
                }
            }
        }
    }
    return twoPairBool;
}

bool PokerHand::threeOfAKind()
{
    bool threeKindBool = false;
    //  This too will be exhilarating
    this->sortByFace();
    for (int i = 0; i < 3; i++)
    {
        if (pokerHand[i].getFace() == pokerHand[i + 1].getFace() &&
            pokerHand[i + 1].getFace() == pokerHand[i + 2].getFace())
        {
            threeKindBool = true;
        }
    }

    return threeKindBool;
}

bool PokerHand::fourOfAKind()
{
    bool fourKindBool = false;
    this->sortByFace();
    for (int i = 0; i < 2; i++)
    {
        if (pokerHand[i].getFace() == pokerHand[i + 1].getFace() &&
            pokerHand[i + 1].getFace() == pokerHand[i + 2].getFace() &&
            pokerHand[i + 2].getFace() == pokerHand[i + 3].getFace())
        {
            fourKindBool = true;
        }
    }
    return fourKindBool;
}

bool PokerHand::flush()
{
    bool flushBool = false;
    if (pokerHand[0].getSuit() == pokerHand[1].getSuit() &&
        pokerHand[1].getSuit() == pokerHand[2].getSuit() &&
        pokerHand[2].getSuit() == pokerHand[3].getSuit() &&
        pokerHand[3].getSuit() == pokerHand[4].getSuit())
    {
        flushBool = true;
    }
    return flushBool;
}

bool PokerHand::straight()
{
    bool straightBool = false;
    this->sortByFace();
    int c1, c2, c3, c4, c5;
    c1 = pokerHand[0].getFace();
    c2 = pokerHand[1].getFace();
    c3 = pokerHand[2].getFace();
    c4 = pokerHand[3].getFace();
    c5 = pokerHand[4].getFace();

    /*
    if second card face = to first card face +1 and third card face = to second card face +1 etc
    if card numbers are 1, 13, 12, 11, and 10 - then wrapping is acceptable. Special case scenario.
    */

    //  Special case
    if (c1 == ACE && c2 == TEN && c3 == JACK && c4 == QUEEN && c5 == KING)
    {
        straightBool = true;
    }
    else if (c2 == c1 + 1 && c3 == c1 + 2 && c4 == c1 + 3 && c5 == c1 + 4)
    {
        //  regular cases
        straightBool = true;
    }
    return straightBool;
}

string PokerHand::toString()
{
    string s;
    s = pokerHand[0].toString() + ", ";
    s += pokerHand[1].toString() + ", ";
    s += pokerHand[2].toString() + ", ";
    s += pokerHand[3].toString() + ", ";
    s += pokerHand[4].toString();
    return s;
}

Card PokerHand::getPokerHandCard(int paramCard) //  Returns the face/suit values as ints
{
    return pokerHand[paramCard];
} //  I did this this way to avoid the scope problem with objects
