#include <stdio.h>
#include <stdlib.h>

void swapInt(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fillIntRandom(int* arr, const int len, const int border)
{
    for(int i = 0; i < len; ++i)
    {
        *(arr + i) = rand() % border;
    }
}

void printIntArray(int* arr, const int size, const int offset)
{
    char format[5];
    sprintf(format, "%%%dd", offset);

    for(int i = 0; i < size; ++i)
    {
        printf(format, *(arr + i));
    }
    printf("\n");
}

void sortInserts(int* arr, int len)
{
    int temp, pos;
    for(int i = 1; i < len; ++i)
    {
        temp = arr[i];
        pos = i - 1;
        while(pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

void qs(int* arr, const int first, int last)
{
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];
    do
    {
      while(arr[i] < x) i++;
      while(arr[j] > x) j--;

      if(i <= j)
      {
          swapInt(&arr[i], &arr[j]);
          i++;
          j--;
      }
    }while(i <= j);

    if(i < last) qs(arr, i, last);
    if(j > first) qs(arr, first, j);
}

//1
void qsImprovement(int* arr, const int first, int last)
{
    int i = first;
    int j = last;
    int len = first + last;
    int k = len / 2;

    if(len < 10)
        sortInserts(arr, len);
    int med;
    if((arr[k] >= arr[i] && arr[k] <= arr[j]) || (arr[k] >= arr[j] && arr[k] <= arr[i]))
        med = arr[k];
    else if((arr[i] >= arr[k] && arr[i] <= arr[j]) || (arr[i] >= arr[j] && arr[i] <= arr[k]))
        med = arr[i];
    else if((arr[j] >= arr[i] && arr[j] <= arr[k]) || (arr[j] >= arr[k] && arr[j] <= arr[i]))
        med = arr[j];
    swapInt(&arr[k], &med);
    qs(arr, i, j);
}

//2
void bucketSort(int* arr, int len)
{
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for(int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }
    for(int digit = 1; digit < 1000000000; digit *= 10)
    {
        for(int i = 0; i < max; ++i)
        {
            int d = (arr[i] / digit) % b;
                        int counter = buckets[d][max];
                        if(arr[i] % 2 == 0)
                            buckets[d][counter] = arr[i]; // it doesn't work. I've been trying to make bucket being filled with only arr[i] % 2 == 0 elements
                        counter++;
                        buckets[d][max] = counter;

//                        buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for(int i = 0; i < b; ++i)
        {
            for(int j = 0; j < buckets[i][max]; ++j)
            {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

int main()
{
    //1
    const int SZ = 30;
    int array[SZ];
    fillIntRandom(array, SZ, 100);
    printIntArray(array, SZ, 3);
    qsImprovement(array, 0, SZ - 1);
    printIntArray(array, SZ, 3);

    //2
    const int SIZE = 12;
    int seQ[] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
    bucketSort(seQ,SIZE);
    printIntArray(seQ, SIZE, 3);
    return 0;
}
