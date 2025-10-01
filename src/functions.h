#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <algorithm>

using namespace std;

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

#endif // FUNCTIONS_H