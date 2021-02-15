#include <iostream>

void shift(int arr[], int size);

int main(int argc, char *argv[])
{
    int Arr[] = { 17, 5, 42, 28, 56 };
    shift(Arr, 5);
    for(int i = 4; i >= 0; i-- ){
        std::cout << Arr[i] << ' ';
    }
    return 0;
}

void shift(int arr[], int size) {
    int temp = arr[size - 1];
        for(int i = size -1; i >= 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
}

