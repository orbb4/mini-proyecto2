class Node{
public:
	Node[4] nodes;
	// par de ptos que representa los limites del cuadrante del nodo
	// cada int[2] tiene: (cord superior izquierda, cord inferior derecha)
	pair <int[2], int[2]> limites;
	string ciudad;
	int poblacion;
	bool es_negro;

};