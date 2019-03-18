/*
*    @author Denis Troschenkov
*
*    Homeworke №5
*/


// 2. Добавить в программу «Реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, 
//    то должно выводиться соответствующее сообщение. Постарайтесь создать ситуацию, когда память 
//    не будет выделяться (добавлением большого количества данных).
// 3. Написать программу, которая определяет, является ли введённая скобочная последовательность правильной. 
//    Примеры правильных скобочных выражений – (), ([])(), {}(), ([{}]), неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.
//    Например: (2+(2*2)) или [2/{5*(4+7)}].
// 4. *Создать функцию, копирующую односвязный список (то есть создающую в памяти копию односвязного списка без удаления первого списка).
// 5. *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
// 6.  Реализовать очередь



#include <stdio.h>
//task 2 стек
#include <stack.h>
//task 6
#include <queue.h>
//task 4
#include <list.h>
#include <string.h>


int isBracketsClosed(char leftBracket, char rightBracket) {
    switch (leftBracket)
    {
        case '(':
            if (rightBracket == ')') return 1;
            break;
        case '[':
            if (rightBracket == ']') return 1;
            break;
        case '{':
            if (rightBracket == '}') return 1;
            break;
        default:
            break;
    }
    return 0;
}

//task 3
int CheckBracketsInStr(const char* str) {
    Stack leftBrackets;
    InitStack(&leftBrackets);
    int strLen = strlen(str);
    for (size_t i = 0; i < strLen; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            if(!PushStack(&leftBrackets, str[i])) {
                printf("CheckBracketsInStr: PushStack() is error: %d\n", leftBrackets.error);
                return 0;
        }
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char leftBracket;
            if(!PopStack(&leftBrackets, &leftBracket)) {
                printf("CheckBracketsInStr: PopStack() is error: %d\n", leftBrackets.error);
            }
            if (!isBracketsClosed(leftBracket, str[i])) {
                return 0;
            } 
        }
    }

    if (leftBrackets.size > 0) {
        return 0;
    }
    return 1;
}

int main(){
    int res = CheckBracketsInStr("({}})");
    printf("task3 res: %d\n", res);
    Queue testQueue;
    InitQueue(&testQueue);
    PushQueue(&testQueue, '8');
    PushQueue(&testQueue, '9');
    PushQueue(&testQueue, 'c');
    PrintQueue(&testQueue);
    List testList;
    List copyList;
    InitList(&testList);
    InitList(&copyList);
    PushList(&testList, 'b');
    PushList(&testList, 'v');
    ListCopy(&testList, &copyList);
    ListPrint(&copyList);
    return 0;
}
