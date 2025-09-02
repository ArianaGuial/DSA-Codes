#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    int count;
} List;

List* initialize()
{
    List *list = (List*)malloc(sizeof(List));
    
    if(list == NULL)
    {
        return NULL;
    }

    list->head = NULL;
    list->count = 0;

    return list;
}

void empty(List *list)
{
    Node *current = list->head;

    while(current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        return;
    }

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count;
}

void insertLast(List *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL)
    {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL)
    {
        list->head = newNode;
    }

    else
    {
        Node *current = list->head;

        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    list->count++;
}

void insertPos(List *list, int data, int index)
{
    if(index < 0 || index > list->count)
    {
        return;
    }

    if(index == 0)
    {
        insertFirst(list, data);
    }

    else if(index == list->count)
    {
        insertLast(list, data);
    }

    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        
        if(newNode == NULL)
        {
            return;
        }

        newNode->data = data;
        Node *current = list->head;

        for(int i = 0; i < index; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        list->count++;
    }
}

void deleteStart(List *list)
{
    if(list->head == NULL)
    {
        return;
    }

    Node *current = list->head;
    list->head = current->next;

    free(current);
    list->count--;
}

void deleteLast(List *list)
{
    if(list->head == NULL)
    {
        return;
    }

    if(list->head->next == NULL)
    {
        free(list->head);
        list->head = NULL;
    }

    else
    {
        Node *current = list->head;

        while(current->next->next != NULL)
        {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }
    
    list->count--;
}

void deletePos(List *list, int index)
{

}

int retrieve(List *list, int index)
{

}

int locate(List *list, int data)
{

}

void display(List *list)
{

}