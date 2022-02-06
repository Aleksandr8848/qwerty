#include "libs/algorithms/array/array.h"
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"

void test_unordered_array_set_union1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_in1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    int value = 1;
    size_t exectedIndex = 0;
    size_t resIndex = unordered_array_set_in(&set1, value);
    assert (exectedIndex == resIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    int value = 3;
    size_t exectedIndex = 2;
    size_t resIndex = unordered_array_set_in(&set1, value);
    assert (exectedIndex == resIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    int value = 42;
    size_t exectedIndex = 3;
    size_t resIndex = unordered_array_set_in(&set1, value);
    assert (exectedIndex == resIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_insert1() {
    unordered_array_set set1 = unordered_array_set_create(10);
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set_insert(&set1, 4);
    unordered_array_set_insert(&set1, 3);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set1 = unordered_array_set_create(10);
    unordered_array_set_insert(&set1, -1);
    unordered_array_set_insert(&set1, 3);
    unordered_array_set_insert(&set1, 14);
    unordered_array_set_insert(&set1, 0);
    unordered_array_set_insert(&set1, -8);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {-8, -1, 0, 3, 14},
                                                  5);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {6, 2, 3, 1}, 4);
    unordered_array_set_deleteElement(&set1, 3);
    unordered_array_set expectedSet = unordered_array_set_create_from_array(
            (int[]) {6, 2, 1}, 3);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {6, 2, 3, 1}, 4);
    unordered_array_set_deleteElement(&set1, 6);
    unordered_array_set_deleteElement(&set1, 1);
    unordered_array_set_deleteElement(&set1, 3);
    unordered_array_set_deleteElement(&set1, 2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array(
            (int[]) {}, 0);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {6, 2, 3, 1}, 4);
    unordered_array_set_deleteElement(&set1, 7);
    unordered_array_set expectedSet = unordered_array_set_create_from_array(
            (int[]) {6, 2, 3, 1}, 4);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
    test_unordered_array_set_deleteElement3();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {4}, 1);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {4}, 1);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 3}, 2);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1}, 1);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3, 1}, 3);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {4, 3, 5}, 3);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 4, 5}, 4);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set universumSet =
            unordered_array_set_create_from_array(
                    (int[]) {4, 3, 5, 1, 2, 6, 7, 8}, 8);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array(
                    (int[]) {4, 5, 6, 7, 8}, 5);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert (unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
}

void test() {
    test_unordered_array_set_in();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

int main() {
    test();
    return 0;
}
