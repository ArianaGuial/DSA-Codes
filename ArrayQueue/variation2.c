#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
    int items[MAX];
    int front;
    int rear;
 } Queue;


Queue* initialize()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    if(q == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    q->front = 1;
    q->rear = 0;

    return q;
}

int isEmpty(Queue *q)
{
    return q->front == (q->rear + 1) % MAX;
}

int isFull(Queue *q)
{
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue *q, int value)
{
    if(isFull(q))
    {
        printf("Cannot enqueue %d, queue is full\n", value);
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Cannot dequeue, queue is empty\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;

    printf("Dequeued %d\n", value);
    return value;
}

int frontValue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("No front element, queue is empty\n");
        return -1;
    }

    return q->items[q->front];
}

void displayQueue(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (front to rear):\n");

    int i = q->front;

    while(i != (q->rear + 1) % MAX)
    {
        printf("%d\n", q->items[i]);
        i = (i + 1) % MAX;
    }
}

int main()
{
    Queue *Q = initialize();

    if(Q == NULL)
    {
        return 1;
    }

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    displayQueue(Q);

    dequeue(Q);
    displayQueue(Q);

    printf("Front element: %d\n", frontValue(Q));

    free(Q);
    return 0;
}