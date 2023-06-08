#include "QuadTree.h"
#include "Node.h"
#include <iostream>

QuadTree::QuadTree(Point a, Point b){
	root = nullptr;
	root = new Node(std::pair(a, b), "", -1, false);

}

QuadTree::~QuadTree(){
	return;
}

int QuadTree::totalPoints(){
	return 1;
}

int QuadTree::totalNodes(){
	return 1;
}

void QuadTree::insert(Point p, int data){
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
