#include "functions.h"

void readFile(const string &filename){
    ifstream file(filename);
    if(file.is_open() && file.good() && file){

        cout << "File opened successfully: " << filename << endl;

        //file format is: operation(string) hex1 hex2 do operation with hex1 and hex2
        
        string operation;
        string hex1, hex2;

        while(file >> operation >> hex1 >> hex2){
            cout << "Operation: " << operation << " Hex1: " << hex1 << " Hex2: " << hex2 << endl;
        }

        cout << "END OF FILE" << endl;
        file.close();
    }else {
        cout << "Error opening file: " << filename << endl;
        exit(1); //exit with 1 to represent that the program has failed at a certain point somewhere
    }
}