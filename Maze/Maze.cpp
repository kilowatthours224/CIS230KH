//  Maze.cpp file - implementation of the Maze class

#include "Maze.h"

Maze::Maze()
{
    // IDK what to put here
}

Maze Maze::operator=(Maze &copier)
{
    //maze = copier.maze;
    for (int i = 0; i < copier.rows; i++)
    {
        for (int o = 0; o < copier.columns; o++)
        {
            this->maze[i][o] = copier.maze[i][o];
        }
    }
    this->mazeEntrance[0] = copier.mazeEntrance[0];
    this->mazeEntrance[1] = copier.mazeEntrance[1];
    this->mazeExit[0] = copier.mazeExit[0];
    this->mazeExit[1] = copier.mazeExit[1];
    return *this;
}


//  exitCheck() - if the X and Y values entered match that of the exit position, returns true, otherwise returns false.
bool Maze::exitCheck(int pos1, int pos2)
{
    if ((pos1 == mazeExit[0]) && (pos2 == mazeExit[1]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Maze::boundsCheck(int pos1, int pos2)
{
    if (((pos1 < rows) && (pos1 >= 0)) && ((pos2 < columns) && (pos2 >= 0)))
    {
        return true;
    }
    else
    {
        return false;
    }
}


char Maze::getSubject(int pos1, int pos2)
{
    if (boundsCheck(pos1, pos2))
    {
        return maze[pos1][pos2];
    }
    else
    {
        cout << "You're trying to access a position outside of the maze, so I'm returning an empty char value." << endl;
        return 'q';
    }
    
}

//  setPath() - checks for wall, bounds violations, path, or visited markers, and if none are detected, then it is marked with a 'P' to denote it as part of the path
void Maze::setPath(int pos1, int pos2)
{
    char subject = getSubject(pos1, pos2);
    if ((subject =! WALL) && (subject != VISITED) && (subject != PATH))
    {
        maze[pos1][pos2] = PATH;
    }
}

//  setVisited() - checks for wall, bounds violations, or already visited, and if it passes, then checks for a path marker, and if one is found, will mark it as visited.
void Maze::setVisited(int pos1, int pos2)
{
    maze[pos1][pos2] = VISITED;
}

//  << operator - takes in the object, and outputs the maze in a visually pleasing manner

ostream &operator<<(ostream& line, Maze& mazeOut)
{
    string stringMaze = "";
    for (int i = 0; i < mazeOut.rows; i++)
    {
        for (int o = 0; o < mazeOut.columns; o++)
        {
            stringMaze += mazeOut.maze[i][o];
        }
        stringMaze += "\n";
    }
    line << stringMaze;
    return line;
}
