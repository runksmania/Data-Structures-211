#include <iostream>
#include <fstream>
#include "MazeSolver.h"
#include "StringSplitter.h"

using namespace std;

MazeSolver::MazeSolver()
{
	//Grab file from user.
	_file_to_open = "";
	cout << "Enter input file: ";
	getline(cin, _file_to_open);

	//Open file.
	ifstream input_file{ _file_to_open };

	if (input_file.is_open())
	{
		if (input_file.good())
		{
			//Grab dimensions from maze
			string current_line;
			getline(input_file, current_line);
			vector<string> dimensions = StringSplitter::split(current_line, " ");
			_height = stoi(dimensions[1]);
			_width = stoi(dimensions[0]);

			//Resize vector to maze dimensions
			_maze_vector.resize(_height);
			for (int i = 0; i < _height; i++)
			{
				_maze_vector[i].resize(_width);
			}

			int row_counter = 0;

			//Transition maze to 2d vector.
			while (input_file.good())
			{
				getline(input_file, current_line);
				cout << current_line << endl;
				vector<string> mazeRow = StringSplitter::split(current_line, " ");

				for (int i = 0; i < _width; i++)
				{
					if (mazeRow[i] == "o")
					{
						_start_location_x = i;
						_start_location_y = row_counter;
					}
					_maze_vector[row_counter][i] = mazeRow[i];
				}
				row_counter++;
			}

		}
	}

}


MazeSolver::~MazeSolver()
{
	//Deliberately left empty.
}

void MazeSolver::printMaze()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			cout << _maze_vector[i][j];
		}
		cout << endl;
	}
}

void MazeSolver::solveMaze()
{
	string search_decision = "";
	cout << "How would you like to solve the maze?\n Enter 1 for Breadth First Search. Enter 2 for Depth First Search.\n How do you want to solve: ";
	getline(cin, search_decision);

	if (search_decision == "1")
	{
		breadthSearch();
	}
	else
	{
		depthSearch();
	}
}

void MazeSolver::breadthSearch()
{
	bool maze_unsolved = true;
	int direction = 0;
	int test_count = 0;
	int current_x = _start_location_x;
	int current_y = _start_location_y;
	string current_space = _maze_vector[current_y][current_x];

	while (maze_unsolved)
	{
		switch(direction){

		case 0:
			if (current_space == "." || current_space == "o")
			{

			}
			direction++;
			test_count++;
			break;

		case 1:
			cout << "case: 1" << endl;
			direction++;
			test_count++;
			break;

		case 2:
			cout << "case: 2" << endl;
			direction++;
			test_count++;
			break;

		case 3:
			cout << "case: 3" << endl;
			direction++;
			test_count++;
			break;
		}
		
		direction %= 4;

		if (test_count == 8)
		{
			maze_unsolved = false;
		}
	}
	

}

void MazeSolver::depthSearch()
{

}

bool MazeSolver::isOpenSpace(string spot_to_check)
{
	bool is_open_space = false;
	
	if (spot_to_check == ".")
	{
		is_open_space = true;
	}
	else
	{
		is_open_space = false;
	}

	return is_open_space;
	
}