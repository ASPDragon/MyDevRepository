#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 1 "Caesar's encryption"
char *caesar(char *in, int key, bool encrypt)
{
    int len = strlen(in);
    char *out = (char*) malloc(len);
    char temp;
    if (encrypt == true)
    {
        for (int i = 0; i < len; ++i)
            out[i] = in[i] + key;
    }
    else
    {
        for (int i = 0; i < len; ++i)
            out[i] = in[i] - key;
    }
    return out;
}

// 2 Shuffle encryption... hm, I dunno how to do that...
char **init2dCharArray(char **array, const int row, const int col)
{
    array = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < col; ++i)
    {
        *(array + i) = (char*) calloc(sizeof(char), col);
    }
    return array;
}

char *shuffle(char *in, int key, bool encrypt)
{
    int len = strlen(in);
    int rows = len / key;
    int step = key + 1;
    // printf("%d\n", len);
    char **out = init2dCharArray(out, key, len / key);

    if (encrypt == true)
    {
        for (int i = 0; i < len; ++i)
        {
            int currentElementRow = i / key;
            int currentElementColumn = i % key;
            for (int j = 0; j < step; ++j)
            {
                *((*(out + currentElementRow)) + currentElementColumn) = in[j + (i * step)];
                CurrentElementRow++;
            }
        }
    }
    return *out;
}

void taskOne()
{
    printf("Lesson 16 HomeWork exercise 1: \n");
    char string[] = "ThisisatopsecretmessageVlad";
    int key = 3;
    char *cryptogram = caesar(string, key, true);
    printf("%s\n", cryptogram);
    char *oops = caesar(cryptogram, key, false);
    printf("%s\n", oops);
    free(cryptogram);
    free(oops);
}

// nope, too dumb
void taskTwo()
{
    printf("Lesson 16 HomeWork exercise 2: \n");
    char string[] = "thisisasecretmessage";
    int key = 4;
    int len = strlen(string);
    char *crypto = shuffle(string, key, true);
    printf("%s\n", crypto);
    // print2dCharArray(&crypto, key, (len / key));
    char *oops = shuffle(crypto, key, false);
    printf("%s\n", oops);
}

int main(const int argc, const char **argv)
{
    taskOne();
    taskTwo();
    return 0;
}