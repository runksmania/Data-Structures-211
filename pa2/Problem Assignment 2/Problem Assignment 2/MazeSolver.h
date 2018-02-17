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
    bool _maze_solved;
	MazeNode _start_node;
	vector<vector<MazeNode>> _maze_vector;
    vector<vector<MazeNode>> _dfs_solution;
    vector<vector<MazeNode>> _bfs_solution;
	stack<MazeNode> _solution_stack;
	queue<MazeNode> _solution_queue;

public:
	MazeSolver();
	~MazeSolver();
	void printMaze();
    void printMazeToFile();
	void solveMaze();
	void breadthSearch();
	void depthSearch();
	MazeNode getStartNode();
    bool isMazeSolved();
};

#endif // !MAZE_SOLVER_H