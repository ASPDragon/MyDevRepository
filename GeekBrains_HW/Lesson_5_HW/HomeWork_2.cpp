#include <iostream>

void val(int *arr){
    for(int i = 0; i < 8; i++){
        arr[i] = ( i == 0 ? 1 : (arr[i-1]+3));
        std::cout << arr[i] << " ";
    }
}

int main(int argc, char *argv[])
{
    int mas[8] = {0};
    val(mas);
}
