//NOE RIOS

#include "functions.h"
using namespace std;

int main(){
    //get input filename, then look for this file and try and read it
    string filename;

    cout << "Enter filename to perform operations on: ";
    cin >> filename;
    //read the file and perform operations
    readFile(filename);

    return 0;
}