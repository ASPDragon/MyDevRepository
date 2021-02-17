#include <iostream>
#include <cstdarg>

namespace KISS {
    // 4
    void shift(int arr4[], int size) {
        int n, dir;
        std::cout << "Input n: ";
        std::cin >> n >> dir;
        while(n) {
            if(dir == 1){ // shift right
                int temp = arr4[0];
                for(int j = 0 ; j < size; j++){
                    arr4[j] = arr4[j + 1];
                }
                arr4[size - 1] = temp;
            } else if(dir == 0){ // shift left
                int temp = arr4[size - 1];
                for(int j = size - 1; j > 0; j--){
                    arr4[j] = arr4[j - 1];
                }
                arr4[0] = temp;
            }
            n--;
        }
    }
    // 5
    void swap1(int *arr5, int size1, ...){
        va_list list;
        int x;
        va_start(list, size1);
        for(x = 0; x < size1; x++){
            va_arg(list, int);
            if(arr5[x] == 1) {
                arr5[x] = 0;
            } else arr5[x] = 1;
        }
        va_end(list);
    }
}
