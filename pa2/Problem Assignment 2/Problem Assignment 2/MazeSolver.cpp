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
			_mazeVector.resize(_height);
			for (int i = 0; i < _height; i++)
			{
				_mazeVector[i].resize(_width);
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
					_mazeVector[row_counter][i] = mazeRow[i];
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
			cout << _mazeVector[i][j];
		}
		cout << endl;
	}
}