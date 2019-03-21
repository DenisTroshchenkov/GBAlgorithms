/*
*    @author Denis Troschenkov
*
*    Homeworke № 7
*/


// 1. Написать функции, которые считывают матрицу смежности из файла и выводят её на экран.
// 2. Написать рекурсивную функцию обхода графа в глубину.
// 3. Написать функцию обхода графа в ширину.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MaxInt = 20000000;
#define MAX_STR_LENGTH 100
#define MAX_N 100

int load(int W[MAX_N][MAX_N], const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Can't open file\n");
        exit(1);
    }
    int N;
    fscanf(file, "%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            int a;
            fscanf(file, "%d", &a);
            if (a == 0) 
                W[i][j] = MaxInt; 
            else 
                W[i][j] = a;
        }
    fclose(file);
    return N;
}


void printMatrix(int W[MAX_N][MAX_N], int N)
{
    printf("%s", "      ");
    for(int i = 0; i < N; i++)
        printf("%c(%d) ", 65 + i, i);
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%c(%d)", 65 + i, i);
        for(int j = 0; j < N; j++)
            printf("%5d", (W[i][j] == MaxInt) ? 0 : W[i][j]);
        printf("\n");
    }
}

int visited[MAX_N];

void clearVisited() {
    for (size_t i = 0; i < MAX_N; ++i) {
        visited[i] = 0;
    }
}

//task 2
void dfs(int startVertex, int W[MAX_N][MAX_N], int N) {
    int vertex;
    static int num = 0;
 
    visited[startVertex]=1;
    
    for (vertex=0; vertex<=N; vertex++)
    if ((W[startVertex][vertex]) && (!visited[vertex])) {
        printf("vertex[%d][%d]\n", startVertex, vertex);
        dfs(vertex, W, N);
    }
}

//task 3
void bfs(int startVertex, int W[MAX_N][MAX_N], int N) {
    int vertex;
    static int num = 0;
 
    visited[startVertex]=1;
    
    for (vertex=0; vertex<=N; vertex++)
    if ((W[vertex][startVertex]) && (!visited[vertex])) {
        printf("vertex[%d][%d]\n", vertex, startVertex);
        dfs(vertex, W, N);
    }
}

int main() {
    printf("Task 1: enter file name: ");
    char  inputStr[MAX_STR_LENGTH];
    scanf("%s", inputStr);
    int W[MAX_N][MAX_N];
    int N = load(W, inputStr);
    printMatrix(W, N);
    printf("Task 2: dfs:\n");
    clearVisited();
    dfs(0, W, N);
    printf("Task 3: bfs:\n");
    clearVisited();
    bfs(0, W, N);
}