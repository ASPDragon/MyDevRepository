#define CHKFIT(X,Y) (((X)  >= 0 ) && ((X)  < ( Y)))
#define DEREF(I,J, ARR) (*((*((ARR) + (I))) + (J)))
#define LENGTH(ARR, TYPE) ((sizeof(ARR))/(sizeof(TYPE)))
#include <iostream>

using namespace std;

int main()
{
    // ex.1
    int x, y;
    cout << "x= ";
    cin >> x;
    cout << "y= ";
    cin >> y;
    cout << CHKFIT(x,y) << endl;

    // ex. 2
    int i, j;
    cout << "i= ";
    cin >> i;
    cout << "j= ";
    cin >> j;

    int **arr = new int*[4];
    arr[0] = new int[4] { 1, 2, 3, 4};
    arr[1] = new int[4] { 5, 6, 7, 8};
    arr[2] = new int[4] { 9, 10, 11, 12};
    arr[3] = new int[4] { 13, 14, 15, 16};

    cout << DEREF(i,j, arr) << endl;

    for(i = 0; i < 5; ++i){
        delete [] arr[i];
    }
    delete [] arr;

    //3
    char c[25] = { "Good afternoon, Semyon!"};
    cout << LENGTH(c, char) << endl;
}
