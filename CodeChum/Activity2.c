#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

// ARRAY QUEUE - Pharmacy Queueing System

typedef struct 
{
    int items[MAX];
    int count;
} List;

typedef struct 
{
    List list;
    int front;
    int rear;
} Queue;

// write your functions here

Queue* initialize()
{
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->list.count = 0;
    
    return q;
}

void enqueue(Queue* q, int value)
{
    if(q->list.count == MAX)
    {
        printf("Queue is full.\n");
        return;
    }
    
    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(Queue* q)
{
    bool isEmpty(Queue* q);
    
    if(isEmpty(q))
    {
        return -1;
    }
    
    int value = q->list.items[q->front];
    q->front = (q->front + 1) % MAX;
    q->list.count--;
    
    return value;
}

bool isFull(Queue* q)
{
    return q->list.count == MAX;
}

bool isEmpty(Queue* q)
{
    return q->list.count == 0;
}

void display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    
    int i;
    
    for(i = 0; i < q->list.count; i++)
    {
        int index = (q->front + i) % MAX;
        printf("%d ", q->list.items[index]);
    }
    
    printf("\n");
}

int main() 
{
    // write your code here
    
    Queue* regularQueue = initialize();
    Queue* priorityQueue = initialize();
            
    int customerNumber = 1;
    int choice;
            
    while(1)
    {
        printf("\n--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                if(isFull(regularQueue))
                {
                   printf("Regular queue is full. Please try again later.\n");
                }
                else
                {
                    enqueue(regularQueue, customerNumber);
                    printf("You have entered the Regular queue. Your number is %d.\n", customerNumber);
                    customerNumber++;
                }
                break;
                
            case 2:
                if(isFull(priorityQueue))
                {
                    printf("Priority queue is full. Please try again later.\n");
                }
                else
                {
                    enqueue(priorityQueue, customerNumber);
                    printf("You have entered the Priority queue. Your number is %d.\n", customerNumber);
                    customerNumber++;
                }

                break;
            
            case 3:
                if(!isEmpty(priorityQueue))
                {
                    int served = dequeue(priorityQueue);
                    printf("Calling next customer from Priority Queue. Customer number: %d\n", served);
                }
                else if(!isEmpty(regularQueue))
                {
                    int served = dequeue(regularQueue);
                    printf("Calling next customer from Regular Queue. Customer number: %d\n", served);
                }
                else
                {
                    printf("No customers in queue.\n");
                }
                
                break;
            
            case 4:
                printf("\n-- Current Queue Status --\n");
                
                printf("Regular Queue: ");
                display(regularQueue);
                
                printf("Priority Queue: ");
                display(priorityQueue);
                
                break;
            
            case 5:
                printf("Exiting program. Goodbye!\n");
                free(regularQueue);
                free(priorityQueue);
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

/*
SAMPLE OUTPUT:
--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 1
You have entered the Regular queue. Your number is 1.

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 1
You have entered the Regular queue. Your number is 2.

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 2
You have entered the Priority queue. Your number is 3.

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 1
You have entered the Regular queue. Your number is 4.

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 3
Calling next customer from Priority Queue. Customer number: 3

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 3
Calling next customer from Regular Queue. Customer number: 1

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 3
Calling next customer from Regular Queue. Customer number: 2

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 3
Calling next customer from Regular Queue. Customer number: 4

--- Pharmacy Queueing System ---
1. Enter Regular Queue
2. Enter Priority Queue
3. Call Next Customer
4. Display Queues
5. Exit
Enter your choice: 5
Exiting program. Goodbye!
*/