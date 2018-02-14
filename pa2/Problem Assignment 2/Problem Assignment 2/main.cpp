#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MazeSolver.h"

using namespace std;

int main(void)
{
	MazeSolver mazeSolver;
	mazeSolver.printMaze();
    mazeSolver.solveMaze();
    mazeSolver.printMaze();

	return 0;
}