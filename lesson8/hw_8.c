/*
*    @author Denis Troschenkov
*
*    Homeworke №8
*/

//1. Реализовать сортировку подсчетом.
//2. Реализовать быструю сортировку.
//3. *Реализовать сортировку слиянием.
//4. **Реализовать алгоритм сортировки со списком

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MaxN 100000

//task1
int simpleCountingSort(int *A, int len, int k)  {
    int* C = (int*) malloc(sizeof(int) * (k + 1));
    int count = 0;
    for (size_t i = 0; i <= k; i++) {
        C[i] = 0;
        ++count;
    }
    for (size_t i = 0; i < len; i++) {
        C[A[i]]++;
        ++count;
    }
    size_t b = 0;
    for (size_t j = 0; j <= k; j++) {
        ++count;
        for (size_t i = 0; i < C[j]; i++) {
            ++count;
            A[b++] = j;
        }
    }
    free(C);
    return count;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//task2
int quickSort(int* array, int first, int last)
{
    int count = 0;
    int i = first, j = last, x = array[(first + last) / 2];

    do 
    {
        ++count;
        while (array[i] < x) {
            ++count; 
            i++;
        }
        while (array[j] > x) { 
            ++count;
            j--; 
        }

        if(i <= j) 
        {
            ++count;
            if (array[i] > array[j]) { 
                ++count;
                swap(&array[i], &array[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) {
        ++count;
        count += quickSort(array, i, last);
    }
    if (first < j) {
        ++count;
        count += quickSort(array, first, j);
    }
    return count;
}


int merge(int* buf, int left, int right) {
    int count = 0;
    int middle = left + (right - left) / 2;
    if (left >= right || middle < left || middle > right) return 1; 
    if (right == left + 1 && buf[left] > buf[right]) {
        ++count;
        swap(&buf[left], &buf[right]);
        return count;
    }
    int m_size = sizeof(int) * (right - left + 1);
    int* tmp = (int*) malloc(m_size);
    memcpy(tmp, &buf[left], m_size);
    for (size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i) {
        ++count;
        if (j > middle - left) {
            ++count;   
            buf[i] = tmp[k++];
        } else if(k > right - left) {
            ++count;
            buf[i] = tmp[j++];
        } else {
            ++count;
            buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
        }
    }
    free(tmp);
    return count;
}

//task 3
int mergeSort(int *buf, int left, int right)
{
    int count = 0;
    int tmp;
    if (left < right) {
        ++count;
        if (right - left == 1) {
            ++count;
            if (buf[right] < buf[left]) {
                ++count;
                tmp = buf[left];
                buf[left] = buf[right];
                buf[right] = tmp;
            }
        }
        else {
            ++count;                  
            count += mergeSort(buf, left, left + (right - left) / 2);
            count += mergeSort(buf, left + (right - left) / 2 + 1, right);
            count += merge(buf, left, right);
        }
    }
    return count;
}

void printArray(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

int main () {
    int a[MaxN];
    int maxValue = 0;
    for (size_t i = 0; i < MaxN; ++i) {
        a[i] = rand() % 100;
        if (a[i] > maxValue) 
            maxValue = a[i];
    }  
    int* resArray = (int*)malloc(MaxN * sizeof(int));
    
    memcpy(resArray, a, MaxN * sizeof(int));
    clock_t tic = clock();
    int resCount = simpleCountingSort(resArray, MaxN, maxValue);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    //printArray(MaxN, resArray);
    printf("simpleCountingSort count: %d\n", resCount);

    memcpy(resArray, a, MaxN * sizeof(int));
    tic = clock();
    resCount = quickSort(resArray, 0, MaxN);
    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    //printArray(MaxN, resArray);
    printf("quickSort count: %d\n", resCount);

    memcpy(resArray, a, MaxN * sizeof(int));
    tic = clock();
    resCount = mergeSort(resArray, 0, MaxN - 1);
    toc = clock();
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    //printArray(MaxN, resArray);
    printf("mergeSort count: %d\n", resCount);

    free(resArray);
}
