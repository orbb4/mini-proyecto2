#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>
#include <utility>

using namespace std;

struct Point {
	int x;
	int y;
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
	Node(Point cords, Point topLeft, Point botRight, bool es_negro, float data);

	Point topLeft;
	Point botRight;
	Point cords;
	float data;

	bool es_negro;
	Node* topLeftTree;
	Node* topRightTree;
	Node* botLeftTree;
	Node* botRightTree;

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
