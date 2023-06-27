#include <iostream>
#include <chrono>
#include <array>
#include <utility>
#include "QuadTree.h"
#include "csv_parser.h"
using namespace std;
using namespace std::chrono;

int main() {
	// Preparación para experimentación
	int num_of_cities;
	cout << "Ingrese la cantidad de ciudades a insertar: ";
	cin >> num_of_cities;
	vector<Node> nodes;
	vector<vector<string>> cities = split_csv("worldcitiespop_fixed.csv");

	// Nos saltamos la primera línea (no contiene datos de ciudades)
	for (int i = 1; i < num_of_cities + 1; i++) {
		size_t aux;
		float y = stof(cities.at(i).at(7), &aux);
		float x = stof(cities.at(i).at(7).substr(aux + 1, string::npos));
		int population = stoi(cities.at(i).at(4));
		Node new_node(Point(x, y), population);
		nodes.push_back(new_node);
	}

	///////////////////////////////////////// Experimentación//////////////////////////////////////////////////////////
	const int num_attempts = 20;

	/* valores para insert */
	// cantidades de insert medidas
	array<int, 5> insrt_values = { num_of_cities/16, num_of_cities/8, num_of_cities/4, num_of_cities/2, num_of_cities };
	// tiempos
	std::chrono::duration<double> insrt_total_time[insrt_values.size()];
	for (int i = 0; i < insrt_values.size(); i++)
		insrt_total_time[i] = std::chrono::seconds::zero();



	/* valores para count/aggregate Region */
	// regiones
	array<pair<Point,int>, 5> region_values;
	region_values[0] = pair<Point,int>(Point(123.456,10),2);
	region_values[1] = pair<Point,int>(Point(-180,-90),10);
	region_values[2] = pair<Point,int>(Point(0,-30),60);
	region_values[3] = pair<Point,int>(Point(-100,-80),120);
	region_values[4] = pair<Point,int>(Point(-180,-90),360);
	// resultados
	array<int,5> count_region_resultados;
	array<int,5> aggregate_region_resultados;
	// tiempos
	std::chrono::duration<double> count_region_total_time[region_values.size()];
	std::chrono::duration<double> aggregate_region_total_time[region_values.size()];
	for (int i = 0; i < region_values.size(); i++) {
		count_region_total_time[i] = std::chrono::seconds::zero();
		aggregate_region_total_time[i] = std::chrono::seconds::zero();
	}




	// experimentando num_attempts veces
	for (int l = 0; l < num_attempts; l++) {

		QuadTree plane2D(true, Point(-180, -90), Point(180, 90));
		auto time_strt = steady_clock::now();

		// experimentacion insert
		int inicio = 0;
		for (int j = 0; j < 5; j++) {
			
			for (int i = inicio; i < insrt_values[j]; i++) {
				plane2D.insert(&nodes.at(i));
			}
			
			auto time = chrono::steady_clock::now() - time_strt;
			insrt_total_time[j] += time;
			inicio = insrt_values[j];
		}

		// experimentacion countRegion
		for (int i = 0; i < region_values.size(); i++) {
			time_strt = steady_clock::now();

			count_region_resultados[i] = plane2D.countRegion(region_values[i].first,region_values[i].second);

			auto time = chrono::steady_clock::now() - time_strt;
			count_region_total_time[i] += time;
		}

		// experimentacion aggregateRegion
		for (int i = 0; i < region_values.size(); i++) {
			time_strt = steady_clock::now();

			aggregate_region_resultados[i] = plane2D.aggregateRegion(region_values[i].first,region_values[i].second);

			auto time = chrono::steady_clock::now() - time_strt;
			aggregate_region_total_time[i] += time;
		}
	}

	// Imprimiendo resultados insert
	cout << "cantidad de experimentos promediados en cada prueba: " << num_attempts << "\n\n";
	for (int i = 0; i < insrt_values.size(); i++)	{
		cout << "tiempo promedio para los primeros " << insrt_values[i] << " inserts: " << (insrt_total_time[i]/num_attempts).count() << "\n";
	}
	cout << "\n";

	// Imprimiendo resultados countRegion
	for (int i = 0; i < region_values.size(); i++)	{
		cout << "tiempo promedio para countRegion con centro en (" << region_values[i].first.x << "," << region_values[i].first.y << ") y radio " << region_values[i].second << ": " << (count_region_total_time[i]/num_attempts).count() << "\n";
	}

	// Imprimiendo resultados aggregateRegion
	for (int i = 0; i < region_values.size(); i++)	{
		cout << "tiempo promedio para aggregateRegion con centro en (" << region_values[i].first.x << "," << region_values[i].first.y << ") y radio " << region_values[i].second << ": " << (aggregate_region_total_time[i]/num_attempts).count() << "\n";
	}

	return 0;
}