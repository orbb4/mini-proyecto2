#include "QuadTree.h"
#include "Node.h"
#include <iostream>
#include <vector>

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
            if (currentQuad == nullptr) {
                currentQuad = new Node(
                    p,
                    Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                    Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                        (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                    true,
                    data
                );
                puntos++;
            }
            return;
        }

        if ((currentQuad->topLeft.x + currentQuad->botRight.x) / 2 >= p.x) {
            // Indicates topLeftTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topLeftTree == nullptr) {
                    currentQuad->topLeftTree = new Node(
                        Point(0, 0),
                        Point(currentQuad->topLeft.x, currentQuad->topLeft.y),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        true,
                        0
                    );
                    nodos++;
                }
                currentQuad = currentQuad->topLeftTree;
            }
            // Indicates botLeftTree
            else {
                if (currentQuad->botLeftTree == nullptr) {
                    currentQuad->botLeftTree = new Node(
                        Point(0, 0),
                        Point(currentQuad->topLeft.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->botRight.y),
                        true,
                        0
                    );
                    nodos++;
                }
                currentQuad = currentQuad->botLeftTree;
            }
        }
        else {
            // Indicates topRightTree
            if ((currentQuad->topLeft.y + currentQuad->botRight.y) / 2 >= p.y) {
                if (currentQuad->topRightTree == nullptr) {
                    currentQuad->topRightTree = new Node(
                        Point(0, 0),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            currentQuad->topLeft.y),
                        Point(currentQuad->botRight.x,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        true,
                        0);
                    nodos++;
                }
                currentQuad = currentQuad->topRightTree;
            }
            // Indicates botRightTree
            else {
                if (currentQuad->botRightTree == nullptr) {
                    currentQuad->botRightTree = new Node(
                        Point(0, 0),
                        Point((currentQuad->topLeft.x + currentQuad->botRight.x) / 2,
                            (currentQuad->topLeft.y + currentQuad->botRight.y) / 2),
                        Point(currentQuad->botRight.x, currentQuad->botRight.y),
                        true,
                        0);
                    nodos++;
                }
                currentQuad = currentQuad->botRightTree;
            }
        }
    }
}

std::vector<NodeL*> QuadTree::list(Node* root){
    std::vector<NodeL*> AB;
    if (root->cords.x == 0 && root->cords.y == 0)
    {
        NodeL *nodel = new NodeL(root->cords, root->data);
        AB.push_back(nodel);
    }
    if (root->topLeftTree != nullptr && root->topLeftTree->es_negro)
    {
        AB.insert(AB.end(), list(root->topLeftTree).begin(), list(root->topLeftTree).end());
    }
    if (root->botLeftTree != nullptr && root->botLeftTree->es_negro)
    {
        AB.insert(AB.end(), list(root->botLeftTree).begin(), list(root->botLeftTree).end());
    }
    if (root->topRightTree != nullptr && root->topRightTree->es_negro)
    {
        AB.insert(AB.end(), list(root->topRightTree).begin(), list(root->topRightTree).end());
    }
    if (root->botRightTree != nullptr && root->botRightTree->es_negro)
    {
        AB.insert(AB.end(), list(root->botRightTree).begin(), list(root->botRightTree).end());
    }
	return AB;
}

int QuadTree::countRegion(Point p, int d){
	return 1;
}

int QuadTree::AggregateRegion(Point p, int d){
	return 1;
}
