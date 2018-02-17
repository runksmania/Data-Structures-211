#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MazeSolver.h"
#include "SpaceReplacer.h"

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