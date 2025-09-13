#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Stack
{
    Node* top;
} Stack;

Stack* initialize()
{
    Stack* s = (Stack *)malloc(sizeof(Stack));

    if(s == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    s->top = NULL;
    return s;
}

bool isFull(Stack* s)
{
    return false;
}

bool isEmpty(Stack* s)
{
    return s->top == NULL;
}

void push(Stack* s, int value)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed for new Node\n");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;

    printf("Pushed %d to stack\n", value);
}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);

    printf("Popped %d from stack\n", value);
    return value;
}

int peek(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty. Nothing to peek\n");
        return -1;
    }

    return s->top->data;
}

void display(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents (top to bottom): \n");
    Node* current = s->top;

    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    Stack* S = initialize();

    if(S == NULL)
    {
        return 1;
    }

    push(S, 1);
    push(S, 3);
    push(S, 5);
    display(S);

    push(S, 4);
    display(S);

    int value = pop(S);
    printf("Value popped: %d\n", value);
    display(S);

    printf("Top element: %d\n", peek(S));

    while(!isEmpty(S))
    {
        pop(S);
    }

    free(S);

    return 0;
}