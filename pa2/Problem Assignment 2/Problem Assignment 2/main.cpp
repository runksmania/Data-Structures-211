#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MazeToVector.h"

using namespace std;

int main(void)
{
	vector<vector<string>> mazeVector = MazeToVector::mazeToVector();

	for (int i = 0; i < mazeVector.size(); i++)
	{
		for (int j = 0; j < mazeVector[i].size(); j++)
		{
			cout << mazeVector[i][j];
		}
		cout << endl;
	}



	return 0;
}