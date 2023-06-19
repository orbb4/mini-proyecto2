#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node(pair<Point, Point> limites, bool es_negro, T data) {
	this->data = data;
	this->limites=limites;
	this->es_negro=es_negro;
	Node nodesAux[4];
	nodes = nodesAux;
}

template <class T>

bool Node<T>::inBoundary(Point p)
{
    Point topLeft = std::get<0>(limites);
    Point botRight = std::get<1>(limites);
    return (p.x >= topLeft.x && p.x <= botRight.x
        && p.y >= topLeft.y && p.y <= botRight.y);
}
