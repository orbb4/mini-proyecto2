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
	if(!root.es_negro){
		root.cords = p;
	}else{
		
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
