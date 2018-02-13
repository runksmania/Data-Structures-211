#include <iostream>
#include <fstream>
#include "MazeSolver.h"
#include "StringSplitter.h"
#include <string>

using namespace std;

MazeSolver::MazeSolver()
{
	//Grab file from user.
	string file_to_open = "";
	cout << "Enter input file: ";
	getline(cin, file_to_open);

	//Open file.
	ifstream input_file{ file_to_open };

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
				//cout << current_line << endl;

				for (int i = 0; i < _width; i++)
				{
					if (current_line[i] == 'o')
					{
						MazeNode temp_node(i, row_counter, true, 'o');
						_start_node = temp_node;
                        _solution_queue.push(_start_node);
						_maze_vector[row_counter][i] = temp_node;
					}
					else
					{
						MazeNode temp_node(i, row_counter, false, current_line[i]);
						_maze_vector[row_counter][i] = temp_node;
					}

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
			cout << _maze_vector[i][j].getSpace();
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
	while (!_solution_queue.empty())
	{
		MazeNode temp_node = _solution_queue.front();
		_solution_queue.pop();

		if (temp_node.getSpace() == '*')
		{
			return;
		}

		for (int i = 0; i < 4; i++)
		{
            
            MazeNode above_node = _maze_vector[temp_node.getY() - 1][temp_node.getX()];
            MazeNode right_node = _maze_vector[temp_node.getY()][temp_node.getX() + 1];
            MazeNode bottom_node = _maze_vector[temp_node.getY() + 1][temp_node.getX()];
            MazeNode left_node = _maze_vector[temp_node.getY()][temp_node.getX() - 1];

            if (above_node.getSpace() == '*' || right_node.getSpace() == '*' || bottom_node.getSpace() == '*' || left_node.getSpace() == '*')
            {
                return;
            }

			switch(i)
			{
			case 0:

				if (above_node.getSpace() == '.' && !above_node.getVisited())
				{
					above_node.setVisited(true);
					_maze_vector[above_node.getY()][above_node.getX()].setVisited(true);
                    _maze_vector[above_node.getY()][above_node.getX()].setSpace('X');
					_solution_queue.push(above_node);               
				}
				else
				{
					break;
				}

			case 1:

				if (right_node.getSpace() == '.' && !right_node.getVisited())
				{
					right_node.setVisited(true);
					_maze_vector[right_node.getY()][right_node.getX()].setVisited(true);
                    _maze_vector[right_node.getY()][right_node.getX()].setSpace('X');
					_solution_queue.push(right_node);
				}
				else
				{
					break;
				}

			case 2:

				if (bottom_node.getSpace() == '.' && !bottom_node.getVisited())
				{
					bottom_node.setVisited(true);
					_maze_vector[bottom_node.getY()][bottom_node.getX()].setVisited(true);
                    _maze_vector[bottom_node.getY()][bottom_node.getX()].setSpace('X');
					_solution_queue.push(bottom_node);
				}
				else
				{
					break;
				}

			case 3:

				if (left_node.getSpace() == '.' && !left_node.getVisited())
				{
					left_node.setVisited(true);
					_maze_vector[left_node.getY()][left_node.getX()].setVisited(true);
                    _maze_vector[left_node.getY()][left_node.getX()].setSpace('X');
					_solution_queue.push(left_node);
				}
				else
				{
					break;
				}
			}
		}
	}
}

void MazeSolver::depthSearch()
{

}

MazeNode MazeSolver::getStartNode()
{
	return _start_node;
}