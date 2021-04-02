//
//  Card.h
//  Assignment_1_(graded)
//
//  Created by Ken Hiltenbrand on 9/21/20.
//  Copyright © 2020 Ken Hiltenbrand. All rights reserved.
//

#ifndef Card_h
#define Card_h
#include <string>
using namespace std;

const int ACE = 0;
const int TWO = 1;
const int THREE = 2;
const int FOUR = 3;
const int FIVE = 4;
const int SIX = 5;
const int SEVEN = 6;
const int EIGHT = 7;
const int NINE = 8;
const int TEN = 9;
const int JACK = 10;
const int QUEEN = 11;
const int KING = 12;

const int HEARTS = 0;
const int DIAMONDS = 1;
const int CLUBS = 2;
const int SPADES = 3;

class Card
{
private:
    int face, suit;

public:
    Card(int paramFace, int paramSuit)
    {
        face = paramFace;
        suit = paramSuit;
    };
    Card()
    {
        face = 0;
        suit = 0;
    };
    static const string faces[13]; //  figured it would be best to define in .cpp
    static const string suits[4];  //  see note above
    string toString();
    void setSuit(int paramSuit) { suit = paramSuit; };
    void setFace(int paramFace) { face = paramFace; };
    int getSuit() { return suit; };
    int getFace() { return face; };
};

#endif /* Card_h */
