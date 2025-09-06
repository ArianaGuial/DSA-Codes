#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct
{
    int items[MAX];
    int top;
} Stack;

Stack* initialize() 
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    if(s == NULL) 
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    s->top = -1;
    return s;
}

void push(Stack *s, int value)
{
    if(s->top == MAX - 1)
    {
        printf("Cannot push %d, stack is full.\n", value);
        return;
    }

    s->top++;
    s->items[s->top] = value;

    printf("Pushed %d to stack\n", value);
}

int pop(Stack *s)
{
    if(s->top == -1)
    {
        printf("Cannot pop, stack is empty\n");
        return -1;
    }

    int value = s->items[s->top];
    s->top--;

    printf("Popped %d from stack\n", value);
    return value;
}

int peek(Stack *s)
{
    if(s->top == -1)
    {
        printf("Nothing to peek, stack is empty\n");
        return -1;
    }

    return s->items[s->top];
}

void displayStack(Stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents (top to bottom):\n");

    for(int i = s->top; i >= 0; i--)
    {
        printf("%d\n", s->items[i]);
    }
}

int main()
{
    printf("Program started\n");

    Stack *S = initialize();

    if(S == NULL)
    {
        return 1;
    }

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);
    displayStack(S);

    push(S, 4);
    displayStack(S);

    int value = pop(S);
    printf("Value popped: %d\n", value);
    displayStack(S);

    printf("Top most element: %d\n", peek(S));

    free(S);
    return 0;
}