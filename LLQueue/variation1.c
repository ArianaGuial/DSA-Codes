#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Queue* initialize()
{
    Queue* q = (Queue *)malloc(sizeof(Queue));

    if(q == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q)
{
    return false;
}

bool isEmpty(Queue* q)
{
    return q->front == NULL;
}

void enqueue(Queue* q, int value)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed for new node\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = temp->next;

    if(q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued %d\n", value);
    return value;
}

int frontValue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty. No front element\n");
        return -1;
    }
    return q->front->data;
}

void display(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (front to rear):\n");
    Node* current = q->front;

    while(current != NULL)
    {
        printf("%d \n", current->data);
        current = current->next;
    }
}

int main()
{
    Queue* Q = initialize();

    if(Q == NULL)
    {
        return 1;
    }

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    display(Q);

    enqueue(Q, 4);
    display(Q);

    int value = dequeue(Q);
    printf("Value dequeued: %d\n", value);
    display(Q);

    printf("Front element: %d\n", frontValue(Q));

    while(!isEmpty(Q))
    {
        dequeue(Q);
    }

    free(Q);

    return 0;
}