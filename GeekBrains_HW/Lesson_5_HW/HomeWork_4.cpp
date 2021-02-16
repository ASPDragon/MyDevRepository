#include <iostream>

void shift(int arr[], int size);

int main(int argc, char *argv[])
{
    int Arr[] = { 17, 5, 42, 28, 56 };
    shift(Arr, 5);
    for(int i = 0; i < 5; i++ ){
        std::cout << Arr[i] << ' ';
    }
    return 0;
}

void shift(int arr[], int size) {
    int n, dir;
    std::cout << "Input n: ";
    std::cin >> n >> dir;
    while(n) {
        if(dir == 1){ // shift right
            int temp = arr[0];
            for(int i = 0 ; i < size; i++){
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = temp;
        } else if(dir == 0){ // shift left
            int temp = arr[size - 1];
            for(int i = size - 1; i > 0; i--){
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
        n--;
    }
}
