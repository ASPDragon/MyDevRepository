#include <iostream>

int equals(int *a, int *b, int *arr);

int main(int argc, char *argv[])
{
    int Arr[7] = { 1, 4, 5, 8, 2, 6, 10};
    int a, b;
    equals(&a, &b, Arr);
}

int equals(int *a, int *b, int *arr){
    using std::cout;
    using std::endl;

    *a = arr[0] + arr[1] + arr[2] + arr[3];
    *b = arr[4] + arr[5] + arr[6];
    if((*a) == (*b)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

}
