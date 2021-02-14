#include <iostream>

void swap(int &var1, int &var2){
    int t = var1;
    var1 = var2;
    var2 = t;
}

int main(int argc, char *argv[])
{
    int var1 = 1, var2 = 0, i;
    int *p1 = &var1;
    int *p2 = &var2;
    int Arr[5] = { *p1, *p2, *p2, *p1, *p2};
    swap(Arr[*p1], Arr[*p2]);

    do {
        std::cout << Arr[i] << " ";
        i++;
    }while(i <= 4);
    return 0;
}
