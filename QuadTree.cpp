#include "QuadTree.h"
#include "Node.h"
#include <iostream>

QuadTree::QuadTree(Point a, Point b){
	root = nullptr;
	root = new Node(std::pair(a, b), "", -1, false);
	puntos = 0;
	nodos = 0;
}

QuadTree::~QuadTree(){
	return;
}

int QuadTree::totalPoints(){
	return puntos;
}

int QuadTree::totalNodes(){
	return nodos;
}

void QuadTree::insert(Point p){
	bool not_inserted = true;
	bool in_boundaries = false;
	Node* actualNode = root;

	//OBTIENE LOS LIMITES Y VE SI EL PUNTO ESTÁ FUERA DE ELLOS
	Point topLeft = root->get(0)<limites>;
	Point botRight = root->get(1)<limites>;
	if (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && 
		p.y <= botRight.y)
	{
		in_boundaries = true;
	}
	else{in_boundaries = false;}

	//Loop para encontrar el nodo correcto para insertar p
	while(true){
		if (!root->es_negro)
		{

		}
		std::cout<<"alo?"<<std::endl;
		break;
	}
	return;
}

void QuadTree::list(){
	return;
}

int QuadTree::countRegion(Point p, int d){
	return 1;
}

int QuadTree::AggregateRegion(Point p, int d){
	return 1;
}

int main(){
	return 0;
}

