#include "MazeNode.h"



MazeNode::MazeNode(int x = 0, int y = 0, bool visited = false, string space = "#")
{
	_x = x;
	_y = y;
	_visited = visited;
	_space = space;
}


MazeNode::~MazeNode()
{
}

void MazeNode::setX(int x)
{
	_x = x;
}

int MazeNode::getX()
{
	return _x;
}

void MazeNode::setY(int y)
{
	_y = y;
}

int MazeNode::getY()
{
	return _y;
}

void MazeNode::setVisited(bool visited)
{
	_visited = visited;
}

bool MazeNode::getVisited()
{
	return _visited;
}

void MazeNode::setSpace(string space)
{
	_space = space;
}

string MazeNode::getSpace()
{
	return _space;
}