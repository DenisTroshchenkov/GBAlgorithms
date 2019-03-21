/*
*    @author Denis Troschenkov
*
*    Homeworke №5
*/


// 2. Добавить в программу «Реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, 
//    то должно выводиться соответствующее сообщение. Постарайтесь создать ситуацию, когда память 
//    не будет выделяться (добавлением большого количества данных).

#ifndef __STACK
#define __STACK

#include <stdio.h>
#include <malloc.h>
#include <list.h>

#define ErrorStackSize 1
#define ErrorMemAlloc  2
#define ErrorStackIsEmpty 3

typedef struct TStack
{
    Node *head;
    int size;
    int maxSize;
    int error;
} Stack;

void InitStack(Stack* stack) {
    stack->head = NULL;
    stack->maxSize = 10000;
    stack->error = 0;
    stack->size = 0;
}

int PushStack(Stack* stack, ValueT value)
{
    if (stack->size >= stack->maxSize) {
        stack->error = ErrorStackSize;
        return 0;
    }
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        stack->error = ErrorMemAlloc;
        return 0;
    }
    tmp->value = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
    return 1;
}

int PopStack(Stack* stack, ValueT* value) {
    if (stack->size == 0) 
    {
        stack->error = ErrorStackIsEmpty;
        return 0;
    }
    Node* next = NULL;
    *value = stack->head->value;
    next = stack->head;
    stack->head = stack->head->next;
    free(next);
    stack->size--;
    return 1;
}

void PrintStack(Stack* stack)
{
    Node *current = stack->head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}
#endif