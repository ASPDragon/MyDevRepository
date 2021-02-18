/*
 HomeWorkC_1
 by Avdoshkin Sergei
 This Homework has been written in Qt Creator */
#include <stdio.h>

int main()
{
    //1
    char text[] = { "Hello, World!" };
    printf("the type of program is: %s\n", text); // %s is the output of the string

    //2 - the comment is above the header

    //3
    int var;
    printf("Please, input the number: ");
    scanf("%d", &var);
    int var2 = var*var;
    printf("You have input the number %d, we have multiplied it on itself, and the result is: %d\n", var, var2);

    //4
    int a, b, c;
    printf("Please, input the value of Uo: ");
    scanf("%d", &a);
    printf("Please, input the value of R1: ");
    scanf("%d", &b);
    printf("Please, input the value of R2: ");
    scanf("%d", &c);
    int d = a / (b / (c * 1.0 + b));
    printf("We applied the formulae Ui = Uo / (R1 / (R2 + R1)) and the result of Ui is: %d\n", d);
    int e, f, g;
    printf("Please, input the value of R2: ");
    scanf("%d", &e);
    printf("Please, input the value of Uo: ");
    scanf("%d", &f);
    printf("Please, input the value of Ui: ");
    scanf("%d", &g);

    int h = e * f / (g * 1.0 - f);
    printf(" We applied the formulae R1 = R2 * Uo / (Ui - Uo) and the result of R1 is : %d\n", h);
    int i, j, k;
    printf("Please, input the value of R1: ");
    scanf("%d", &i);
    printf("Please, input the value of Ui: ");
    scanf("%d", &j);
    printf("Please, input the value of Uo: ");
    scanf("%d", &k);
    int l = i * j / k * 1.0 - i;
    printf("We applied the formulae R2 = R1 * Ui / Uo - R1 and the result of R2 is: %d\n", l);
}
