#include <stdio.h>
#include <stdlib.h>

// 1
#define SIZE 10

#define B int
#define true 1 == 1
#define false 1 != 1
#define SIZEBINARY 64


//1
typedef struct{
    int pr;
    int data;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init(){
    for(int i = 0; i < SIZE; i++){
        arr[i] = NULL;
    }

    head = 0;
    tail = 0;
    items = 0;
}

Node* findMax(){
    Node* max_pr = arr[head];
    for(int i = 1; i < tail; i++){
        if((arr[i]->pr) > (max_pr->pr)){
            max_pr = arr[i];
        }
    }
    return max_pr;
}

void insert(int pr, int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node-> pr = pr;
    node-> data = data;

    if(items == SIZE){
        printf("%s \n", "Queue is full");
        free(node);
    }
    else{
        arr[tail++] = node;
        items++;
    }
}

void rem(){
    Node* temp;
    int i = 0;
    int index = 0;

    if(items == 0){
        printf("%s \n", "Queue is empty");
    }
    else{
        Node* max_pr = findMax();;

        for(i = head; i < tail; i++){
            index = i % SIZE;

            if(arr[index] -> pr == max_pr-> pr){
                temp = arr[index];
                arr[index] = NULL;
                tail--;
                items--;

                while(index < SIZE - 1){
                    arr[index] = arr[index + 1];
                    index++;
                    if(index == tail){
                        arr[index] = NULL;
                    }
                }
                i--;
                printf("pr= %d, data= %d\n", temp -> pr, temp -> data);
            }
        }
    }
}

void printQueue(){
    printf("[ ");

    for(int i = 0; i < SIZE; i++){
        if(arr[i] == NULL){
            printf("[*, *] ");
        }
        else{
            printf("[%d, %d] ", arr[i] -> pr, arr[i] -> data);
        }
    }

    printf("] \n");
}

void taskOne(){
    init();
    insert(1, 11);
    insert(3, 22);
    insert(4, 33);
    insert(2, 44);
    insert(5, 55);
    insert(4, 66);
    insert(5, 77);
    insert(7, 88);
    insert(2, 99);
    insert(6, 100);
    printQueue();

    for(int i = 0; i < 3; i++){
        rem();
    }
    printQueue();

    insert(10, 234);
    insert(9, 432);
    insert(10, 111);
    insert(9, 246);
    printQueue();

    rem();
    printQueue();
}

typedef int boolean;

int cursor = -1;
B Stack[SIZE];

void decToBin(B number){
    if(number >= 2)
    {
        decToBin(number / 2);
    }
    printf("%d", number % 2);
}

boolean push(B number){
    if(cursor < SIZE){
        Stack[++cursor] = number;
        decToBin(number);
        printf("\n");
        return true;
    }
    else{
        printf("Stack overflow\n");

        return false;
    }
}

B pop()
{
    if(cursor != -1)
    {
        return Stack[cursor--];
    }
    else
    {
        printf("%s \n", "Stack is empty!");
    }
}


void taskTwo(){
    int val;
    printf("Please, enter the number: ");
    scanf("%d", &val);
    push(val);

    pop();
}

int main(int argc, char** atgv){
    taskOne();
    taskTwo();

    return 0;
}
