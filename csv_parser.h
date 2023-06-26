#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>
#include "Node.h"
#include "Ciudad.h"

int str_to_int(std::string w);
float format_int(int n);
std::vector<std::vector<std::string>> split_csv(std::string fileName);
bool cord_match(std::string csv_latitude, std::string csv_longitude, int x, int y);
Ciudad* get_city(std::vector<std::vector<std::string>> csv, Point p);
void print_city_data(std::vector<std::vector<std::string>> csv, std::string city_name);

#endif // CSV_PARSER_H