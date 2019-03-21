/*
*    @author Denis Troschenkov
*
*    Homeworke №5
*/

// 6.  Реализовать очередь



#ifndef __QUEUE
#define __QUEUE
#include <stdio.h>
#include <malloc.h>
#include <list.h>

#define ErrorQueueSize 1
#define ErrorMemAlloc  2
#define ErrorQueueIsEmpty 3

typedef struct TQueue
{
    Node *head;
    Node *tail;
    int size;
    int maxSize;
    int error;
} Queue;

void InitQueue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->maxSize = 10000;
    queue->size = 0;
    queue->error =0;
}

int PushQueue(Queue* queue, ValueT value)
{
    if (queue->size >= queue->maxSize) {
        queue->error = ErrorQueueSize;
        return 0;
    }
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        queue->error = ErrorMemAlloc;
        return 0;
    }
    tmp->value = value;
    tmp->next = NULL;
    if (queue->tail == NULL) {
        queue->tail = tmp;
        queue->head = tmp;       
    } else {
        queue->tail->next = tmp;
        queue->tail = tmp;
    }
    queue->size++;
    return 1;
}

int PopQueue(Queue* queue, ValueT* value) {
    if (queue->size == 0) 
    {
        queue->error = ErrorQueueIsEmpty;
        return 0;
    }
    Node* next = NULL;
    *value = queue->head->value;
    next = queue->head;
    queue->head = queue->head->next;
    free(next);
    queue->size--;
    if(queue->size == 0) {
        queue->tail = NULL;
    }
    return 1;
}

void PrintQueue(Queue* stack)
{
    Node *current = stack->head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}
#endif