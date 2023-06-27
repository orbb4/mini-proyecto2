#include <iostream>
#include <chrono>
#include "QuadTree.h"
#include "csv_parser.h"
using namespace std;
using namespace std::chrono;

int main() {
    // Preparación para experimentación
    int num_of_cities = 800000;
    vector<Node> nodes;
    vector<vector<string>> cities = split_csv("worldcitiespop_fixed.csv");
    
    // Nos saltamos la primera línea (no contiene datos de ciudades)
    for (int i = 1; i < num_of_cities + 1; i++) {
		size_t aux;
        float y = stof(cities.at(i).at(7),&aux);
        float x = stof(cities.at(i).at(7).substr(aux +1, string::npos));
        int population = stoi(cities.at(i).at(4));
        Node new_node(Point(x, y), population);
        nodes.push_back(new_node);
    }

    // Experimentación
    int num_attempts = 20;
    std::chrono::duration<double> avg_secs;
	avg_secs = std::chrono::seconds::zero();

    for (int j = 0; j < num_attempts; j++) {
		QuadTree plane2D(true, Point(-180,-90), Point(180,90));
        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < num_of_cities; i++) {
            plane2D.insert(&nodes.at(i));
        }

  		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_in_secs = end-start;
		std::cout <<"Experimento "<< j <<": "<< time_in_secs.count() << "segundos" << std::endl;
		avg_secs+=time_in_secs;
        
    }
    avg_secs/=num_attempts;
	std::cout<<"Tiempo promedio: "<< avg_secs.count() << "s" << std::endl;
    
    return 0;
}