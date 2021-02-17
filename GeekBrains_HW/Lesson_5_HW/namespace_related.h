#include <iostream>
#ifndef NAMESPACE_RELATED_H
#define NAMESPACE_RELATED_H

#endif // NAMESPACE_RELATED_H

namespace KISS {
    // 1
    void swap(int *arr){
        for(int i = 0; i < 8; i++){
            if(arr[i] == 1) {
                arr[i] = 0;
            } else arr[i] = 1;
        }
    }

    // 2
    void val(int *arr2){
        for(int y = 0; y < 8; y++){
            arr2[y] = ( y == 0 ? 1 : (arr2[y-1]+3));
            std::cout << arr2[y] << " ";
        }
    }

    // 3
    int equals(int *a, int *b, int *arr3){
        using std::cout;
        using std::endl;

        *a = arr3[0] + arr3[1] + arr3[2] + arr3[3];
        *b = arr3[4] + arr3[5] + arr3[6];
        if((*a) == (*b)){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}
