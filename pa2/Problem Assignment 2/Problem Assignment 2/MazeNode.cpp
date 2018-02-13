#include "MazeNode.h"


MazeNode::MazeNode()
{
	_x = 0;
	_y = 0;
	_visited = false;
    _space = '#';
}

MazeNode::MazeNode(int x = 0, int y = 0, bool visited = false, char space = '#')
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

void MazeNode::setSpace(char space)
{
	_space = space;
}

char MazeNode::getSpace()
{
	return _space;
}