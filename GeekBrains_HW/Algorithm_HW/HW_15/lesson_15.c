#include "geek.h"

#define SIZE 5

// 1 I'm not sure if it is a correct way to solve this task...
int simpleHashSum(char *in)
{
    int i = 0;
    int sum = 0;
    int len = strlen(in);

    while(i < len)
    {
        sum += in[i];
        i++;
    }
    return sum;
}

// 2 some garbage outside the array
int exchange(int *money, const int size, int sum)
{
    int num = 0;
    int coins = 0;
    int shift = 0;
    int pouchSize = size * 2;
    int *pouch = (int*) calloc(sizeof(int), pouchSize);
    while (num != sum && coins < pouchSize && shift < size)
    {
        int temp = num; // temporary variable to get back if value of coins is greater than target sum   
        num += money[shift];
        if (num > sum)
        {
            shift++; // no money into the pouch: pouch overflow!
            num = temp;
        }
        else
        {
            pouch[coins] = money[shift]; // time to put some coins in the pouch!
            coins++;
        }
    }
    for (int i = 0; i < coins; ++i)
    {
        printf("%d ", *(pouch + i));
    }
    free(pouch);
}

void task1()
{
    printf("Lesson 15 HomeWork exercise 1: \n");
    char *string = {"Good evening, Vlad!\0"};
    int i = 0;
    printf("The sum of ASCII-codes in '%s' is %d! \n", string, simpleHashSum(string));
}

void task2()
{
    printf("Lesson 15 HomeWork exercise 2:\n");
    int sum = 98;
    int money[SIZE] = {50, 10, 5, 2, 1};
    printf("%d \n", exchange(money, SIZE, sum));
    int cent[SIZE] = {50, 25, 10, 5, 1};
    printf("%d \n", exchange(cent, SIZE, sum));
}

int main(const int argc, const char **argv)
{
    task1();
    task2();
    return 0;
}