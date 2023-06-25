#include "QuadTree.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <cmath>

float distance(Point p1, Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

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

int QuadTree::totalPoints() {
    int count = 0;

    // Contar los puntos almacenados en el nodo actual
    if (n != nullptr) {
        count++;
    }

    // Sumar los puntos de los subárboles recursivamente
    if (topLeftTree != nullptr) {
        count += topLeftTree->totalPoints();
    }
    if (topRightTree != nullptr) {
        count += topRightTree->totalPoints();
    }
    if (botLeftTree != nullptr) {
        count += botLeftTree->totalPoints();
    }
    if (botRightTree != nullptr) {
        count += botRightTree->totalPoints();
    }

    return count;
}

int QuadTree::totalNodes() {
    int count = 1;

    // Sumar los nodos de los subárboles recursivamente
    if (topLeftTree != nullptr) {
        count += topLeftTree->totalNodes();
    }
    if (topRightTree != nullptr) {
        count += topRightTree->totalNodes();
    }
    if (botLeftTree != nullptr) {
        count += botLeftTree->totalNodes();
    }
    if (botRightTree != nullptr) {
        count += botRightTree->totalNodes();
    }

    return count;
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
    if (abs(topLeft.x - botRight.x) <= 0.0001
        && abs(topLeft.y - botRight.y) <= 0.0001) {
        if (n == NULL) {
            n = node;
            puntos++;
        }
        return;
    }

    if ((topLeft.x + botRight.x) / 2 > node->pos.x) {
        // Indicates topLeftTree
        if ((topLeft.y + botRight.y) / 2 > node->pos.y) {
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
        if ((topLeft.y + botRight.y) / 2 > node->pos.y) {
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

void QuadTree::list(QuadTree* root , std::vector<NodeL*> vec){
    if (root->n != nullptr)
    {
        NodeL *nodel = new NodeL(root->n->pos, root->n->data);
        vec.push_back(nodel);
    }
    if (root->topLeftTree != nullptr)
    {
        list(root->topLeftTree, vec);
    }
    if (root->botLeftTree != nullptr)
    {
        list(root->botLeftTree, vec);
    }
    if (root->topRightTree != nullptr)
    {
        list(root->topRightTree, vec);
    }
    if (root->botRightTree != nullptr)
    {
        list(root->botRightTree, vec);
    }
}

int QuadTree::countRegion(Point p, int d) {
    // Verificar si el punto está dentro de los límites del QuadTree actual
    if (!inBoundary(p))
        return 0;

    int count = 0;

    // Si el QuadTree actual tiene nodos, contar los que están dentro de la región
    if (n != NULL) {
        if (distance(n->pos, p) <= d)
            count++;
    }

    // Recorrer los subárboles y contar los puntos en la región
    if (topLeftTree != NULL)
        count += topLeftTree->countRegion(p, d);
    if (topRightTree != NULL)
        count += topRightTree->countRegion(p, d);
    if (botLeftTree != NULL)
        count += botLeftTree->countRegion(p, d);
    if (botRightTree != NULL)
        count += botRightTree->countRegion(p, d);

    return count;
}

int QuadTree::AggregateRegion(Point p, int d) {
    // Verificar si el QuadTree está vacío
    if (n == NULL)
        return 0;

    // Calcular los límites de la región
    float minX = p.x - d;
    float maxX = p.x + d;
    float minY = p.y - d;
    float maxY = p.y + d;

    // Inicializar la suma de población
    int populationSum = 0;

    // Verificar si la región colisiona con el QuadTree actual
    if (inBoundary(Point(minX, minY), Point(maxX, maxY))) {
        // Si el QuadTree actual es un QuadTree de unidad de área,
        // agregar su población al total
        if (abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1) {
            populationSum += n->pobl;
        }
        // Si el QuadTree actual no es de unidad de área,
        // continuar agregando la población de sus sub-QuadTrees
        else {
            if (topLeftTree != NULL)
                populationSum += topLeftTree->AggregateRegion(p, d);
            if (topRightTree != NULL)
                populationSum += topRightTree->AggregateRegion(p, d);
            if (botLeftTree != NULL)
                populationSum += botLeftTree->AggregateRegion(p, d);
            if (botRightTree != NULL)
                populationSum += botRightTree->AggregateRegion(p, d);
        }
    }

    return populationSum;
}
