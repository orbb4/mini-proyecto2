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
	Node* actualNode = root;
	while(true){
		if (!root->es_negro)
		{
			float new_lim_sup_x = 0;
			float new_lim_inf_x = 0;
			float new_lim_sup_y = 0;
			float new_lim_inf_y = 0;
			root->data = p;
			//PRIMER CUADRANTE
			new_lim_sup_x = root->get(0)<limites>.x;
			new_lim_inf_x = root->get(1)<limites>.x;
			


			root->nodes[0] = root = new Node(std::pair(new_lim_sup, new_lim_inf), "", -1, false);
			root->nodes[1] = root = new Node(std::pair(new_lim_sup, new_lim_inf), "", -1, false);
			root->nodes[2] = root = new Node(std::pair(new_lim_sup, new_lim_inf), "", -1, false);
			root->nodes[3] = root = new Node(std::pair(new_lim_sup, new_lim_inf), "", -1, false);

			break;
		}
		if ()
		{
			/* code */
		}
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

