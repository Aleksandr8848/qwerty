//
// Created by Admin on 23.12.2021.
//
#include <malloc.h>
#include <stdlib.h>
#include "ordered_array_set.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    qsort(set.data, set.size, sizeof(int), compare_ints);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        ordered_array_set_isAbleAppend(set);
        size_t posInsertElement = binarySearchMoreOrEqual_(set->data, set->size, value);
        insert_(set->data, &set->size, posInsertElement, value);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size) {
        size_t posDeleteElement = ordered_array_set_in(set, value);
        deleteByPosSaveOrder_(set->data, &set->size, posDeleteElement);
        ordered_array_set_shrinkToFit(set);
    }
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set
set) {
    if (subset.size == 0)
        return true;
    size_t indexFirst = binarySearch_(set.data, set.size, subset.data[0]);
    size_t i = 0;
    size_t j = indexFirst;
    while (i < subset.size && j < set.size) {
        if (set.data[j] != subset.data[i])
            return false;
        i++;
        j++;
    }
    return i == subset.size;
}


ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size) {
        if (set1.data[set1Read] < set2.data[set2Read])
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            append_(setResult.data, &setResult.size, set2.data[set2Read++]);
        else {
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
            set2Read++;
        }
    }
    while (set1Read < set1.size)
        append_(setResult.data, &setResult.size, set1.data[set1Read++]);
    while (set2Read < set2.size)
        append_(setResult.data, &setResult.size, set2.data[set2Read++]);
    return setResult;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1,
                                                 ordered_array_set set2) {
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size)
        if (set1.data[set1Read] < set2.data[set2Read])
            set1Read++;
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
            set2Read++;
        }
    return setResult;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1,
                                               ordered_array_set set2) {
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size)
        if (set1.data[set1Read] < set2.data[set2Read])
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            set1Read++;
            set2Read++;
        }

    while (set1Read < set1.size)
        append_(setResult.data, &setResult.size, set1.data[set1Read++]);
    return setResult;
}

ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set setDeff1 = ordered_array_set_difference(set1, set2);
    ordered_array_set setDeff2 = ordered_array_set_difference(set2, set1);
    ordered_array_set setResult = ordered_array_set_union(setDeff1, setDeff2);
    ordered_array_set_delete(setDeff1);
    ordered_array_set_delete(setDeff2);
    return setResult;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set,
                                               ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (int i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}