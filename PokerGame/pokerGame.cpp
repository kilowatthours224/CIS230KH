//  PokerGame.cpp -> implements Card DeckOfCards and PokerHand classes into a poker game
//      Will document systems used where possible/necessary
#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
#include "PokerHand.h"
using namespace std;

//  Function prototypes
void outputHand(PokerHand &hand);
void helpOutput();
void cardReplacer(PokerHand &, DeckOfCards &);
int gameFacilitator();
void computerLogic(PokerHand &, DeckOfCards &);
int handEval(PokerHand &);
bool inputVal(int inVal);

//  main function, facilitates everything
int main()
{
    //  Greeting and rules
    cout << "Poker! Poker Poker! Welcome to Ken Hiltenbrand's poker game!" << endl;
    helpOutput();

    bool playerHere = true;
    int playerChoice;
    while (playerHere)
    {
        playerChoice = gameFacilitator();
        if (playerChoice == 0)
        {
            playerHere = false;
        }
    }
    return 0;
}

//  outputHand(): Displays the player's poker hand
void outputHand(PokerHand &hand)
{
    cout << "Here is your hand:" << endl;
    cout << hand.toString() << endl;
}

//  helpOutput(): displays rules for the menu-based nature of this implementation of poker.
void helpOutput()
{
    cout << "Here are the rules for poker and for this program:" << endl
         << endl;
    cout << "Poker:" << endl;
    cout << "You will be dealt 5 cards from which you may keep or discard any to pick up new cards." << endl;
    cout << "There are a few different hands, that have value points." << endl;
    cout << "The value-order of the hands is as follows:" << endl;
    cout << "Four of a Kind\nStraight\nFlush\nThree of a Kind\nTwo Pair\nPair" << endl;
    cout << "Between you and the AI, whoever has the better hand wins, unless two hands have the same value" << endl;
    cout << "\nThis Program:" << endl;
    cout << "You will be prompted to enter input, please enter numbers only." << endl;
    cout << "Enter 1-5 to select a card to //.\nPress 7 when you have selected all that you sish to." << endl;
    cout << "Your hand will then be evaluated, compared to that of the AI, and a winner of the round will be determined." << endl;
    cout << "After you have completed a round, you will be asked if you would like to play again." << endl;
    cout << "Please enter 1 if you would like to proceed or 2 if you would not." << endl;
    cout << "You may enter 0 to see this list of rules/procedures at any time.\n"
         << endl;
    cout << "Please press enter to continue." << endl;
    cin.get(); //  I remember something like this from cis115 with python, so I checked for something like it from the book. Found it in ch3
}

//  cardReplacer(): Prompts the player to remove a card of their choosing.
void cardReplacer(PokerHand &pokerH, DeckOfCards &deck)
{
    Card temp[5];
    for (int i = 0; i < 5; i++)
    {
        temp[i] = pokerH.getPokerHandCard(i);
    }
    int cardCount = 0;
    int cardnum;
    bool replaceMoreCards = true;
    while (replaceMoreCards && (cardCount < 3))
    {

        cout << "If you would like to replace a card, please indicate which one by the number below it on screen." << endl;
        cout << "If not, please enter the number 7." << endl;
        cin >> cardnum;
        if (inputVal(cardnum))
        {
            if (cardnum == 7)
            {
                replaceMoreCards = false;
            }
            if (cardnum >= 1 && cardnum <= 5)
            {
                temp[cardnum - 1] = deck.dealCard();
                cardCount++;
            }
            else
            {
                replaceMoreCards = false;
            }
        }
    }
    pokerH.setPokerHand(temp[0], temp[1], temp[2], temp[3], temp[4]);
}

// gameFacilitator(): facilitates gameplay
//  Note: This was intentionally set up this way to ensure that the deck object would go out of scope, and a new one would be created each time this is called
int gameFacilitator()
{
    //  Setting up the poker game
    DeckOfCards deck;
    deck.shuffle();
    PokerHand userHand(deck);
    PokerHand computerHand(deck);
    string hands[] = {"High Card", "Pair", "Two Pair", "Three of a Kind", "Flush", "Straight", "Four of a Kind"};

    // Let the poker game begin!
    int userChoice;
    outputHand(userHand);
    cout << "Card #  1\t\t2\t\t3\t\t4\t\t5" << endl;
    cout << "Your current highest scoring hand is a " << hands[handEval(userHand)] << endl
         << endl;
    cardReplacer(userHand, deck);
    outputHand(userHand);
    cout << "Now your highest scoring hand is a " << hands[handEval(userHand)] << endl
         << endl;

    computerLogic(computerHand, deck);
    cout << "Here is the computer's hand:\n"
         << computerHand.toString() << endl;
    cout << "The computer's highest scoring hand is a " << hands[handEval(computerHand)] << endl
         << endl;
    int userScore = handEval(userHand);
    int cpuScore = handEval(computerHand);

    //  Check for special case
    if (userScore == 0 && cpuScore == 0)
    {
        userHand.sortByFace();
        computerHand.sortByFace();
        Card uTemp = userHand.getPokerHandCard(4);
        Card cTemp = computerHand.getPokerHandCard(4);

        if (uTemp.getFace() > cTemp.getFace())
        {
            userScore += 1;
        }
        else if (uTemp.getFace() < cTemp.getFace())
        {
            cpuScore += 1;
        }
    }

    //  final dedision tree
    if (userScore > cpuScore)
    {
        cout << "You win!!!" << endl;
    }
    else if (cpuScore > userScore)
    {
        cout << "You lose! Better luck next time!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
    }

    //  Ask the user if they want to keep going with a little bit of input validation just to be safe.
    //  I was going to use another inputVal() type function, but I realized that I couldn't override the first one.
    //      It also was just easier to do this here than to create another function to call.
    bool valIn = false;
    while (!valIn)
    {
        cout << "Would you like to keep playing? Please enter 1 for yes, 0 for no.";
        cin >> userChoice;
        cout << endl;
        if ((userChoice == 0) || (userChoice == 1))
        {
            valIn = true;
        }
        else
        {
            cout << "That is not valid input!! Please give numerical input 0 or 1." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    cout << endl
         << endl;

    return userChoice;
}

//  computerLogic(): takes the hand, runs eval, then sees what it can discard and what it shouldn't
void computerLogic(PokerHand &pokerH, DeckOfCards &deck)
{
    //  Here is the brains behind the AI. It is dumb for now, but I'll try to improve it
    int cpuScore = handEval(pokerH);
    if (cpuScore >= 1 && cpuScore <= 6)
    {
        return;
    }
    else if (cpuScore == 0)
    {
        //  look for three high cards, and discard the rest.
        pokerH.sortByFace();
        Card temp[5] = {pokerH.getPokerHandCard(0), pokerH.getPokerHandCard(1), pokerH.getPokerHandCard(2), pokerH.getPokerHandCard(3), pokerH.getPokerHandCard(4)};
        for (int i = 0; i < 5; i++)
        {
            //  Check for high card (10 or higher) and discard everything else.
            if (temp[4 - i].getFace() < 9 && temp[4 - i].getFace() != 0)
            {
                temp[4 - i] = deck.dealCard();
            }
        }
        pokerH.setPokerHand(temp[0], temp[1], temp[2], temp[3], temp[4]);
    }
    //  Note: It's not very intuitive and I wanted to have one that evaluates the hand, saves cards that would score anything, and replace the rest if possible,
    //      but I got bogged down with work from other classes and then got muddled in problems that came when I tried to use python syntax with C++. That was
    //      fun to debug.
}

//  handEval(): Evaluates hand and assigns a value to the hand in order of hand value (according to the site you provided us)
int handEval(PokerHand &pokerH)
{
    //
    if (pokerH.fourOfAKind())
    {
        return 6;
    }
    else if (pokerH.straight())
    {
        return 5;
    }
    else if (pokerH.flush())
    {
        return 4;
    }
    else if (pokerH.threeOfAKind())
    {
        return 3;
    }
    else if (pokerH.twoPair())
    {
        return 2;
    }
    else if (pokerH.pair())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//inputVal(): validates input for the card replacer
bool inputVal(int inVal)
{
    bool valInput = false;
    if (((inVal <= 6) && (inVal >= 1)) || (inVal == 7))
    {
        valInput = true;
    }
    else
    {
        cout << "That is not valid input!! Please give numerical input range 1-5 or 7." << endl
             << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return valInput;
}
