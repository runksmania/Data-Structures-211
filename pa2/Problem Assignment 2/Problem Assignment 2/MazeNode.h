#pragma once
#ifndef MAZE_NODE_H
#define MAZE_NODE_H

#include <string>

using namespace std;

class MazeNode
{
private:
	int _x;
	int _y;
	bool _visited;
	string _space;

public:
	MazeNode();
	MazeNode(int x, int y, bool visited, string space);
	~MazeNode();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setVisited(bool visited);
	bool getVisited();
	void setSpace(string space);
	string getSpace();
};

#endif MAZE_NODE_H

