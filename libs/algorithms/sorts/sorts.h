//
// Created by Admin on 15.03.2022.
//

#ifndef COURSE_SORTS_H
#define COURSE_SORTS_H

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

// обменная сортировка (пузырёк)
void bubbleSort(int *a, size_t size);

long long getBubbleSortComps(int *a, size_t size);

// сортировка выбором
void selectionSort(int *a, size_t size);

long long getSelectionSortComps(int *a, size_t size);

// сортировка вставками
void insertionSort(int *a, size_t size);

long long getInsertionSortComps(int *a, size_t size);

// сортировка расчёской
void combSort(int *a, size_t size);

long long getCombSortComps(int *a, size_t size);

// сортировка Шелла
void shellSort(int *a, size_t size);

long long getShellSortComps(int *a, size_t size);

// цифровая сортировка
void LSD_sort(int *a, size_t n);

long long getLSD_sortComps(int *a, size_t n);

// быстрая сортировка
void stdlibQsort(int *a, size_t n);

#endif //COURSE_SORTS_H
