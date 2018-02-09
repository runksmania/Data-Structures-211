#pragma once
#ifndef MAZE_TO_VECTOR_H
#define MAZE_TO_VECTOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "StringSplitter.h"

using namespace std;

class MazeToVector
{
public:

	static vector<vector<string>> mazeToVector()
	{
		vector<vector<string>> mazeVector;

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
				int height = stoi(dimensions[1]);
				int width = stoi(dimensions[0]);

				//Resize vector to maze dimensions
				mazeVector.resize(height);
				for (int i = 0; i < height; i++)
				{
					mazeVector[i].resize(width);
				}

				int row_counter = 0;

				//Transition maze to 2d vector.
				while (input_file.good())
				{
					getline(input_file, current_line);
					cout << current_line << endl;
					vector<string> mazeRow = StringSplitter::split(current_line, " ");

					for (int i = 0; i < width; i++)
					{
						mazeVector[row_counter][i] = mazeRow[i];
					}
					row_counter++;
				}

			}
		}

		return mazeVector;
	}

};
#endif // !MAZE_TO_VECTOR_H
