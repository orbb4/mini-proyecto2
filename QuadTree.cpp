#include "QuadTree.h"
#include "Node.h"
#include <iostream>

QuadTree::QuadTree(Point a, Point b){
	root = nullptr;
	root = new Node(Point(0, 0), a, b, false, 0);
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

// Inserta un nodo
void QuadTree::insert(Point p, float data)
{
    Node* currentQuad = root;

    if (root == NULL)
        return;

    while (currentQuad != nullptr) {

        if (!currentQuad->inBoundary(p))
            return;

        if (abs(currentQuad->topLeft.x - currentQuad->botRight.x) <= 0.0001
            && abs(currentQuad->topLeft.y - currentQuad->botRight.y) <= 0.0001) {
            if (currentQuad == nullptr)
                currentQuad = new Node(
                    p,
                    Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                    Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                        (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                    true,
                    data
                    );
            return;
        }

        if ((currentQuad->topLeft.x + currentQuad->botRight.x) / 2 >= p.x) {
            // Indicates topLeftTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topLeftTree == nullptr)
                    currentQuad->topLeftTree = new Node(
                        Point(0,0),
                        Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        true,
                        0
                    );
                
                currentQuad = currentQuad->topLeftTree;
            }
            // Indicates botLeftTree
            else {
                if (currentQuad->botLeftTree == nullptr)
                    currentQuad->botLeftTree = new Node(
                        Point(0,0),
                        Point(currentQuad->topLeft.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->botRight.y),
                        true,
                        0
                    );
                currentQuad = currentQuad->botLeftTree;
            }
        }
        else {
            // Indicates topRightTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topRightTree == nullptr)
                    currentQuad->topRightTree = new Node(
                        Point(0, 0),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->topLeft.y),
                        Point(currentQuad->botRight.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        true,
                        0);
                currentQuad = currentQuad->topRightTree;
            }
            // Indicates botRightTree
            else {
                if (currentQuad->botRightTree == nullptr)
                    currentQuad->botRightTree = new Node(
                        Point(0, 0),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point(currentQuad->botRight.x, currentQuad->botRight.y),
                        true,
                        0);
                currentQuad = currentQuad->botRightTree;
            }
        }
    }
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
