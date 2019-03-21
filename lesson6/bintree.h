/*
*    @author Denis Troschenkov
*
*    Homeworke №6
*/

// 2. Переписать программу, реализующее двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;
// в) *Добавить в программу обработку командной строки с помощью которой можно указывать
// из какого файла считывать данные, каким образом обходить дерево.

#ifndef BINTREE__
#define BINTREE__

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;

typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;
// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
        printf("(");

        if (root->left) 
            printTree(root->left);
        else 
            printf("NULL");
        printf(",");

        if (root->right) 
            printTree(root->right);
        else 
            printf("NULL");
        printf(")");
        }
    }
}

// Создание нового узла
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL) 
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) 
    {
        if (value> tmp->data) 
        {
            if (tmp->right) 
            {
                tmp = tmp->right;
                continue;
            } 
  else 
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } 
        else if (value< tmp->data) 
        {
            if (tmp->left) 
            {
                tmp = tmp->left;
                continue;
            } 
            else 
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } 
        else 
        {
            exit(2);                     // Дерево построено неправильно
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void midOrderTravers(Node* root) {
    if (root) {
        preOrderTravers(root->left);
        printf("%d ", root->data);
        preOrderTravers(root->right);
    }
}

void rightOrderTravers(Node* root) {
    if (root) {
        preOrderTravers(root->left);
        preOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

// Поиск по дереву
Node* SearchInTree(Node* root, T data) {
    Node* res;
    if (root == NULL) {
        return NULL;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        res = SearchInTree(root->left, data);
    } else {
        res = SearchInTree(root->right, data);
    }
    return res;
}



#endif