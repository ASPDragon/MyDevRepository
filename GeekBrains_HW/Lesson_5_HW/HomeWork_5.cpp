#include <iostream>
#include <cstdarg>

void swap1(int *arr, int size, ...);

int main(int argc, char **argv)
{
    int Arr[] = { 1, 0, 1, 0, 1, 1, 0, 1 };
    swap1(Arr, 8);
    for(int i = 0; i < 8; i++){
        std::cout << Arr[i] << " ";
    }

    return 0;
}

void swap1(int *arr, int size, ...){
    va_list n;
    int i;
    va_start(n, size);
    for(i = 0; i < size; i++){
        va_arg(n, int);
        if(arr[i] == 1) {
            arr[i] = 0;
        } else arr[i] = 1;
    }
    va_end(n);
}
