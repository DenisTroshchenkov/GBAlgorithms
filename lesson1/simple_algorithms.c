/*
 *   @author Denis Troschenkov
 *   
 *   Homework №1
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, 
//имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
void solution10 ();
//11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, 
//оканчивающихся на 8.
void solution11 ();
//12. Написать функцию нахождения максимального из трех чисел.
void solution12 ();
//13. * Написать функцию, генерирующую случайное число от 1 до 100.
//с использованием стандартной функции rand()
//без использования стандартной функции rand()
void solution13 ();
//14. * Автоморфные числа. Натуральное число называется автоморфным, 
//если оно равно последним цифрам своего квадрата. Например, 25 \ :sup: 2 = 625. Напишите программу, 
//которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.
void solution14 ();
void menu();

int main () {
    int sel = 0;
    do {
        menu ();
        scanf ( "%i", &sel );
        switch (sel) {
            case 10:
                solution10 ();
                break;
            case 11:
                solution11 ();
                break;
            case 12:
                solution12 ();
                break;
            case 13:
                solution13 ();
                break;
            case 14:
                solution14 ();
                break;
            case 0:
              printf ( "Bye-bye\n" );
              break;
            default:
              printf ( "Wrong selected\n" );
        }
    } while ( sel != 0 );
    return 0;
}

void solution10 () {
    int sel = 0;    
    printf ( "Введите число N > 0: " );
    scanf ( "%i", &sel );
    if ( sel <= 0 ) {
        printf ( "Ошибка: Число меньше нуля или равно нулю\n" );
        return;
    }
    while ( sel > 0 ) {
        if ( (sel % 10) % 2 ) {
            printf ( "True\n" );
            return;
        }
        sel /= 10; 
    }
    printf ( "False\n" );
}

void solution11 () {
    printf ( "Введите число\n" );
    printf ( "Для выхода нажмите: 0\n" );
    int sel = 0;
    int totalCount = 0;
    int totalSum = 0; 
    while (1) {
        scanf ( "%i", &sel );
        if ( sel == 0 ) {
            break;
        }
        if ( (sel % 10) == 8) {
            totalSum += sel;
            ++totalCount;
        }
    }
    if ( totalCount == 0 ) {
        printf ( "Avg: 0\n" );
        return;
    }
    int avg = totalSum / totalCount;
    printf ( "Avg: %d\n", avg );
}

void solution12 () {
    const int num = 3;
    int values[num];
    printf ( "Введите число a: \n" );
    scanf ( "%i", &values[0] );
    printf ( "Введите число b: \n" );
    scanf ( "%i", &values[1] );
    printf ( "Введите число c: \n" );
    scanf ( "%i", &values[2] );
    int max_value = values[0];
    for ( int i = 1; i < num; ++i ) { 
        if ( max_value < values[i] ) {
            max_value = values[i];
        }
    }
    printf("Max value %d: \n", max_value);
}

int my_rand() {
    time_t seconds;
    seconds = time(NULL);
    static int x = 1;
    int a, b, m;
    int res = 0;
    m = 100;
    a = (int) seconds % 10;
    b = (int) seconds % 100;
    x = (a * b + b ) % m;
    return x;    
}

void solution13 () {
    printf ( "1 - С rand\n" );
    printf ( "2 - Без rand\n" );
    int sel = 0;
    scanf ( "%i", &sel );
    int rand_value;
    switch (sel)
    {
        case 1:
            rand_value = rand() % 100; 
            break;
         case 2:
            rand_value = my_rand();
            break;
        default:
            printf("Task 13: Wrong selected\n");
            return;
    }
    printf("Rand value: %d\n", rand_value);
}

void solution14 () {
    int value = 0;    
    printf ( "Введите число N > 0: " );
    scanf ( "%i", &value );
    if ( value <= 0 ) {
        printf ( "Ошибка: Число меньше нуля или равно нулю\n" );
        return;
    }
    while(value) {
        int num_in_value = 0;
        int temp_value = value;
        while (temp_value) {
            ++num_in_value;
            temp_value /= 10;
        }
        int value_in_pow = value * value;
        int last_num = value_in_pow % (int) pow(10, (double) num_in_value);
        if ( value == last_num ) {
            printf ("%d\n", value);
        }
        --value;   
    }
}

void menu () {
    printf ( "10 - task10\n" );
    printf ( "11 - task11\n" );
    printf ( "12 - task12\n" );
    printf ( "13 - task13\n" );
    printf ( "14 - task14\n" );
    printf ( "0 - exit\n" );
}
