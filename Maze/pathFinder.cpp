//  pathFinder.cpp: Driver for Assignment 3 - contains pathfinding elements and main
#include <iostream>
#include <stack>
#include "Maze.h"
#include "Creature.h"
using namespace std;

//  function prototypes
bool goNorth(Maze&, Creature&);
bool goSouth(Maze&, Creature&);
bool goEast(Maze&, Creature&);
bool goWest(Maze&, Creature&);


//  main function
int main()
{
    Maze cornMaze;
    Creature lassy(cornMaze);
    cout << "Maze to be completed:\n" << cornMaze << endl;
    bool try1 = goNorth(cornMaze, lassy);
    cout << "\nPath:\n" << lassy << endl;

    return 0;
}


bool goNorth(Maze &maze, Creature &sparky)
{
    //cout << "Calling goNorth()." << endl;
    int cPos1 = sparky.getPos1(), cPos2 = sparky.getPos2();
    //cout << "I'm trying to access array element " << cPos1 - 1 << " and " << cPos2 << endl;
    char subject = maze.getSubject(cPos1 - 1, cPos2);
    bool success = false;
    if ((subject == Maze::CLEAR) && (maze.boundsCheck(cPos1 - 1, cPos2)) && (subject != Maze::VISITED))
    {
        sparky.move(-1, 0);
        maze.setPath(sparky.getPos1(), sparky.getPos2());
        sparky.setPath(sparky.getPos1(), sparky.getPos2());
        if (maze.exitCheck(sparky.getPos1(), sparky.getPos2()))
        {
            success = true;
        }
        else
        {
            success = goNorth(maze, sparky);
            if (!success)
            {
                success = goWest(maze, sparky);
                if (!success)
                {
                    success = goEast(maze, sparky);
                    if (!success)
                    {
                        maze.setVisited(cPos1, cPos2);  //  Setting position as visited
                        sparky.backtrack(sparky.getPos1(), sparky.getPos2());
                        sparky.move(1, 0);             //  Backtracking South
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}

bool goWest(Maze &maze, Creature &sparky)
{
    //cout << "Calling goWest()." << endl;
    int cPos1 = sparky.getPos1(), cPos2 = sparky.getPos2();
    //cout << "I'm trying to access array element " << cPos1 << " and " << cPos2 << endl;
    char subject = maze.getSubject(cPos1, cPos2 - 1);
    bool success = false;
    if ((subject == Maze::CLEAR) && (maze.boundsCheck(cPos1, cPos2 - 1)) && (subject != Maze::VISITED))
    {
        sparky.move(0, -1);
        maze.setPath(sparky.getPos1(), sparky.getPos2());
        sparky.setPath(sparky.getPos1(), sparky.getPos2());
        if (maze.exitCheck(sparky.getPos1(), sparky.getPos2()))
        {
            success = true;
        }
        else
        {
            success = goWest(maze, sparky);
            if (!success)
            {
                success = goNorth(maze, sparky);
                if (!success)
                {
                    success = goSouth(maze, sparky);
                    if (!success)
                    {
                        maze.setVisited(cPos1, cPos2);  //  Setting position as visited
                        sparky.backtrack(sparky.getPos1(), sparky.getPos2());
                        sparky.move(0, 1);              //  Backtracking East
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}

bool goEast(Maze &maze, Creature &sparky)
{
    //cout << "Calling goEast()." << endl;
    int cPos1 = sparky.getPos1(), cPos2 = sparky.getPos2();
    //cout << "I'm trying to access array element " << cPos1 << " and " << cPos2 + 1 << endl;
    char subject = maze.getSubject(cPos1, cPos2 + 1);
    bool success = false;
    if ((subject == Maze::CLEAR) && (maze.boundsCheck(cPos1, cPos2 + 1)) && (subject != Maze::VISITED))
    {
        sparky.move(0, 1);
        maze.setPath(sparky.getPos1(), sparky.getPos2());
        sparky.setPath(sparky.getPos1(), sparky.getPos2());
        if (maze.exitCheck(sparky.getPos1(), sparky.getPos2()))
        {
            success = true;
        }
        else
        {
            success = goEast(maze, sparky);
            if (!success)
            {
                success = goNorth(maze, sparky);
                if (!success)
                {
                    success = goSouth(maze, sparky);
                    if (!success)
                    {
                        maze.setVisited(cPos1, cPos2);  //  Setting position as visited
                        sparky.backtrack(sparky.getPos1(), sparky.getPos2());
                        sparky.move(0, -1);             //  Backtracking West
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}

bool goSouth(Maze &maze, Creature &sparky)
{
    //cout << "Calling goSouth()." << endl;
    int cPos1 = sparky.getPos1(), cPos2 = sparky.getPos2();
    //cout << "I'm trying to access array element " << cPos1 + 1 << " and " << cPos2 << endl;
    char subject = maze.getSubject(cPos1 + 1, cPos2);
    bool success = false;
    if ((subject == Maze::CLEAR) && (maze.boundsCheck(cPos1, cPos2 + 1)) && (subject != Maze::VISITED))
    {
        sparky.move(1, 0);
        maze.setPath(sparky.getPos1(), sparky.getPos2());
        sparky.setPath(sparky.getPos1(), sparky.getPos2());
        if (maze.exitCheck(sparky.getPos1(), sparky.getPos2()))
        {
            success = true;
        }
        else
        {
            success = goSouth(maze, sparky);
            if (!success)
            {
                success = goWest(maze, sparky);
                if (!success)
                {
                    success = goEast(maze, sparky);//  Setting position as visited
                    if (!success)
                    {
                        maze.setVisited(cPos1, cPos2);  //  Setting position as visited
                        sparky.backtrack(sparky.getPos1(), sparky.getPos2());
                        sparky.move(-1, 0);             //  Backtracking North
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}