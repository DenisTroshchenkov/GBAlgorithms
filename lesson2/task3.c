/*
 *   @author Denis Troschenkov
 *   
 *   Homework №2
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

//Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У
//исполнителя две команды, каждой присвоен номер:
//1. Прибавь 1.
//2. Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.
//Определить, сколько существует программ, которые преобразуют число 3 в число 20:
//а. С использованием массива.
//b. *С использованием рекурсии.


int with_array(int start_value, int last_value) {
    //каким образом здесь лучше подсчитать количество выделяемой зареание памяти ? 
    int *interim_value = (int*) malloc(pow(2, last_value));
    interim_value[0] = start_value + 1;
    interim_value[1] = start_value * 2;
    int array_size = 2;
    int result = 0;
    for (int i = 0; i < array_size; ++i) {
        int with_sum = interim_value[i] + 1;
        int with_multi = interim_value[i] * 2;
        if (with_sum == last_value) {
            ++result;
        } else if (with_sum < last_value) {
            interim_value[array_size] = with_sum;
            ++array_size;
        } 
        
        if (with_multi == last_value) {
            ++result;
        }  else if (with_multi < last_value) {
            interim_value[array_size] = with_multi;
            ++array_size;
        } 
    }
    free(interim_value);
    return result;
}


int with_recursion(int start_value, int last_value) {
    if (start_value == last_value) {
        return 1;
    } else if (start_value > last_value) {
        return 0;
    }
    return with_recursion(start_value + 1, last_value) + with_recursion(start_value * 2, last_value);
}

int main () {
    int res = 0;
    int start_value = 3;
    int last_value = 20;
    //а. С использованием массива.
    res = with_array(start_value, last_value);
    printf("a: %d\n", res);
    //b. *С использованием рекурсии.
    res = with_recursion(start_value, last_value);
    printf("b: %d\n", res);
    return 0;
}

