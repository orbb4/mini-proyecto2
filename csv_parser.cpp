#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <cstring>  
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

