#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;
using namespace functions;


int main() {
    // ex. 1
    ofstream file1, file2;
    file1.open ("file1.txt", ios::out);
    file2.open ("file2.txt", ios::out);
    file1 << "A happy arrangement: many people prefer cats to other people, and many cats prefer people to other cats. - Mason Cooley";
    file1.close ();
    file2 << "How we behave toward cats here below determines our status in heaven. – Robert A. Heinlein";
    file2.close ();

    // ex. 2
    string filename, result;
    int count = 0;
    cout << "Input the name of the result file: " << " " << endl;
    cin >> result;
    do{
        cout << "Input the name of the file: " << " " << endl;
        cin >> filename;
        comb(filename, result);
        count++;
    } while(count < 2);

    // ex. 3
    string filename1, word;
    cout << "Input the name of the original file: " << " " << endl;
    cin >> filename1;
    cout << "Input the word you would like to find in the file: " << " " << endl;
    cin >> word;
    chkmatch(filename1, word);
}
