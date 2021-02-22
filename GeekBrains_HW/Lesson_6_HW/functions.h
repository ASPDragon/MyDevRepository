#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#endif // FUNCTIONS_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

namespace functions {
    // ex. 2 function
void comb(string filename, string result) {
    ifstream file (filename, ifstream::binary);
            if(file) {
                file.seekg (0, file.end); // measuring the length of the file
                int len = file.tellg();
                file.seekg(0, file.beg);
                char *arr = new char[len]; // creating the array of the size len
                file.read (arr, len);
                file.close ();
                ofstream fout(result, ios::out | ios::app);
                fout.write(arr, len);
                delete [] arr;
                fout.close ();
            }
}
    // ex. 3 function
void chkmatch(string filename1, string word) {
    string str;
    int len;
    int st;
    bool flag = false;
    ifstream our_file (filename1, ios_base::in);
            if(!our_file.is_open()) {
                cout << "Error during the opening of the file!" << endl;
            }
            else {
                while(getline(our_file, str)){
                    len = str.size();
                    for(int i = 0; i < len; i++) {
                        if(flag == true)
                        {
                            break;
                        }

                        if(word[0] == str[i]) {

                            int j=0;
                            while(str[1]) {
                                if(word[j] == str[i + j]) {
                                    st = word.size();
                                    if(j == st - 1) {
                                        flag = true;
                                        break;
                                    }
                                }
                                    else {
                                        flag = false;
                                        break;
                                    }
                                    j++;
                                }
                        }
                    }
                }
            }
                our_file.close();
                cout << flag << endl;
}
}
