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
private:
	float data;

public:
	Node(Point cords, Point topLeft, Point botRight, bool es_negro, float data);

	Point topLeft;
	Point botRight;
	Point cords;

	bool es_negro;
	Node* topLeftTree;
	Node* topRightTree;
	Node* botLeftTree;
	Node* botRightTree;

	bool inBoundary(Point);
};

#endif
