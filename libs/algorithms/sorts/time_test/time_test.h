//
// Created by Admin on 15.03.2022.
//

#ifndef COURSE_TIME_TEST_H
#define COURSE_TIME_TEST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
    clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort)(int *a, size_t n); // указатель на функцию
                                    // сортировки
    char name[64];                  // имя сортировки,
                                    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate)(int *a, size_t n); // указатель на функцию
                                        // генерации последоват.
    char name[64];                      // имя генератора,
                                        // используемое при выводе
} GeneratingFunc;

typedef struct SortFuncCompares {
    long long (*sort)(int *a, size_t n);

    char name[64];
} SortFuncCompares;

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName);

void checkCompares(long long (*sortFunc)(int *, size_t),
                   void (*generateFunc)(int*, size_t),
                   size_t size, char *experimentName);

void timeExperiment();

void comparesExperiment();

#endif //COURSE_TIME_TEST_H
