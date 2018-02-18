/*
Assignment: PA
Description: Learn how to solve mazes using breadth and depth search.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 10 hours.
In completing this program, I received help from the following people:
Adam Carter
Mitchell (I think thats his name)
Kat
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MazeSolver.h"

using namespace std;

int main(void)
{
	MazeSolver mazeSolver;
    cout << "Maze to be solved:\n";
    mazeSolver.printMaze();
    mazeSolver.solveMaze();

    if (mazeSolver.isMazeSolved())
    {
        mazeSolver.printMaze();
    }
    else
    {
        cout << "There is no solution to this maze.\n";
    }

    mazeSolver.printMazeToFile();

	return 0;
}