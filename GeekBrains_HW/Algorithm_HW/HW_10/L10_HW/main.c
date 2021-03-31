#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define T char
#define true 1 == 1
#define false 1 != 1
#define STR_SIZE 255

typedef int boolean;

typedef struct OneLinkNode
{
    int data;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct
{
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst);

void insert(OneLinkList *lst, int data)
{
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->data = data;
    new->next = NULL;

    OneLinkNode *current = lst->head;
    if(current == NULL)
    {
        lst->head = new;
        lst->size++;
        return;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

//1 So sad, dumb student was not able to solve it...
typedef struct
{
    OneLinkNode *head;
    int size;
} OneLinkStack;

push(OneLinkStack *stack, T value);

//boolean balanceBrackets(OneLinkList *stack, T value)
//{
//    OneLinkNode *current = (OneLinkNode*) malloc(sizeof(OneLinkNode));
//    if(current->data == '{' || current->data == '(' || current->data == '[')
//        {
//            push(stack, current->data);
//            continue;
//        }
//        else if(current->data == '}' || current->data == ')' || current->data == ']')
//        {
//            return false;
//        }
//        else
//        {
//            push(stack, current->data);
//            continue;
//        }
//}

popOneLinkStack(OneLinkList *stack);

//2
void cpy(OneLinkList *lst, OneLinkList *lst2)
{
    OneLinkNode *current = lst->head;

    if(current == NULL){
        insert(lst2, current->data);
    }
    else{
        while (current != NULL)
        {
            insert(lst2, current->data);
            current = current->next;
        }
    }
}

OneLinkNode* rm(OneLinkList *lst, int data)
{
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if(current == NULL)
    {
        return NULL;
    }
    while(current->next != NULL && current->data != data)
    {
        parent = current;
        current = current->next;
    }
    if(current->data != data)
    {
        return NULL;
    }
    if(current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    free(parent);
    lst->size--;
    return current;
}

//3
boolean checkSort(OneLinkList *lst)
{
    int b = 1;
    OneLinkNode *temp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    OneLinkNode *current = lst->head;
    for(int i = 1; i < lst->size; i++)
    {
            temp->data = current->data;
            current = current->next;
            if(current->data > temp->data)
            {
                b++;
                continue;
            }
            else
            {
                continue;
            }
    }
    return b == lst->size ? true : false;
}

void printOneLinkIntNode(OneLinkNode *n);

void printOneLinkIntList(OneLinkList *lst);

int main()
{
    //1 So sad, dumb student is unable to solve it...
//    T string[STR_SIZE];
//    int i;
//    OneLinkList *BrBalance = (OneLinkList*) malloc(sizeof(OneLinkList));
//    initOneLinkList(BrBalance);
//    printf("Please input the expression: ");
//    for(i = 0; i < STR_SIZE; ++i)
//    {
//        gets(string[i]);
//        push(BrBalance, string[i]);
//    }
//    printf("%d \n", balanceBrackets(BrBalance, string[i]) ? "True" : "False");

    //2
    OneLinkList *list1 = (OneLinkList*) malloc(sizeof(OneLinkList));
    OneLinkList *list2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    int i = 0;
    initOneLinkList(list1);
    initOneLinkList(list2);

    insert(list1, (10));
    insert(list1, (0));
    insert(list1, (5));
    insert(list1, (38));
    printOneLinkIntList(list1);
    printf("shitty solution of copying: \n");
    cpy(list1, list2);
    printOneLinkIntList(list2);
    printf("\n");

    //3
    OneLinkList *list3 = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(list3);
    boolean check;
    insert(list3, 4);
    insert(list3, 2);
    insert(list3, 42);
    insert(list3, 73);
    insert(list3, 5);
    insert(list3, 7);
    printf("%s \n", checkSort(list3) ? "True" : "False");
    return 0;
}
