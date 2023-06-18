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

bool QuadTree::inBoundary(Point p)
{
    return (p.x >= topLeft.x && p.x <= botRight.x
        && p.y >= topLeft.y && p.y <= botRight.y);
}

void QuadTree::insert(Point p) {
    Node* node = new Node(p);

    if (node == nullptr)
        return;

    QuadTree* currentQuad = this;

    while (currentQuad != nullptr) {
        if (!currentQuad->inBoundary(node->pos))
            return;

        if (abs(currentQuad->topLeft.x - currentQuad->botRight.x) <= 0.0001
            && abs(currentQuad->topLeft.y - currentQuad->botRight.y) <= 0.0001) {
            if (currentQuad->n == nullptr)
                currentQuad->n = node;
            return;
        }

        if ((currentQuad->topLeft.x + currentQuad->botRight.x) / 2 >= node->pos.x) {
            // Indicates topLeftTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= node->pos.y) {
                if (currentQuad->topLeftTree == nullptr)
                    currentQuad->topLeftTree = new Quad(
                        Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2));
                currentQuad = currentQuad->topLeftTree;
            }
            // Indicates botLeftTree
            else {
                if (currentQuad->botLeftTree == nullptr)
                    currentQuad->botLeftTree = new Quad(
                        Point(currentQuad->topLeft.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->botRight.y));
                currentQuad = currentQuad->botLeftTree;
            }
        }
        else {
            // Indicates topRightTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= node->pos.y) {
                if (currentQuad->topRightTree == nullptr)
                    currentQuad->topRightTree = new Quad(
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->topLeft.y),
                        Point(currentQuad->botRight.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2));
                currentQuad = currentQuad->topRightTree;
            }
            // Indicates botRightTree
            else {
                if (currentQuad->botRightTree == nullptr)
                    currentQuad->botRightTree = new Quad(
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point(currentQuad->botRight.x, currentQuad->botRight.y));
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

int main(){
	return 0;
}

