#include "Node.h"

using namespace std;

Node::Node(Point cords, Point a, Point b, bool es_negro, float data) {
	this->cords = cords;
	this->data = data;
	this->topLeft = a;
	this->botRight = b;
	this->es_negro=es_negro;
	topLeftTree = nullptr;
	topRightTree = nullptr;
	botLeftTree = nullptr;
	botRightTree = nullptr;
}

bool Node::inBoundary(Point p)
{

    return (p.x >= topLeft.x && p.x <= botRight.x
        && p.y >= topLeft.y && p.y <= botRight.y);
}
