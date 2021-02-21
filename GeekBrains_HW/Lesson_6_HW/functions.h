#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#endif // FUNCTIONS_H
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

namespace functions {
void comb(string filename) {
    ifstream file (filename, ifstream::binary);
            if(file) {
                file.seekg(0, file.end); // measuring the length of the file
                int len = file.tellg();
                file.seekg(0, file.beg);
                char *arr = new char[len]; // creating the array of the size j
                file.read (arr, len);
                file.close ();
                ofstream fout("file3.txt", ios::out | ios::app);
                fout.write(arr, len);
                fout.put('\n'); //
                delete [] arr;
                fout.close ();
            }
}
}
