#include "QuadTree.h"
#include "Node.h"
#include <iostream>


template <class T>
QuadTree<T>::QuadTree(Point a, Point b){
	root = nullptr;
	root = new Node(std::pair(a, b), "", -1, false);
	puntos = 0;
	nodos = 0;
}

template <class T>
QuadTree<T>::~QuadTree(){
	return;
}

template <class T>
int QuadTree<T>::totalPoints(){
	return puntos;
}

template <class T>
int QuadTree<T>::totalNodes(){
	return nodos;
}

template <class T>
void QuadTree<T>::insert(Point p) {

    Node<T> *currentQuad = root;

    while (currentQuad != nullptr) {

        if (!currentQuad->inBoundary(p))
            return;

        if (abs(currentQuad->topLeft.x - currentQuad->botRight.x) <= 0.0001
            && abs(currentQuad->topLeft.y - currentQuad->botRight.y) <= 0.0001) {
            return;
        }

        if ((currentQuad->topLeft.x + currentQuad->botRight.x) / 2 >= p.x) {
            // Indicates topLeftTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topLeftTree == nullptr)
                    currentQuad->topLeftTree = new Node(
                        Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2));
                currentQuad = currentQuad->topLeftTree;
            }
            // Indicates botLeftTree
            else {
                if (currentQuad->botLeftTree == nullptr)
                    currentQuad->botLeftTree = new Node(
                        Point(currentQuad->topLeft.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->botRight.y));
                currentQuad = currentQuad->botLeftTree;
            }
        }
        else {
            // Indicates topRightTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topRightTree == nullptr)
                    currentQuad->topRightTree = new Node(
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->topLeft.y),
                        Point(currentQuad->botRight.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2));
                currentQuad = currentQuad->topRightTree;
            }
            // Indicates botRightTree
            else {
                if (currentQuad->botRightTree == nullptr)
                    currentQuad->botRightTree = new Node(
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point(currentQuad->botRight.x, currentQuad->botRight.y));
                currentQuad = currentQuad->botRightTree;
            }
        }
    }
}

template <class T>
void QuadTree<T>::list(){
	return;
}


template <class T>
int QuadTree<T>::countRegion(Point p, int d){
	return 1;
}


template <class T>
int QuadTree<T>::AggregateRegion(Point p, int d){
	return 1;
}
