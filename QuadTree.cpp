#include "QuadTree.h"
#include "Node.h"
#include <iostream>
#include <vector>

QuadTree::QuadTree(bool es_negro, Point a, Point b){
    topLeft = a;
    botRight = b;
    es_negro = true;
    n = NULL;
    topLeftTree = NULL;
    topRightTree = NULL;
    botLeftTree = NULL;
    botRightTree = NULL;
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
// Inserta un nodo
void QuadTree::insert(Node* node)
{
    if (node == NULL)
        return;

    // Current quad cannot contain it
    if (!inBoundary(node->pos))
        return;

    // We are at a quad of unit area
    // We cannot subdivide this quad further
    if (abs(topLeft.x - botRight.x) <= 0.1
        && abs(topLeft.y - botRight.y) <= 0.1) {
        if (n == NULL) {
            n = node;
            puntos++;
        }
        return;
    }

    if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (topLeftTree == NULL) {
                topLeftTree = new QuadTree(
                    true,
                    Point(topLeft.x, topLeft.y),
                    Point((topLeft.x + botRight.x) / 2,
                        (topLeft.y + botRight.y) / 2));
                nodos++;
            }
            topLeftTree->insert(node);
        }

        // Indicates botLeftTree
        else {
            if (botLeftTree == NULL) {
                botLeftTree = new QuadTree(
                    true,
                    Point(topLeft.x,
                        (topLeft.y + botRight.y) / 2),
                    Point((topLeft.x + botRight.x) / 2,
                        botRight.y));
                nodos++;
            }
            botLeftTree->insert(node);
        }
    }
    else {
        // Indicates topRightTree
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
            if (topRightTree == NULL) {
                topRightTree = new QuadTree(
                    true,
                    Point((topLeft.x + botRight.x) / 2,
                        topLeft.y),
                    Point(botRight.x,
                        (topLeft.y + botRight.y) / 2));
                    nodos++;
            }
            topRightTree->insert(node);
        }

        // Indicates botRightTree
        else {
            if (botRightTree == NULL) {
                botRightTree = new QuadTree(
                    true,
                    Point((topLeft.x + botRight.x) / 2,
                        (topLeft.y + botRight.y) / 2),
                    Point(botRight.x, botRight.y));
                nodos++;
            }
            botRightTree->insert(node);
        }
    }
}

std::vector<NodeL*> QuadTree::list(QuadTree* root){
    std::vector<NodeL*> AB;
    if (root->n->pos.x == 0 && root->n->pos.y == 0)
    {
        NodeL *nodel = new NodeL(root->n->pos, root->n->data);
        AB.push_back(nodel);
    }
    if (root->topLeftTree != nullptr)
    {
        AB.insert(AB.end(), list(root->topLeftTree).begin(), list(root->topLeftTree).end());
    }
    if (root->botLeftTree != nullptr)
    {
        AB.insert(AB.end(), list(root->botLeftTree).begin(), list(root->botLeftTree).end());
    }
    if (root->topRightTree != nullptr)
    {
        AB.insert(AB.end(), list(root->topRightTree).begin(), list(root->topRightTree).end());
    }
    if (root->botRightTree != nullptr)
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
