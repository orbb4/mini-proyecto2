#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility> // std::pair
#include <sstream> // std::stringstream
#include <cstring>  
#include "Node.h"
#include "Ciudad.h"
using namespace std;

// funcion auxiliar para split_csv, devuelve un numero como entero quitando la coma decimal y manteniendo los decimales
int str_to_int(string w){
    int num;
    
    string str_num = "";
    int integral_counter = 0;
    int decimal_counter = 0;
    bool decimal_part=false;
    
    for(char c: w){
        if(c != '.' && c!= ','){
            decimal_counter++;
            str_num +=c;
            if(decimal_part){
                decimal_counter++;
                if(decimal_counter>=3){
                    break;
                }
            }
        }else{
            decimal_part=true;
        }
    }

    try {
        num = stoi(str_num);
    } catch (const std::invalid_argument& e) {
        cout<<w<<" es un argumento invalido"<<endl;
        return -1;
    }
    
    return num;
}

// deja intactos numeros de a lo mas 3 digitos, caso contrario pone un punto decimal 
// despues del tercer digito (ej 123 queda intacto, 1234 queda 123.4)
float format_int(int n){
    string n_str = to_string(n);
    if(n_str.length() > 3){
        n_str.insert(3, 1, '.');
    }
    return stof(n_str);
}

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
    else{
        cout<<"No se pudo acceder al csv.\n";
    }
    return content;

}

bool cord_match(string csv_latitude, string csv_longitude, int x, int y){
    float margen_de_error = 0.5;
    replace(csv_latitude.begin(), csv_latitude.end(), ',', '.');
    replace(csv_longitude.begin(), csv_longitude.end(), ',', '.');
    float latitude = stof(csv_latitude);
    float longitude = stof(csv_longitude);
    cout<<format_int(x)<<" "<<format_int(y)<<endl;
    bool match = (abs(latitude - format_int(x) ) < margen_de_error) && (abs(longitude- format_int(y) ) < margen_de_error);
    cout<<"format int: "<<format_int(x)<<" "<< format_int(y)<<endl;

    cout<<latitude<<", "<<longitude<<endl;
    return match;

}


bool collision(std::vector<int[2]> pts, int x, int y){
    for(int i = 0; i < pts.size(); i++){
        if(pts.at(i)[0] == x && pts.at(i)[1] == y){
            return true;
        }
    }
    return false;
}


Ciudad *get_city(vector<vector<string>> csv, Point p){
    Ciudad *city = new Ciudad();
    int factor = 1000;
    //int collision_counter = 0;
    std::vector<Point> pts;
    for(int i = 1; i < csv.size(); i++){
        //std::cout<<str_to_int(csv_latitude)<<" "<<str_to_int(csv_longitude)<<csv.at(i).at(1)<<std::endl;
        //bool collides = collision(pts, str_to_int(csv_latitude), str_to_int(csv_longitude));
        /*if(collides){
            collision_counter++;
        }*/
        //pts.push_back({{str_to_int(csv_latitude), str_to_int(csv_longitude)}});
        if(cord_match(csv.at(i).at(5), csv.at(i).at(6), p.x, p.y)){  
            city->Country = csv.at(i).at(0);
            city->City = csv.at(i).at(1);
            city->AccentCity = csv.at(i).at(2);
            city->region = csv.at(i).at(3);
            city->Population = str_to_int(csv.at(i).at(4));
            city->Latitude = str_to_int(csv.at(i).at(5));
            city->Longitude = str_to_int(csv.at(i).at(6));

            return city;
        }
    }
    std::cout<<"ciudad no encontrada"<<std::endl;
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
    p.x = 40.5;  
    p.y = 50;
    get_city(cities, p);
    //cout<<cord_match("123,0005", "123,0005", 123, 123);
    return 0;
}
*/
