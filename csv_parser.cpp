#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <cstring>  
#include "Node.h"
#include "Ciudad.h"
using namespace std;


// devuelve un vector con vectores que contienen los datos de cada linea del csv
// se puede obtener un dato en (row, column) con: parsed_csv.at(column).at(row)
vector<vector<string>> split_csv(string fileName){
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    fstream file (fileName, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
 
            stringstream str(line);
 
            while(getline(str, word, ';'))
                
                row.push_back(word); 
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    return content;

}

Ciudad *get_city(vector<vector<string>> csv, Point p){
    Ciudad *city = new Ciudad();

    for(int i = 1; i < csv.size(); i++){
        std::cout<<std::stoi(csv.at(i).at(5))<<" "<<std::stoi(csv.at(i).at(6))<<std::endl;
        if(std::stoi(csv.at(i).at(5))== p.x && std::stoi(csv.at(i).at(6)) == p.y){         
            city->City = csv.at(i).at(1);
            city->AccentCity = csv.at(i).at(2);
            std::cout<<city->City<<std::endl;
            return city;
        }
    }
    std::cout<<":("<<std::endl;
    return city;
}


void print_city_data(vector<vector<string>> csv, string city_name){
    for(int i = 0; i < csv.size(); i++){
        if(csv.at(i).at(1)==city_name){
            for(int j = 0; j < csv.at(i).size(); j++){
                cout<<csv.at(i).at(j)<<endl;
            }
        }
    }
}

/*
int main(){
    vector<vector<string>> cities = split_csv("worldcitiespop_fixed.csv");
    //print_city_data(cities, "mulchen");
    struct Point p;
    p.x = -15; 
    p.y = 20;
    get_city(cities, p);
    return 0;
}*/
