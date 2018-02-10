#pragma once
#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class MazeSolver
{
private:
	int _height;
	int _width;
	string _file_to_open;
	vector<vector<string>> _mazeVector;
	stack<string> _solutionStack;

public:
	MazeSolver();
	~MazeSolver();
	void printMaze();
};

#endif // !MAZE_SOLVER_H