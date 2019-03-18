/*
*    @author Denis Troschenkov
*
*    Homeworke №5
*/

// 4. *Создать функцию, копирующую односвязный список (то есть создающую в памяти копию односвязного списка без удаления первого списка).

#ifndef __LIST
#define __LIST
#include <stdio.h>
#include <malloc.h>

#define ValueT char
typedef struct TNode
{
    ValueT value;
    struct TNode *next;
} Node;

typedef struct TList {
    Node *head, *current;
    int size;
} List;

void InitList(List* list) {
    list->head = NULL;
    list->size = 0;
}

int PushList(List* list, ValueT value)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = list->head;
    list->head = tmp;
    list->size++;
    return 1;
}

void ListPrint(List* list) {
    Node *p = list->head;
    do
    {
        if (p == list->current) 
            printf("*");
        printf("%c ", p->value);
        p = p->next;
    }
    while(p!=NULL);
}



int ListCopy(List* listSrc, List* listDst) {
    Node* p = listSrc->head;
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->value = p->value;
    ++listDst->size;
    listDst->head = tmp;
    listDst->current = listDst->head;
    p = p->next;
    do
    {
        Node* prevNode = tmp;
        tmp = (Node*) malloc(sizeof(Node));
        tmp->value = p->value;
        tmp->next = NULL;
        prevNode->next = tmp;
        ++listDst->size;        
        p = p->next;
    }
    while(p!=NULL);
}
#endif