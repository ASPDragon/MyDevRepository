#define SIZE 20
#define POW2(X) pow((X), 2)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1
void decToBinary(int num, char* res)
{
    if(num >= 2)
    {
        decToBinary(num / 2, res);
    }
    strcat(res, (num % 2 ? "1" : "0"));
}

//2
typedef struct rectangle
{
    int length;
    int width;
    int perimeter;
    int surface;
}Rectangle;

void rectangleParamCalc(Rectangle *r)
{
    r->perimeter = (r->length + r->width) * 2;
    r->surface = r->length * r->width;
}

//3
typedef struct line
{
    float lng;
}someLine;

typedef struct points
{
    int x1, y1;
    int x2, y2;
}somePoints;

void lineLeng(someLine *line, somePoints *points)
{
    line->lng = sqrt(POW2(points->x2 - points->x1) + POW2(points->y2 - points->y1));
}

//4
void arrCreationism(int **arr, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            *((*(arr + i)) + j) = 1;
            printf("%d ", *((*(arr + i)) + j));
        }
    }
}

int main()
{
    //1
    int num;
    char binary[256] = "";
    printf("Input the number: ");
    scanf("%d", &num);
    decToBinary(num, binary);
    printf("Binary number is: %s\n", binary);

    //2
    Rectangle rec;
    printf("Input the length and the width of the rectangle: ");
    scanf("%d %d", &rec.length, &rec.width);
    printf("The parameters of rectangle is %d and %d\n", rec.length, rec.width);
    rectangleParamCalc(&rec);
    printf("The perimeter of the rectangle is %d, the surface of it is %d\n", rec.perimeter, rec.surface);

    //3
    someLine ln;
    somePoints pt;
    struct points p;
    printf("Input the coordinates of point 1(x, y): ");
    scanf("%d %d", &pt.x1, &pt.y1);
    printf("Input the coordinates of point 2(x, y): ");
    scanf("%d %d", &pt.x2, &pt.y2);
    lineLeng(&ln, &pt);
    printf("the length of the line between point 1 and point 2 is: %3.1f\n", ln.lng);

    //4
    int rows = 4;
    int cols = 5;
    int** array = (int**) calloc(rows, sizeof(int*));
    for(int i = 0; i < rows; i++)
    {
        *(array + i) = (int*) calloc(cols, sizeof(int));
    }
    arrCreationism(array, rows, cols);
    return 0;
}
