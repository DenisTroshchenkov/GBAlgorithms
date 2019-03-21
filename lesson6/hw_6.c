/*
*    @author Denis Troschenkov
*
*    Homeworke №6
*/

// 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
// 2. Переписать программу, реализующее двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;
// в) *Добавить в программу обработку командной строки с помощью которой можно указывать
// из какого файла считывать данные, каким образом обходить дерево.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <bintree.h>

#define MAX_STR_LENGTH 100

// task 1
long int StrToHash (const char* str) {
    int strLength = strlen(str);
    if (strLength == 0) {
        return 0;
    }
    long int res = str[0];
    for (size_t i = 1; i < strLength; ++i) {
        res += (long int)pow(str[i], i) % strLength;
    }
    return res;
}

int main(){
    printf("Task 1: Please enter random string: ");
    char inputStr[MAX_STR_LENGTH];
    scanf("%s", inputStr);
    long int resHash = StrToHash(inputStr);
    printf("Task 1: result hash: %d\n", resHash);
    printf("Task 2: enter file name: ");
    scanf("%s", inputStr);
    printf("Task 2: enter order[1 - pre; 2 - mid; 3 - right]");
    int order;
    scanf("%d", &order);
    Node *Tree = NULL;
    FILE* file = fopen(inputStr, "r");
    if (file == NULL)
    {
        puts("Can't open file!");
        exit(1);
    }
    int count;
    fscanf(file, "%d", &count);          // Считываем количество записей
    int i;
    for(i = 0; i < count; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);
    printTree(Tree);
    printf("\nOrderTravers:\n");
    switch (order) {
        case 1:
        preOrderTravers(Tree);
        break;
        case 2:
        midOrderTravers(Tree);
        break;
        case 3:
        rightOrderTravers(Tree);
        break;
    }
    printf("\n");
    return 0;
}