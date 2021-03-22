#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printArr(int *arr, int size);

// 1
int calcSquareEq(int a, int b, int c, double* x1, double* x2);

// 2
int magic_func(int *arr, int size);

// 3
void asShortPrint(unsigned* arr, int size);

int main(){
// 1
    int a = 0, b = 0, c = 0, Discriminant = 0;
    double x1 = 0, x2 = 0;
    printf("Input variables a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);
    Discriminant = calcSquareEq(a, b, c, &x1, &x2);
    printf("Discriminant = %d , x1 = %lf, x2 = %lf\n", Discriminant, x1, x2);

// 2
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10, answer = 0;
    answer = magic_func(arr, size);
    printf("result is: %d\n", answer);
    if(answer == 1){
        printArr(arr, size);
    }

//3
    uint32_t arr1[10] = { 0, 1, 2, 3, 4, 65541, 65542, 65543, 65544, 65545};
    asShortPrint(arr1, size);
}

// 1
int calcSquareEq(int a, int b, int c, double* x1, double* x2){
    if((pow(b, 2) - 4 * a * c) > 0){
        *x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        *x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        return 1;
    } else if((pow(b, 2) - 4 * a * c) == 0){
        *x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        return 0;
    } else if((pow(b, 2) - 4 * a * c) < 0){
        return -1;
    }
}

// 2
int magic_func(int *arr, int size){
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 != 0){
            arr[i] *= 2;
            flag = 1;
        }
    }
    return flag;
}

//3
void asShortPrint(unsigned* arr, int size){
    printf("Yo, derp! Your array is: ");
    uint16_t *output = arr;
    for(int i = 0; i < size * 2; i++){
        printf("%d ", output[i]);
    }
}

void printArr(int *arr, int size){
    printf("Your array is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
