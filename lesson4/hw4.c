/*
* @author Troschenkov Denis
*/

// 1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
// Карта для примера:
// 3 3
// 1 1 1
// 0 1 0
// 0 1 0

// 2. Решить задачу о нахождении длины максимальной подпоследовательности с помощью матрицы.

// 3. ***Требуется обойти конём шахматную доску размером N × M, пройдя через все поля доски по одному разу. 
// Здесь алгоритм решения такой же, как и в задаче о 8 ферзях. Разница только в проверке положения коня.


#include <stdio.h>
#include <string.h>
#define N 3
#define M 3

void Print2(int n, int m, int a[N][M]) {
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void initMap (int map[N][M]) {
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < M; j++)
            map[i][j] = 1;
    }
    map[1][0] = 0;
    map[2][0] = 0;
    //map[1][2] = 0;
   // map[2][2] = 0;
}

void task1() {
    int A[N][M];
    int map[N][M];
    initMap(map);
    int i, j;
    for(j = 0; j < M; j++) { 
        if ( map[0][j] == 0 ) {
            A[0][j] = 0; 
        } else if  (j == 0) {
            A[0][j] = 1;
        }
        else {
            A[0][j] = A[0][j - 1];
        }
    }
    for(i = 1; i < N; i++)
    {
        if ( map[i][0] == 0 ) {
            A[i][0] = 0; 
        } else if  (i == 0) {
            A[i][0] = 1;
        }
        else {
            A[i][0] = A[i - 1][0];
        }

        for(j = 1; j < M; j++) {
            if (map[i][j] == 0) {
                A[i][j] = 0;
            } else {
                A[i][j] = A[i][j-1] + A[i-1][j];
            }
        }
    }
    Print2(N, M, A);
}

const int m_length = 10;
const int n_length = 10;
const char* m = "geekbrains";
const char* n = "geekmainds";  

void Print3(int n, int m, int a[m_length][n_length]) {
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

void task2() { 
    int lcs[m_length][n_length];

    for (int i = 1; i < m_length; ++i) {
        lcs[i][0] = 0;
    }
    
    for (int j = 0; j < n_length; ++j) {
        lcs[0][j] = 0;
    }

    for (int i = 1; i < m_length; ++i) {
        for ( int j = 1; j < n_length; ++j) { 
            if (m[i] == n[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else if (lcs[i - 1][j] >= lcs[i][j - 1]) {
                lcs[i][j] = lcs[i - 1][j];
            } else {
                lcs[i][j] = lcs[i][j - 1];
            }
        }
    }
    Print3(m_length, n_length, lcs);
}

int main(int argc, char *argv[])
{
    task1();
    puts("");
    task2();
    return 0;
}
