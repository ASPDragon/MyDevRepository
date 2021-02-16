#include <iostream>

void swap(int *);

int main(int argc, char **argv)
{
    int i;
    int Arr[8] = { 1, 0, 1, 0, 1, 1, 0, 1 };
    swap(Arr);
    for(int i = 0; i < 8; i++){
        std::cout << Arr[i] << " ";
    }

    return 0;
}

void swap(int *arr){
    for(int i = 0; i < 8; i++){
        if(arr[i] == 1) {
            arr[i] = 0;
        } else arr[i] = 1;
    }
}
