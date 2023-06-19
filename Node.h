#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>
#include <utility>

using namespace std;

struct Point {
	int x;
	int y;
};

template <class T>
class Node
{
private:
	T data;

public:
	Node(pair<Point, Point> limites, bool es_negro, T data);

	Point cords;
	Node *nodes;
	// par de ptos que representa los limites del cuadrante del nodo
	pair<Point, Point> limites;
	bool es_negro;

	bool inBoundary(Point);
};

#endif
