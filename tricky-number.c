#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int nums, sum_big = 0, sum_small = 0;
    int result;   //кол-во чисел, сумма чисел больше данного, сумма чисел меньше данного, результат
    fscanf(fin, "%i", &nums);   //ввод количества чисел

    int index_mass [nums];  //массив индексов на выход
    int results_mass [2 * nums];    //массив результатов
    int digits_mass [nums];         //исходные данные
    int result_counter = 1;         //счетчик в массив результатов для результирующей разности
    int indexes_counter = 0;        //счетчик в массив результатов для индексов

    for (int i = 0; i < nums; ++i) {
        fscanf(fin, "%i", &digits_mass[i]);     //ввод чисел
        if (digits_mass[i] < 1){        //проверка входных чисел
            exit(0);
        }
    }

    for (int j = 0; j < nums; ++j) {
        for (int i = 0; i < nums; ++i) {
            if (digits_mass[i] > digits_mass[j]) {
                sum_big += digits_mass[i];      //суммирование элементов больше заданного
            } else if (digits_mass[i] < digits_mass[j]) {
                sum_small += digits_mass[i];        //суммирование элементов меньше заданного
            }
            result = abs(sum_small - sum_big);      //результат
        }
        results_mass[indexes_counter] = j + 1;      //вписываем в массив индекс
        results_mass[result_counter] = result;      //затем - результат для данного индекса
        result_counter += 2;        //увеличиваем счетчики
        indexes_counter += 2;
        sum_big = 0, sum_small = 0;     //обнуляем суммы для последующих членов
    }

    result = results_mass[1];       //берем первый член массива чтобы найти в нем минимальный результат
    int min_index = 1;              //берем за минимальный индекс 1, т.е. 1-й член минимален, если не выполнится цикл
    for (int m = 1; m <= indexes_counter; m += 2) {
        if (results_mass[m] < result) {
            result = results_mass [m];
            min_index = results_mass [m-1];      //индексы на 1
        }
    }
    int s = 0;      //поиск одинаковых результатов
    int counter_same_results = 0;
    for (int i1 = 1; i1 < nums*2; i1 += 2) {
        if (results_mass[i1] == result) {
            index_mass[s] = results_mass[i1 - 1];
            s++;
            counter_same_results++;     //если цикл выполнится хотя бы раз, выполнится условие ниже
        }
    }
    if (counter_same_results == 0) {
        fprintf(fout, "%i", min_index);
    } else {
        for (int k1 = 0; k1 < counter_same_results; ++k1) {
            fprintf(fout, "%i ", index_mass[k1]);
        }
    }
}