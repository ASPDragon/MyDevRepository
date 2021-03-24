#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printIntArr(const int rows, const int cols, int arr[][cols])
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//1
void bubbleSort(int* arr, const int len)
{
    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < len - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                    swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 2
void reverseTPK(int *arr, const int size)
{
    double result;
    for(int i = size - 1; i >= 0; --i)
    {
        printf("%d ", arr[i]);
        result = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
        if(result > 400)
            printf("Error, the result is greater than 400: ");
        printf("%lf \n", result);
    }
}

int main()
{
    //1
    const int LEN = 3 * 3;
    int matrix[3][3] = {
        {1, 9, 2},
        {5, 7, 6},
        {4, 3, 8}
    };
    int *arrptr = &matrix[0][0];
    bubbleSort(arrptr, LEN);
    printIntArr(3, 3, matrix);

    //2
    const int SIZE = 11;
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        printf("Please, input the number: ");
        scanf("%d", &array[i]);
    }
    reverseTPK(array, SIZE);
    return 0;
}
