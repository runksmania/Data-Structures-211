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
	int _start_location_x;
	int _start_location_y;
	string _file_to_open;
	vector<vector<string>> _maze_vector;
	stack<string> _solution_stack;

public:
	MazeSolver();
	~MazeSolver();
	void printMaze();
	void solveMaze();
	void breadthSearch();
	void depthSearch();
	bool isOpenSpace(string spot_to_check);
};

#endif // !MAZE_SOLVER_H