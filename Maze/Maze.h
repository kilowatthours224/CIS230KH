//  Maze.h file - Contains initialization for class "Maze"

#ifndef Maze_h
#define Maze_h
#include <ostream>
#include <iostream>
using namespace std;

class Maze
{
private:
    //  Initialization of the maze with the default maze being like that of the book.
    char maze[7][20] = {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X',' ','X'},
        {'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X','X','X','X',' ','X'},
        {'X',' ','X','X','X','X','X',' ',' ','X','X','X','X',' ',' ',' ','X','X',' ','X'},
        {'X',' ','X','X','X','X','X',' ','X','X','X','X','X','X','X',' ','X','X',' ','X'},
        {'X',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ','X','X',' ','X'},
        {'X',' ','X','X','X','X','X','X','X','X','X','X',' ','X','X',' ',' ',' ',' ','X'},
        {'X','X','X','X','X','X','X','X','X','X','X','X',' ','X','X','X','X','X','X','X'}
        };
    
    //  Data Members describing key aspects of the maze
    int mazeEntrance[2] = {6, 12};
    int mazeExit[2] = {0, 18};
    int rows = 7;
    int columns = 20;
    
public:
    
    //  Constants that are public to this class's implementation and any class that is using this.
    static const char WALL = 'X';
    static const char PATH = 'P';
    static const char VISITED = 'V';
    static const char CLEAR = ' ';
    
    //  Constructor
    Maze();
    
    //operator
    Maze operator=(Maze&);
    int getEnterX() { return mazeEntrance[0]; };
    int getEnterY() { return mazeEntrance[1]; };
    bool exitCheck(int, int);

//    bool wallCheck(int, int);
//    bool visitedCheck(int, int);
    bool boundsCheck(int, int);
    char getSubject(int, int);
    int getRows() { return rows; };
    int getColumns() { return columns; };
    void setPath(int, int);
    void setVisited(int, int);
    friend ostream &operator<<(ostream&, Maze&);
};


#endif /* Maze_h */