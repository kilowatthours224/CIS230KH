//  Creature.h file - contains the initialization of the class "Creature"
#ifndef CREATURE_H_
#define CREATURE_H_
#include <stdio.h>
#include <ostream>
#include "Maze.h"

class Creature
{
private:
    int position[2];
    Maze lost;
    char path[7][20] = {
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
        };   //  The maze from the book has these dimensions.
    int pathDims[2] = {lost.getRows(), lost.getColumns()};
public:
    Creature(Maze&);    //  initializes the creature with the get-methods from the maze class
    void move(int, int);
    void setPath(int, int);
    void backtrack(int, int);
    int getPos1() { return position[0]; };
    int getPos2() { return position[1]; };
    friend ostream &operator<<(ostream&, Creature&);
};


#endif /* Creature_h */