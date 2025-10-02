//NOE RIOS

#include "functions.h"
using namespace std;

int main(){

    string filename;

    cout << "Enter filename to perform operations on: ";
    cin >> filename;

    /* cout << "Debugging: " << filename << endl; */

    readFile(filename);

    return 0;
}