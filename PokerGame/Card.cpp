//
//  Card.cpp
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#include <iostream>
#include "Card.h"

const string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

const string Card::faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

string Card::toString()
{
    string cardAsString = faces[face] + " of " + suits[suit];
    return cardAsString;
}
