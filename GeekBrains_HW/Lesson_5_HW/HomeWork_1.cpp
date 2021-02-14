#include <iostream>

void swap(int &var1, int &var2){
    int t = var1;
    var1 = var2;
    var2 = t;
}

int main(int argc, char *argv[])
{
    int var1 = 1, var2 = 0, i;
    int Arr[5] = { var1, var2, var2, var1, var2 };
    swap(Arr[var1], Arr[var2]);

    do {
        std::cout << Arr[i] << " ";
        i++;
    }while(i <= 4);
    return 0;
}
