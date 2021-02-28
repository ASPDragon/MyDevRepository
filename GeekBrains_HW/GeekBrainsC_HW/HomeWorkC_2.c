#include <stdio.h>
#include <string.h>

int main()
{
    // ex 1
    int i = 0;
    printf("input the number: ");
    scanf("%d", &i);
    printf("the result of the check is %d\n", (((i >= 0) && (i <= 100)) ? 1 : 0));

    // ex 2
    float sum = 0;
    int j = 0, answer = 0;

    do{
        j++;
        printf("Input the number: ");
        scanf("%d", &answer);
        sum = (float)sum + answer;
    } while(j < 10);
    printf("The arithmetical mean of numbers is: %f\n", sum/j);

    // ex 3
    int number = 0;

    do{
        printf("Input the number: ");
        scanf("%d", &number);
    } while(!(number > 0 && number <= 1000));

    for(int y = 0; y <= number; y++){
        if(y % 2 == 0){
            printf("%d, ", y);
        }
    }

    // ex 4
    int rows = 0;
    printf("Input the number of rows: ");
    scanf("%d", &rows);
    for(int row = 0; row < rows; row++, printf("\n")) {
        for(int emp = (rows - row) - 1; emp > 0; --emp, printf(" "));
        for(int columns = ((2 * row) + 1); columns > 0; --columns, printf("^"));
    }
}
