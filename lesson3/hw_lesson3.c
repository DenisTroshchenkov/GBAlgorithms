/*
*    @author Denis Troschenkov
*
*    home work № 3
*/

//1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
//2. *Реализовать шейкерную сортировку.
//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxN 20

void printArray(int, int*);
void swap(int*, int*);

// task №1
// Сортировка с оптимизацией требует в 5 раз меньше операций
int bubbleSort(int, int*);
int notOptimizeBubbleSort(int, int*);

// task №2
int shakerSort(int, int*);

// task №3
int binarySearch(int, int, int*);

// task №4
// bubbleSort N^2 ожидаемое количество операций - 400 полученное 85
// notOptimizeBubbleSort N^2 ожидаемое количество операций - 400 полученное 455
// shakerSort N^2 ожидаемое количество операций - 400 полученное 265
// Наиболее быстрой оказалась оптимизированная пузырьковая сортировка

int main(int argc, char** argv) {
    int a[MaxN] = {8,-7,100,88,2,3,1,1,78,-45,3,75,32,123,653,11,10,99,10,22}; 
    int* resArray = (int*)malloc(MaxN * sizeof(int));
    
    memcpy(resArray, a, MaxN * sizeof(int));
    int resCount;
    resCount = bubbleSort(MaxN, resArray);
    printArray(MaxN, resArray);
    printf("bubbleSort count: %d\n", resCount);

    memcpy(resArray, a, MaxN * sizeof(int));
    resCount = notOptimizeBubbleSort(MaxN, resArray);
    printArray(MaxN, resArray);
    printf("notOptimizeBubbleSort count: %d\n", resCount);

    memcpy(resArray, a, MaxN * sizeof(int));
    resCount = shakerSort(MaxN, resArray);
    printArray(MaxN, resArray);
    printf("shakerSort count: %d\n", resCount);

    int resIdx;
    resIdx = binarySearch(78, MaxN, resArray);
    printf("binatySearch idx: %d\n", resIdx);

    if (resArray)
        free(resArray);
    return 0;
}

int bubbleSort(int N, int* a) {
    int count = 0;
    for(size_t i = 0; i < N; i++) {
        //Оптимизация
        int is_swaped = 0;
        ++count;
        for(size_t j = 0; j < N - 1; j++) {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                is_swaped = 1;
                ++count;
            }
        }
        if (!is_swaped) {
            break;
        }
    }
    return count;
}

int notOptimizeBubbleSort(int N, int* a) {
    int count = 0;
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < N - 1; j++) {
            ++count;
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                ++count;
            }
        }
    }
    return count;
}

int shakerSort(int N, int* a) {
    int count = 0;
    for (size_t left_idx = 0, right_idx = N - 1; left_idx < right_idx;) {
        for (size_t idx = left_idx; idx < right_idx; idx++)
        {
            ++count;
            if (a[idx + 1] < a[idx])
            {
                ++count;
                swap(&a[idx], &a[idx + 1]);
            }
        }
        right_idx--;

        for (size_t idx = right_idx; idx > left_idx; idx--)
        {
            ++count;
            if (a[idx - 1] >  a[idx])
            {
                ++count;
                swap(&a[idx - 1], &a[idx]);
            }
        }
        left_idx++;
    }
    return count;
}

int binarySearch(int serch_value, int N, int* a) {
    int left_idx = 0;
    int right_idx = N - 1;
    while (left_idx <= right_idx) {
        int midl = (left_idx + right_idx) / 2;
        if (a[midl] < serch_value) {
            left_idx = midl + 1;
        } else if (a[midl] > serch_value) {
            right_idx = midl - 1;
        } else {
            return midl;
        }
    }
    return -1;
}

void printArray(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
