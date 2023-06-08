#include "Node.h"

class QuadTree {
private:

public:

	Node *root;

	QuadTree(Point, Point);
	~QuadTree();

	int totalPoints(); // Retorna la cantidad de puntos almacenados en el QuadTree
	int totalNodes(); // Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
	void insert(Point p, int data); // Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la información disponible en data (ej. la población de una ciudad con coordenadas p).
	void list(); // Retorna un contenedor con todos los puntos almacenados en el QuadTree. Por cada punto retorna sus coordenadas y su valor asociado (ej. la población). Para esta función, queda a criterio de los estudiantes elegir un recorrido entre preorder, postorder o una variante de inorder. El tipo de retorno dependerá del tipo de contenedor que se utilice.
	int countRegion(Point p, int d); // Retorna la cantidad de puntos en una región del plano, tomando como centro el punto p y una distancia d.
	int AggregateRegion(Point p, int d); // Retorna la población estimada dentro de una región del plano, tomando como centro el punto p y una distancia d.
};
