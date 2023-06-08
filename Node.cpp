#include "Node.h"

Node::Node(pair <int[2], int[2]> limites, string ciudad, int poblacion, bool es_negro){
	this.limites=limites;
	this.ciudad=ciudad;
	this.poblacion=poblacion;
	this.es_negro=es_negro;
}