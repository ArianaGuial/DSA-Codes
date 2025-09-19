#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

// ARRAY STACK - Warehouse Inventory System

typedef struct 
{
    int items[MAX];
    int top;
} Stack;

// write your functions here

void initialize(Stack *s)
{
    s->top = -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if(!isFull(s))
    {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s)
{
    if(!isEmpty(s))
    {
        return s->items[(s->top)--];
    }
    
    return -1;
}

int peek(Stack *s)
{
    if(!isEmpty(s))
    {
        return s->items[s->top];
    }
    
    return -1;
}

int top(Stack *s)
{
    return s->top;
}

void display(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty.");
    }
    
    else
    {
        for(int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->items[i]);
        }
        printf("\b");
    }
}

int main() 
{
    // write your code here

    Stack stacks[3];
    int i, choice, containerID;
    bool found;

    for(i = 0; i < 3; i++) 
    {
        initialize(&stacks[i]);
    }

    while (1) 
    {
        printf("\n--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter container ID to push: ");
                scanf("%d", &containerID);

                for(i = 0; i < 3; i++)
                {
                    if (!isFull(&stacks[i])) 
                    {
                        push(&stacks[i], containerID);
                        printf("Container %d pushed successfully.\n", containerID);
                        break;
                    }
                }
                
                if(i == 3) 
                {
                    printf("All stacks are full. Cannot push container.\n");
                }
                
                break;

            case 2:
                for(i = 2; i >= 0; i--) 
                {
                    if (!isEmpty(&stacks[i])) 
                    {
                        int removed = pop(&stacks[i]);
                        printf("Container %d popped successfully.\n", removed);
                        break;
                    }
                }
                
                if(i < 0)
                {
                    printf("Error: All stacks are empty. Cannot pop container.\n");
                }
                
                break;

            case 3:
                printf("Enter container ID to check: ");
                scanf("%d", &containerID);
                found = false;

                for(i = 0; i < 3; i++) 
                {
                    for(int j = 0; j <= stacks[i].top; j++) 
                    {
                        if(stacks[i].items[j] == containerID) 
                        {
                            printf("Container %d exists in a stack.\n", containerID);
                            found = true;
                        }
                    }
                }
                
                if(!found) 
                {
                    printf("Container %d does not exist in any stack.\n", containerID);
                }
                break;

            case 4:
                for(i = 0; i < 3; i++) 
                {
                    printf("\n--- Stack %d ---\n", i + 1);
                    display(&stacks[i]);
                    
                    printf("\n");
                }
                
                break;

            case 5:
                printf("Exiting program.");
                exit(0);

            default:
                printf("Invalid.\n");
        }
    }

    return 0;
}

/*
SAMPLE OUTPUT:
--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 10
Container 10 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 20
Container 20 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 1
Enter container ID to push: 30
Container 30 pushed successfully.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 4

--- Stack 1 ---
30
20
10

--- Stack 2 ---
Stack is empty.

--- Stack 3 ---
Stack is empty.

--- Warehouse Inventory Management System ---
1. Push a container
2. Pop a container
3. Check if a container exists
4. Display all stacks
5. Exit
Enter your choice: 5
Exiting program.
*/