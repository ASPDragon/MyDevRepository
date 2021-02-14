#include <iostream>

int equals(int *a, int *b);

int main(int argc, char *argv[])
{
    int Arr[7] = { 1, 4, 5, 8, 2, 6, 10};
    int a, b;
    equals(&a, &b);
}

int equals(int *a, int *b){
    int Arr[7];
    *a = Arr[0] + Arr[1] + Arr[2] + Arr[3];
    *b = Arr[4] + Arr[5] + Arr[6];
    if((*a) == (*b)){
        std::cout << "true";
    }
    else {
        std::cout << "false";
    }

}
