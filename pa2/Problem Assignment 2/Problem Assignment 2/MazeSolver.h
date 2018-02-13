#pragma once
#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "MazeNode.h"

using namespace std;

class MazeSolver
{
private:
	int _height;
	int _width;
	MazeNode _start_node;
	vector<vector<MazeNode>> _maze_vector;
	stack<MazeNode> _solution_stack;
	queue<MazeNode> _solution_queue;

public:
	MazeSolver();
	~MazeSolver();
	void printMaze();
	void solveMaze();
	void breadthSearch();
	void depthSearch();
	MazeNode getStartNode();
};

#endif // !MAZE_SOLVER_H