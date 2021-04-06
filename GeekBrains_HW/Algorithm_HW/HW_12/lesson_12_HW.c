#include "geek_c/geek.h"


BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data)
{
    BinTreeIntNode *newNode;
    newNode =(BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if(t == NULL) // если корня нет- корнем становится новый узел
    {
        t = newNode;
        return t;
    }
    else
    {
        while(current->key != data)
        {
            parent = current;
            if(current->key > data)  // если текущий узел больше искомого- текущий узел нужно переключить в левого наследника
            {
                current = current->left;
                if(current == NULL) // если при переключении текущего узла не существует- мы находимся в листовом элементе и можем добавлять ему наследника.
                {
                    parent->left = newNode;
                    return t;
                }
            }
            else // иначе- в правого
            {
                current = current->right;
                if(current == NULL) // если при переключении текущего узла не существует- мы находимся в листовом элементе и можем добавлять ему наследника.
                {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

/* скобочная последовательность- это попытка визуализировать дерево средствами консоли */

void printTree(BinTreeIntNode *root) // обход в прямом порядке для формирования скобочной последовательности
{
    if(root)
    {
        printf("%d", root->key);
        if(root->left || root->right)
        {
            printf("(");
            if(root->left)
            {
                printTree(root->left);
            }
            else
            {
                printf("NULL");
            }
            printf(",");
            if(root->right)
            {
                printTree(root->right);
            }
            else
            {
                printf("NULL");
            }
            printf(")");
        }
    }
}

BinTreeIntNode* getSuccessor(BinTreeIntNode *node)
{
    BinTreeIntNode *current = node->right;
    BinTreeIntNode *parent = node;
    BinTreeIntNode *s = node;

    while(current != NULL)
    {
        parent = s;
        s = current;
        current = current->left;
    }
    if(s != node->right)
    {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

boolean delete(BinTreeIntNode *root, int key)
{
    BinTreeIntNode *current = root;
    BinTreeIntNode *parent = root;
    boolean isLeftChild = true;

    while(current->key != key)
    {
        parent = current;
        if(key < current->key)
        {
            current = current->left;
            isLeftChild = true;
        }
        else
        {
            current = current->right;
            isLeftChild = false;
        }
        if(current == NULL)
        {
            return false;
        }
    }

    if(current->left == NULL && current->right == NULL)
    {
        if(current == root)
            root = NULL;
        else if(isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if(current->right == NULL)
    {
        if(isLeftChild)
        {
            parent->left = current->left;
        }
        else
            parent->right = current->left;
    }
    else if(current->left == NULL)
    {
        if(isLeftChild)
        {
            parent->left = current->right;
        }
        else
            parent->right = current->right;
    }
    else
    {
        BinTreeIntNode *successor = getSuccessor(current);
        if(current == root)
            root = successor;
        else if(isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    free(current);
    return true;
}

void freeBinTree(BinTreeIntNode *node)
{
    if (node != NULL)
    {
        freeBinTree(node->right);
        freeBinTree(node->left);
        free(node);
    }
}

// 1 write some code that checks if the tree is balanced. (it's not working in the correct way for unknown reasons, though...)
int max(int a, int b) // maximum of two integers
{
    return (a >= b) ? a : b;
}

int height(BinTreeIntNode *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

boolean isBalanced(BinTreeIntNode *root)
{
    int leftHeight;
    int rightHeight;

    if(root == NULL)
    {
        return true;
    }
    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
}

// 2a write the program that creates forest of 50 trees with 10000 elements
void runForest(BinTreeIntNode *tree, BinTreeIntNode **arr, int size, int branches)
{
    int border = 2000000000;

    for(int i = 0; i < size; ++i)
    {
        arr[i] = NULL;
        for(int j = 0; j < branches; ++j)
        {
            arr[i] = treeInsert(arr[i], rand() % border);
        }
    }
}

// 3
BinTreeIntNode* binTreeSearchRecursive(BinTreeIntNode *root, int value)
{
    BinTreeIntNode *current = root;
    if(current == NULL)
    {
        return NULL;
    }
    if(current->key == value)
    {
        return current;
    }

    if(root->key >= value)
    {
        return binTreeSearchRecursive(current = current->left, value);
    }
    else
    {
        return binTreeSearchRecursive(current = current->right, value);
    }
    if(current == NULL)
    {
        return NULL;
    }
}

boolean treeNodeDelete(BinTreeIntNode *root, int key);

int main()
{
    // 1
    printf("%s \n", "exercise 1");
    BinTreeIntNode *tree = NULL;
    tree = treeInsert(tree, 10);
    treeInsert(tree, 5);
    treeInsert(tree, 7);
    treeInsert(tree, 3);
    treeInsert(tree, 11);
    treeInsert(tree, 15);
    treeInsert(tree, 19);

    printTree(tree);
    printf(" \n");
    printf("%s \n", isBalanced(tree) ? "True" : "False");

    // 2
    printf("%s \n", "exercise 2");
    BinTreeIntNode *tree2 = NULL;
    const int SZ = 50;
    const int BRANCHES = 10000;
    float counter = 0;
    float percentage = 0;
    BinTreeIntNode *arr[SZ];
    runForest(tree2, arr, SZ, BRANCHES);
    for(int i = 0; i < SZ; ++i)
    {
        if(isBalanced(arr[i]))
            counter++;
        printf("%s \n", isBalanced(arr[i]) ? "True" : "False");
        printf("%.0f \n", isBalanced(arr[i]) ? counter++ : counter + 0);
        freeBinTree(tree2);
    }
    percentage = (counter / (float)SZ) * 100;
    printf("%.1f%% \n", percentage);
    // 3
    printf("%s \n","exercise 3");
    int val;
    printf("%s", "Please enter the number to search: ");
    scanf("%d", &val);
    printf("\n");
    printf("The result of the search of %d in tree is %s \n", val, binTreeSearchRecursive(tree, val));
    freeBinTree(tree);
    return 0;
}