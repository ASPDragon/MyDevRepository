#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
using namespace functions;


int main() {
    // 1
    ofstream file1, file2;
    file1.open ("file1.txt", ios::out);
    file2.open ("file2.txt", ios::out);
    file1 << "A happy arrangement: many people prefer cats to other people, and many cats prefer people to other cats. - Mason Cooley";
    file1.close ();
    file2 << "How we behave toward cats here below determines our status in heaven. – Robert A. Heinlein";
    file2.close ();

    // 2
    string filename;
    int count = 0;
    do{
        cout << "Input the name of the file: " << " " << endl;
        cin >> filename;
        comb(filename);
        count++;
    } while(count < 2);
}
