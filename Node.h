#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>
#include <utility>

using namespace std;

struct Point {
	float x;
	float y;
	Point() {
		x = 0;
		y = 0;
	}
	Point(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

class Node
{
public:
	Node(Point cords, float data);
	Point pos;
	float data;

	bool inBoundary(Point);
};

class NodeL
{
public:
	Point pto;
	float pobl;
	NodeL(Point _pto, float _pobl) {
		pto = _pto;
		pobl = _pobl;
	}
};
#endif
