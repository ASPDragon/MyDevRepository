#include "geek_c/geek.h"

void clearVisited(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
}


void widthTravers(int **matrix, int start, const int size)
{
    TwoLinkList *queue = (TwoLinkList*) malloc(sizeof(TwoLinkList)); // the algorithm is based on 2-linked list.
    initTwoLinkList(queue); // set
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while(queue->size > 0)
    {
        int index = TwoLinkDequeue(queue);
        if(visited[index] == 1) continue;
        visited[index] = 1;
        printf("%d ", index);
        for(int i = 0; i < size; ++i)
        {
            if(get2dInt(matrix, index, i) ==1 && visited[i] == 0)
            {
                TwoLinkEnqueue(queue, i);
            }
        }
    }
}

int main(const int argc, const char **argv)
{
    const int SIZE = 6;
    int **adjacency = init2dIntArray(adjacency, SIZE, SIZE);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);
    widthTravers(adjacency, SIZE, 0);
    printf("\n");
    widthTravers(adjacency, SIZE, 3);
    printf("\n");
    widthTravers(adjacency, SIZE, 1);
    printf("\n");
    return 0;
}