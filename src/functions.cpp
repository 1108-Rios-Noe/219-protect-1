#include "functions.h"

void readFile(const string &filename){
    ifstream file(filename);
    if(file.is_open() && file.good() && file){

        cout << "File opened successfully: " << filename << endl;

        //file format is: operation(string) hex1 hex2 do operation with hex1 and hex2
        
        string operation;
        string hex1, hex2;
        int line = 0; //FOR DEBUGGING

        while(file >> operation){
            line++; //FOR DEBUGGING

            if(operation == "NOT" || operation == "not"){
                file >> hex1;
            }else {

            }
            

            file >> hex1 >> hex2;
            uint32_t num1 = stoi(hex1, nullptr, 16);
            uint32_t num2 = stoi(hex2, nullptr, 16);

            //FOR DEBUGGING
            cout << "Line: " << line << " Operation: " << operation << " Hex1: " << hex1 << " Hex2: " << hex2 << endl;
            cout << "Num1: " << num1 << " Num2: " << num2 << " ADD: " << num1 + num2 << " Hex: 0x" << hex << num1+num2 << endl;

        }

        cout << "END OF FILE" << endl;
        file.close();
    }else {
        cout << "Error opening file: " << filename << endl;
        exit(1); //exit with 1 to represent that the program has failed at a certain point somewhere
    }
}

void notOperation(uint32_t &num){

}
void andOperation(uint32_t &num1, uint32_t &num2){

}
void orOperation(uint32_t &num1, uint32_t &num2){

}
void xorOperation(uint32_t &num1, uint32_t &num2){

}
void addOperation(uint32_t &num1, uint32_t &num2){

}
void subOperation(uint32_t &num1, uint32_t &num2){

}
void eqOperation(uint32_t &num1, uint32_t &num2){

}
void ltOperation(uint32_t &num1, uint32_t &num2){

}
void gtOperation(uint32_t &num1, uint32_t &num2){

}
void lslOperation(uint32_t &num1, uint32_t &numToShift){

}
void lsrOperation(uint32_t &num1, uint32_t &numToShift){

}
bool isValidOp(const string &op){
    const string validOps[] = {"NOT", "AND", "OR", "XOR", "ADD", "SUB", "EQ", "LT", "GT", "LSL", "LSR", "not", "and", "or", "xor", "add", "sub", "eq", "lt", "gt", "lsl", "lsr"};
    
}