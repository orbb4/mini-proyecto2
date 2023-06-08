#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>
#include <utility>

using namespace std;

struct Point{
	int x;
	int y;
};

class Node{
public:

	Point cords;
	Node(pair<Point, Point> limites, string ciudad, int poblacion, bool es_negro);
	Node* nodes;
	// par de ptos que representa los limites del cuadrante del nodo
	// cada int[2] tiene: (cord superior izquierda, cord inferior derecha)
	pair<Point, Point> limites;
	string ciudad;
	int poblacion;
	bool es_negro;

};

#endif
