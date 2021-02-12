#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // 1
    int a, b;
    a = 10;
    b = 12;
    if ((a + b >= 10) && (a + b <= 20)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    } 

    // 2
	if(num = 2) {
		cout << num << " is a simple number!" << endl;
	}
    for(int num = 3 ; num <= 25 ; num+= 2 ) {
        if(num % (num-1) != 0) {
            cout << num << " is a simple number!" << endl;
        } else if (num % num == 0) {
            cout << num << " is a simple number!" << endl;
        } else if (num % 1 == 0) {
            cout << num << " is a simple number!" << endl;
        }
        else {
            cout << num << " is not a simple number" << endl;
        }
    }

    //3
    int val1, val2;
    val1 = 3;
    val2 = 7;
    if ((val1+val2 == 10) || (val1 == 10)) {
        cout << "true" << endl;
    }

    //4
    long Year;
    for (Year > 0; Year <= 2021 ; Year++) {
        if(Year % 400 == 0) {
            cout << Year << " is a leapy year!" << endl;
        } else if(Year % 100 == 0) {
            cout << Year << " is a century!" << endl;
        } else if(Year % 4 == 0) {
            cout << Year << " is a leapy year!" << endl;
        } else if(Year % 4 != 0) {
            cout << Year << " is not a leapy year" << endl;
        }
    }; 
    return 0;
}

