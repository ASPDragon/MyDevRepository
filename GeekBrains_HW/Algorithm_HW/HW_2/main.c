#include <stdio.h>

int isPrime(int number)
{
    int d = 0;
    int i = 1;
    while(i <= number)
    {
        if(number % i++ == 0)
        {
            d++;
        }
        else
        {
            continue;
        }
        if(d == 3)
        {
            return 0;
        }
    }
    return (d == 2);
}

int main()
{
    int number;
    printf("Input the number: ");
    scanf("%d", &number);
    printf("The number %d you have input is %sprime\n", number, isPrime(number) ? "" : "not ");
}
