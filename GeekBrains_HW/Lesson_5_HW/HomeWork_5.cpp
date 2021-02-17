#include <iostream>
#include "namespace_related.h"
#include "namespace_related2.cpp"

using namespace KISS;

int main()
{
    using std::cout;
    using std::endl;
    using IntDelegate = void(*)(int *);
    // 1
    IntDelegate f[2];
    f[0] = swap;
    f[1] = val;
    int i;
    int Arr[8] = { 1, 0, 1, 0, 1, 1, 0, 1 };
    f[0](Arr);
    for(int i = 0; i < 8; i++){
        cout << Arr[i] << " ";
    }
    cout << std::endl;

    // 2
    int mas[8] = {0};
    f[1](mas);
    cout << endl;

    // 3
    int Arr3[7] = { 1, 4, 5, 8, 2, 6, 10};
    int a, b;
    int (*fseq)(int *, int *, int *);
    fseq = equals;
    (*fseq)(&a, &b, Arr3);
    cout << endl;

    // 4
    int Arr4[] = { 17, 5, 42, 28, 56 };
    void (*fshift)(int *, int);
    fshift = shift;
    (*fshift)(Arr4, 5);
    for(int j = 0; j < 5; j++ ){
        cout << Arr4[j] << ' ';
    }
    cout << std::endl;

    // 5
    int Arr5[] = { 1, 0, 1, 0, 1, 1, 0, 1 };
    void (*fswap1)(int *, int, ...);
    fswap1 = swap1;
    (*fswap1)(Arr5, 8);
    for(int x = 0; x < 8; x++){
        cout << Arr5[x] << " ";
    }

    return 0;
}
