#include "functions.h"

void readFile(const string &filename){
    ifstream file(filename);
    if(file.is_open() && file.good() && file){

        cout << "File opened successfully: " << filename << endl << endl;

        //file format is: operation(string) hex1 hex2 do operation with hex1 and hex2
        
        string operation;
        string hex1, hex2;
        int line = 0; //FOR DEBUGGING

        while(file >> operation){
            line++; //FOR DEBUGGING

            if(operation == "NOT" || operation == "not"){
                file >> hex1;
                uint32_t num1;
                formatHex(hex1);
                cout << operation << " " << hex1 << " : ";
                if(!isValidHex(hex1)){
                    cout << "Invalid Hexadecimal Format" << endl;
                    //skip to next line
                    getline(file, operation);
                    continue;
                }

                try {
                    num1 = stoul(hex1, nullptr, 16); //convert the string to decimal value unsigned
                } catch (const std::out_of_range &err) {
                    cout << "Number out of range for 32-bit unsigned integer: "<< endl;
                    continue;
                } catch (const std::invalid_argument &err) {
                    cout << "Invalid hexadecimal number format"<< endl;
                    continue;
                }

                if(num1 > 0 && num1 <= 0xFFFFFFFF){
                    notOperation(num1);
                }else cout << "Positive operand required" << endl;
            }else {
                cout << operation;

                if(!isValidOp(operation)){
                    //skip the to next line
                    getline(file, operation);
                    formatHex(operation);
                    cout << operation << " : Unsupported Operation" << endl;
                    continue;
                }

                file >> hex1;
                getline(file, hex2);
                hex2 = hex2.substr(1, hex2.length());
                formatHex(hex1); formatHex(hex2);
                if(hex2.empty() || hex2.find_first_not_of(' ') == string::npos){
                    cout << " " << hex1 << " : Invalid Operand Count" << endl;
                    continue;
                }
                if(!isValidHex(hex1) || !isValidHex(hex2)){
                    cout << " " << hex1 << " " << hex2 << " : Invalid Hexadecimal Format" << endl;
                    continue;
                }

                /* file >> hex2; */

                cout << " " << hex1 << " " << hex2 << " : ";

                //convert the hexidecimal string to a unsigned 32 bit integer
                //16 states that the number is in base 16
                uint32_t num1, num2;
                try {
                    num1 = stoul(hex1, nullptr, 16); //stoul gives unsigned
                    num2 = stoul(hex2, nullptr, 16);
                } catch (const std::out_of_range &err) {
                    cout << "Number out of range for 32-bit unsigned integer" << endl;
                    continue;
                } catch (const std::invalid_argument &err) {
                    cout << "Invalid hexadecimal number format" << endl;
                    continue;
                }

                callOperation(operation, num1, num2);

            }

        }

        cout << endl << "END OF FILE" << endl;
        file.close();
    }else {
        cout << "Error opening file: " << filename << endl;
        exit(1); //exit with 1 to represent that the program has failed at a certain point somewhere
    }
}

void notOperation(uint32_t &num){
    cout << "0x" << hex << ~num << endl;
}
void andOperation(uint32_t &num1, uint32_t &num2){
    cout << "0x" << hex << (num1 & num2) << endl;
}
void orOperation(uint32_t &num1, uint32_t &num2){
    cout << "0x" << hex << (num1 | num2) << endl;
}
void xorOperation(uint32_t &num1, uint32_t &num2){
    cout << "0x" << hex << (num1 ^ num2) << endl;
}
void addOperation(uint32_t &num1, uint32_t &num2){
    cout << "0x" << hex << (num1 + num2) << endl;
}
void subOperation(uint32_t &num1, uint32_t &num2){
    cout << "0x" << hex << (num1 - num2) << endl;
}
void eqOperation(uint32_t &num1, uint32_t &num2){
    cout << (num1 == num2 ? "True" : "False") << endl;
}
void ltOperation(uint32_t &num1, uint32_t &num2){
    cout << (num1 < num2 ? "True" : "False") << endl;
}
void gtOperation(uint32_t &num1, uint32_t &num2){
    cout << (num1 > num2 ? "True" : "False") << endl;
}
void lslOperation(uint32_t &num1, uint32_t &numToShift){
    if(numToShift > 32){
        cout << "Shift Value Exceeds Bit Size" << endl;
        return;
    }
    cout << "0x" << hex << (num1 << numToShift) << endl;
}
void lsrOperation(uint32_t &num1, uint32_t &numToShift){
    if(numToShift > 32){
        cout << "Shift Value Exceeds Bit Size" << endl;
        return;
    }
    cout << "0x" << hex << (num1 >> numToShift) << endl;
}
bool isValidOp(const string &op){
    const string validOps[] = {"NOT", "AND", "OR", "XOR", "ADD", "SUB", "EQ", "LT", "GT", "LSL", "LSR", "not", "and", "or", "xor", "add", "sub", "eq", "lt", "gt", "lsl", "lsr"};
    for(const string &validOps : validOps){
        if(op == validOps){
            return true;
        }
    }
    return false;
}

bool callOperation(string &operation, uint32_t &num1, uint32_t &num2){
    if (operation == "ADD" || operation == "add") {
        addOperation(num1, num2);
    } else if (operation == "SUB" || operation == "sub") {
        subOperation(num1, num2);
    } else if (operation == "AND" || operation == "and") {
        andOperation(num1, num2);
    } else if (operation == "OR" || operation == "or") {
        orOperation(num1, num2);
    } else if (operation == "XOR" || operation == "xor") {
        xorOperation(num1, num2);
    } else if (operation == "EQ" || operation == "eq") {
        eqOperation(num1, num2);
    } else if (operation == "LT" || operation == "lt") {
        ltOperation(num1, num2);
    } else if (operation == "GT" || operation == "gt") {
        gtOperation(num1, num2);
    } else if (operation == "LSL" || operation == "lsl") {
        lslOperation(num1, num2);
    } else if (operation == "LSR" || operation == "lsr") {
        lsrOperation(num1, num2);
    }
    return true;
}

bool isValidHex(string &hex){
    if(hex[0] == '0' && hex[1] == 'x'){
        if(hex.length() > 10){ //hex.substr(2, hex.length()).length() > 8
            return false;
        }else return true;
    }
    return false;
}

bool formatHex(string &hex){
    hex.erase(hex.find_last_not_of(" \t\n") + 1);
    return true;
}