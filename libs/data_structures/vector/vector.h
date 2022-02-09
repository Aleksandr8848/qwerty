//
// Created by Admin on 08.02.2022.
//
//
#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdint.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

// изменяет количество памяти,
// выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// освобождает память, выделенную под
// неиспользуемые элементы.
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору.
void deleteVector(vector *v);

// проверяет является ли вектор пустым.
bool isEmpty(vector *v);

// проверяет является ли вектор полным.
bool isFull(vector *v);

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора.
void popBack(vector *v);
#endif //COURSE_VECTOR_H
