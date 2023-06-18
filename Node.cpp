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