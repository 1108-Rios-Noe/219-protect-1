#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <algorithm>

using namespace std;

//all the function prototypes that help perform the operations and become a dynamic project
void readFile(const string &filename);
void notOperation(uint32_t &num);
void andOperation(uint32_t &num1, uint32_t &num2);
void orOperation(uint32_t &num1, uint32_t &num2);
void xorOperation(uint32_t &num1, uint32_t &num2);
void addOperation(uint32_t &num1, uint32_t &num2);
void subOperation(uint32_t &num1, uint32_t &num2);
void eqOperation(uint32_t &num1, uint32_t &num2);
void ltOperation(uint32_t &num1, uint32_t &num2);
void gtOperation(uint32_t &num1, uint32_t &num2);
void lslOperation(uint32_t &num1, uint32_t &numToShift);
void lsrOperation(uint32_t &num1, uint32_t &numToShift);
bool isValidOp(const string &op);
bool callOperation(string &operation, uint32_t &num1, uint32_t &num2);
bool isValidHex(string &hex);
bool formatHex(string &hex);

#endif // FUNCTIONS_H