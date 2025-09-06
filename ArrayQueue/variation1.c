#include<stdio.h>
#include<stdlib.h>

#define MAX 10

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

Queue* initialize()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    if(q == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    q->list.count = 0;
    q->front = -1;
    q->rear = -1;

    return q;
}

void enqueue(Queue *q, int value)
{
    if(q->list.count == MAX)
    {
        printf("Cannot enqueue %d, queue is full\n", value);
        return;
    }

    if(q->list.count == 0)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->list.items[q->rear] = value;
    q->list.count++;

    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q)
{
    if(q->list.count == 0)
    {
        printf("Cannot dequeue, queue is empty\n");
        return -1;
    }

    int value = q->list.items[q->front];

    if(q->list.count == 1)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;
    printf("Dequeued %d\n", value);
    return value;
}

int frontValue(Queue *q)
{
    if(q->list.count == 0)
    {
        printf("No front element, queue is empty\n");
        return -1;
    }

    return q->list.items[q->front];
}

void displayQueue(Queue *q)
{
    if(q->list.count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue contents (front to rear):\n");

    int i = q->front;

    for(int c = 0; c < q->list.count; c++)
    {
        printf("%d", q->list.items[i]);
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    Queue *Q = initialize();

    if(Q ==NULL)
    {
        return 1;
    }

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 2);
    enqueue(Q, 5);
    displayQueue(Q);

    enqueue(Q, 4);
    displayQueue(Q);

    int value = dequeue(Q);

    printf("Value dequeued: %d\n", value);
    displayQueue(Q);

    printf("Front most element: %d\n", frontValue(Q));

    free(Q);
    return 0;
}
