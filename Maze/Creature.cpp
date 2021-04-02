//  Creature.cpp - contains implementation of Creature class.
#include "Creature.h"


//  Constructor function for class Creature
Creature::Creature(Maze &maze)
{
    lost = maze;

    position[0] = maze.getEnterX();
    position[1] = maze.getEnterY();
    //cout << "Initializing Creature with startying point (" << position[0] << "," << position[1] << ")" << endl;
    path[position[0]][position[1]] = Maze::PATH;
}

//  I'm assuming that the checks in the pathFinder.cpp are working, so I don't do any validation here
void Creature::move(int dir1, int dir2)
{
    position[0] += dir1;
    position[1] += dir2;
    //cout << "I'm moving to position (" << position[0] << " , " << position[1] << " )" << endl;
}

// setPath() - sets the given position equal to 'P'
void Creature::setPath(int pos1, int pos2)
{
    char subject = lost.getSubject(pos1, pos2);
    if(subject != Maze::WALL)
    {
        path[pos1][pos2] = Maze::PATH;
        cout << "Setting (" << pos1 << "," << pos2 << ") as a 'path' block." << endl;
    }
}

//  backtrack - erases a path marker from the path array
void Creature::backtrack(int pos1, int pos2)
{
    path[pos1][pos2] = Maze::CLEAR;
    cout << "Removing (" << pos1 << "," << pos2 << ") from the path." << endl;
}


ostream &operator<<(ostream &lines, Creature& creatOut)
{
    string pathString = "";
    for (int i = 0; i < creatOut.pathDims[0]; i++)
    {
        for (int o = 0; o < creatOut.pathDims[1]; o++)
        {
            pathString += creatOut.path[i][o];
        }
        pathString += "\n";
    }
    lines << pathString;
    return lines;
}


