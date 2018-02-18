/*
Assignment: PA
Description: Learn how to solve mazes using breadth and depth search.
Author: Michael Cottrell
HSU ID: 946839472
Completion Time: 10 hours.
In completing this program, I received help from the following people:
Adam Carter
Mitchell (I think thats his name)
Kat
*/

#include <iostream>
#include <fstream>
#include "MazeSolver.h"
#include <string>
#include "StringSplitter.h"

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
            _bfs_solution = _maze_vector;
            _dfs_solution = _maze_vector;
        }
    }

}


MazeSolver::~MazeSolver()
{
    //Deliberately left empty.
}

void MazeSolver::printMaze()
{
    if (_maze_solved == false)
    {
        for (int i = 0; i < _height; i++)
        {
            for (int j = 0; j < _width; j++)
            {
                cout << _maze_vector[i][j].getSpace();
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    //Breadth Search print
    cout << "Breadth solution:\n";
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            cout << _bfs_solution[i][j].getSpace();
        }
        cout << endl;
    }
    cout << endl;

    //Depth Search print
    cout << "Depth solution:\n";
    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            cout << _dfs_solution[i][j].getSpace();
        }
        cout << endl;
    }
    cout << endl;
}

void MazeSolver::printMazeToFile()
{
    ofstream bfs_file{ "solution_bfs.txt" };
    ofstream dfs_file{ "solution_dfs.txt" };

    if (!_maze_solved)
    {
        bfs_file << "There is no solution to this maze.";
        dfs_file << "There is no solution to this maze.";
        bfs_file.close();
        dfs_file.close();
        return;
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            bfs_file << _bfs_solution[i][j].getSpace();
        }
        bfs_file << endl;
    }

    for (int i = 0; i < _height; i++)
    {
        for (int j = 0; j < _width; j++)
        {
            dfs_file << _dfs_solution[i][j].getSpace();
        }
        dfs_file << endl;
    }
    bfs_file.close();
    dfs_file.close();
}

void MazeSolver::solveMaze()
{
    //clear out solution queue;
    while (_solution_queue.empty() == false)
    {
        _solution_queue.pop();
    }

    _bfs_solution = _maze_vector;
    breadthSearch();

    //clear out solution stack;
    while (_solution_stack.empty() == false)
    {
        _solution_stack.pop();
    }

    _dfs_solution = _maze_vector;
    depthSearch();

}

void MazeSolver::breadthSearch()
{
    _solution_queue.push(_start_node);
    _maze_solved = false;

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

            MazeNode above_node = _bfs_solution[temp_node.getY() - 1][temp_node.getX()];
            MazeNode right_node = _bfs_solution[temp_node.getY()][temp_node.getX() + 1];
            MazeNode bottom_node = _bfs_solution[temp_node.getY() + 1][temp_node.getX()];
            MazeNode left_node = _bfs_solution[temp_node.getY()][temp_node.getX() - 1];

            if (above_node.getSpace() == '*' || right_node.getSpace() == '*' || bottom_node.getSpace() == '*' || left_node.getSpace() == '*')
            {
                _maze_solved = true;
                return;
            }

            switch (i)
            {
            case 0:

                if (above_node.getSpace() == '.' && !above_node.getVisited())
                {
                    _bfs_solution[above_node.getY()][above_node.getX()].setVisited(true);
                    _bfs_solution[above_node.getY()][above_node.getX()].setSpace('X');
                    _solution_queue.push(above_node);
                }
                else
                {
                    break;
                }

            case 1:

                if (right_node.getSpace() == '.' && !right_node.getVisited())
                {
                    _bfs_solution[right_node.getY()][right_node.getX()].setVisited(true);
                    _bfs_solution[right_node.getY()][right_node.getX()].setSpace('X');
                    _solution_queue.push(right_node);
                }
                else
                {
                    break;
                }

            case 2:

                if (bottom_node.getSpace() == '.' && !bottom_node.getVisited())
                {
                    _bfs_solution[bottom_node.getY()][bottom_node.getX()].setVisited(true);
                    _bfs_solution[bottom_node.getY()][bottom_node.getX()].setSpace('X');
                    _solution_queue.push(bottom_node);
                }
                else
                {
                    break;
                }

            case 3:

                if (left_node.getSpace() == '.' && !left_node.getVisited())
                {
                    _bfs_solution[left_node.getY()][left_node.getX()].setVisited(true);
                    _bfs_solution[left_node.getY()][left_node.getX()].setSpace('X');
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
    _solution_stack.push(_start_node);
    _maze_solved = false;

    while (!_solution_stack.empty())
    {
        MazeNode temp_node = _solution_stack.top();
        _solution_stack.pop();

        MazeNode above_node = _dfs_solution[temp_node.getY() - 1][temp_node.getX()];
        MazeNode right_node = _dfs_solution[temp_node.getY()][temp_node.getX() + 1];
        MazeNode bottom_node = _dfs_solution[temp_node.getY() + 1][temp_node.getX()];
        MazeNode left_node = _dfs_solution[temp_node.getY()][temp_node.getX() - 1];

        if (temp_node.getSpace() == '*' || above_node.getSpace() == '*' || right_node.getSpace() == '*' || bottom_node.getSpace() == '*' || left_node.getSpace() == '*')
        {
            _maze_solved = true;
            return;
        }

        if (above_node.getSpace() == '.' && !above_node.getVisited())
        {
            // hasn't checked all possible locations to go from that node
            _solution_stack.push(temp_node);

            while (above_node.getSpace() == '.' && !above_node.getVisited())
            {
                _dfs_solution[above_node.getY()][above_node.getX()].setVisited(true);
                _dfs_solution[above_node.getY()][above_node.getX()].setSpace('X');
                _solution_stack.push(above_node);
                above_node = _dfs_solution[above_node.getY() - 1][above_node.getX()];
            }

            if (above_node.getSpace() == '*')
            {
                _maze_solved = true;
                return;
            }
        }
        else if (right_node.getSpace() == '.' && !right_node.getVisited())
        {
            // hasn't checked all possible locations to go from that node
            _solution_stack.push(temp_node);

            while (right_node.getSpace() == '.' && !right_node.getVisited())
            {
                _dfs_solution[right_node.getY()][right_node.getX()].setVisited(true);
                _dfs_solution[right_node.getY()][right_node.getX()].setSpace('X');
                _solution_stack.push(right_node);
                right_node = _dfs_solution[right_node.getY()][right_node.getX() + 1];
            }

            if (right_node.getSpace() == '*')
            {
                _maze_solved = true;
                return;
            }
        }
        else if (bottom_node.getSpace() == '.' && !bottom_node.getVisited())
        {
            // hasn't checked all possible locations to go from that node
            _solution_stack.push(temp_node);

            while (bottom_node.getSpace() == '.' && !bottom_node.getVisited())
            {
                _dfs_solution[bottom_node.getY()][bottom_node.getX()].setVisited(true);
                _dfs_solution[bottom_node.getY()][bottom_node.getX()].setSpace('X');
                _solution_stack.push(bottom_node);
                bottom_node = _dfs_solution[bottom_node.getY() + 1][bottom_node.getX()];
            }

            if (bottom_node.getSpace() == '*')
            {
                _maze_solved = true;
                return;
            }
        }
        else if (left_node.getSpace() == '.' && !left_node.getVisited())
        {

            while (left_node.getSpace() == '.' && !left_node.getVisited())
            {
                _dfs_solution[left_node.getY()][left_node.getX()].setVisited(true);
                _dfs_solution[left_node.getY()][left_node.getX()].setSpace('X');
                _solution_stack.push(left_node);
                left_node = _dfs_solution[left_node.getY()][left_node.getX() - 1];
            }

            if (left_node.getSpace() == '*')
            {
                _maze_solved = true;
                return;
            }
        }
    }
}

MazeNode MazeSolver::getStartNode()
{
    return _start_node;
}

bool MazeSolver::isMazeSolved()
{
    return _maze_solved;
}