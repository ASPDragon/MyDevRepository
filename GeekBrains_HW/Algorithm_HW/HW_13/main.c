#include "geek_c/geek.h"

#define SZ 4

int **createGraph()
{
    int **matrix = init2dIntArray(matrix, SZ, SZ);
    setLineValues(matrix, SZ, 0, 0, 1, 0, 0),
    setLineValues(matrix, SZ, 1, 1, 0, 1, 1);
    setLineValues(matrix, SZ, 2, 0, 1, 0, 1);
    setLineValues(matrix, SZ, 3, 0, 1, 1, 0);
    return matrix;
}

int getVertex(int **matrix, int size, int index, int *visit)
{
    for (int i = 0; i < size; ++i)
    {
        if (*((*(matrix + index)) + i) == 1 && !visit[i])
            return i;
    }
    return -1;
}

void depthTraversStack(int** matrix, int size)
{
    int visited[SZ] = {0};
    OneLinkList* stack = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(stack);

    visited[0] = 1;

    printf("The sequence of the depth traverse of the graph is: %c ", OFFSET);
    pushOneLinkStack(stack, 0);

    while (stack->size != 0)
    {
        int vertex = getVertex(matrix, size, stack->head->dat, visited);
        if(vertex == -1)
            popOneLinkStack(stack);
        else
        {
            visited[vertex] = 1;
            pushOneLinkStack(stack, vertex);
            printf("%c ", vertex + OFFSET);
        }
    }
    printf("\n");
    while (stack->size != 0)
    {
        popOneLinkStack(stack->head);
    }
    free(stack);
}

void adjacencyCount(int** matrix, int size, int *links)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (matrix[i][j] == 1 && i != j)
                links[i]++;
        }
    }
}

void taskOne()
{
    printf("%s\n", "Task #1: ");
    int** graph = createGraph();
    depthTraversStack(graph, SZ);
    for (int i = 0; i < SZ; ++i)
        free(*(graph + i));
    free(graph);
}

void taskTwoA()
{
    printf("%s\n", "Task #2: \n");
    int links[SZ] = {0};
    int** graph = createGraph();

    adjacencyCount(graph, SZ, links);
    printf("Adjacency for every node: ");
    printIntArray(links, SZ, 3);

    for (int i = 0; i < SZ; ++i)
        free(*(graph + i));
    free(graph);
}

void taskTowB()
{}

int main(const int argc, const char** argv)
{
    taskOne();
    taskTwoA();
    return 0;
}