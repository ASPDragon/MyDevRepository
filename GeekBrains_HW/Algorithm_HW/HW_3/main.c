#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
//#define SIZE_X 8
//#define SIZE_Y 8
#define SIZE_X 3
#define SIZE_Y 3

//1 decimal to binary converter
void decToBinary(int num, char* res)
{
    if(num >= 2)
        decToBinary(num / 2, res); // recursive call of function with the division of num by 2
    strcat(res, num % 2 ? "1" : "0"); // concatenation of "0" and "1" in one string
}

//2 power of a^b iter version
double expIter(double x, int ex)
{
    int i;
    double result = 1;
    if(ex > 0) // for ex value > 0 we're just mulptiplying X on itself ex-number of times
    {
        for(i = 0; i < ex; i++)
            result *= x;
    }
    else if(ex < 0) // for ex value < 0 we're dividing 1 on X ex-number of times
    {
        for(i = 0; i > ex; i--)
            result *= x;
        result = 1 / result;
    }
    else // ANY X^0 is always 1
        return result = 1;
    return result;
}

//3 power of a^b recursive version
double expRecursive(double x, int ex)
{
    if(ex > 0) // We have to recursively multiply x on the result of multiplication of X^ex-1 while ex > 0
        return x * expRecursive(x, ex - 1);
    else if(ex < 0)
        return 1 / expRecursive(x, -ex); // 1 divide on recursive call of X^-ex
    else // once again ANY X^0 is always 1
        return 1;
}

//4 Property of Exponent Even/Odd
double expEvenOdd(double x, int ex)
{
    if(ex == 0)
        return 1;
    else if(ex % 2 != 0)
        return x * expEvenOdd(x, ex - 1);
    else if(ex < 0)
        return 1 / expRecursive(x, -ex);
    else
        return expEvenOdd(pow(x, 2), ex / 2);
}

//5 Run, Your Majesty, Run
void boardGen(int** arr, int y, int x)//, int obs)
{

    /* random positions of obstacles
        srand(time(NULL));
        while(obs)
        {
         x = rand() % (SIZE_X);
         y = rand() % (SIZE_Y);
         if(*((*(board + y)) + x) != 1)
          *((*(board + y)) + x) = 1;
          obs--;
        } */
    *((*(arr + 1)) + 1) = 1;
    for(int y = 0; y < SIZE_Y; ++y)
    {
        for(int x = 0; x < SIZE_X; ++x)
        {
            printf("%d ", *((*(arr + y)) + x));
        }
        printf("\n");
    }
}

int HighWay2Freedom(int** arr, int y, int x)//, int obs)
{
    boardGen(arr, y, x);
    if(arr[y][x] == 1)
        return 0;
    else if(x == 0 && y == 0)
        return 0;
    else if(x == 0 ^ y == 0)
        return 1;
    else
        return HighWay2Freedom(arr, x, y - 1) + HighWay2Freedom(arr, x - 1, y);
}

int main()
{
    //1 decimal to binary converter(function call)
    int number;
    char binary[256] = "";
    char output[256];
    printf("Please, input the number: ");
    scanf("%d", &number);
    decToBinary(number, binary);
    sprintf(output,"The binary equivalent of your decimal number %d is: 0b%08s\n", number, binary);
    puts(output);

    //2 power of a^b(function call) iter version
    double base;
    int power;
    printf("Please, input the number you wish to raise to the power: ");
    scanf("%lf", &base);
    printf("Please, input the value of power: ");
    scanf("%d", &power);
    printf("The result of the raising to the power of %3.0lf is: %3.5lf\n", base, expIter(base, power));

    //3 power of a^b(function call) recursive version
    double base2;
    int power2;
    printf("Please, input the number you wish to raise to the power: ");
    scanf("%lf", &base2);
    printf("Please, input the value of power: ");
    scanf("%d", &power2);
    printf("The result of the raising to the power of %3.0lf is: %3.5lf\n", base2, expRecursive(base2, power2));

    //4 Property of Exponent Even/Odd (function call)
    double base3;
    int power3;
    printf("Please, input the number you wish to raise to the power: ");
    scanf("%lf", &base3);
    printf("Please, input the value of power: ");
    scanf("%d", &power3);
    printf("The result of the raising to the power of %3.0lf is: %3.3lf\n", base3, expEvenOdd(base3, power3));

    //5 Run, Your Majesty, Run (function call)
    int obstacles = 1;
    /* user input of value obstacles:
        printf("Input the number of obstacles: ");
        scanf("%d", &obstacles); */
    int** board = (int**) calloc(SIZE_Y, sizeof(int*));
    for(int y = 0; y < SIZE_Y; ++y)
    {
        *(board + y) = (int*) calloc(SIZE_X, sizeof(int));
    }
    for(int y = 0; y < SIZE_Y; ++y)
    {
        for(int x = 0; x < SIZE_X; ++x)
        {
            printf("%d ", HighWay2Freedom(board, SIZE_Y, SIZE_X));
        }
        printf("\n");
    }
    free(board);
    return 0;
}
