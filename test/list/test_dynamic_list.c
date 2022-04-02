#include "test_dynamic_list.h"

int init_suite_dynamic_list(void) {
    return 0;
}

int clean_suite_dynamic_list(void) {
    return 0;
}

CU_ErrorCode prepare_suite_dynamic_list() {
    CU_pSuite dynamic_list_suite = CU_add_suite("Dynamic List", init_suite_dynamic_list, clean_suite_dynamic_list);
    if (dynamic_list_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(dynamic_list_suite, "dsc_dynamic_list_create", test_dynamic_list_create) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_free", test_dynamic_list_free) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_resize", test_dynamic_list_resize) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_insert", test_dynamic_list_insert) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_remove", test_dynamic_list_remove) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_get", test_dynamic_list_set) == NULL) ||
        (CU_add_test(dynamic_list_suite, "dsc_dynamic_list_set", test_dynamic_list_get) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_dynamic_list_create(void) {
    dsc_dynamic_list_t *list = dsc_dynamic_list_create(0, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_PTR_NOT_NULL(list->data);
    CU_ASSERT_EQUAL(list->capacity, DSC_DYNAMIC_LIST_INITIAL_CAPACITY);
    dsc_dynamic_list_free(list);

    list = dsc_dynamic_list_create(64, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(list->capacity, 64);
    dsc_dynamic_list_free(list);
}

void test_dynamic_list_free(void) {
    dsc_dynamic_list_t *list = dsc_dynamic_list_create(0, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    dsc_dynamic_list_free(list);
}

void test_dynamic_list_resize(void) {
    dsc_dynamic_list_t *list = dsc_dynamic_list_create(64, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(list->capacity, 64);
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 128), 0);
    CU_ASSERT_EQUAL(list->capacity, 128);
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 64), 0);
    CU_ASSERT_EQUAL(list->capacity, 64);
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 0), 0);
    CU_ASSERT_EQUAL(list->capacity, DSC_DYNAMIC_LIST_INITIAL_CAPACITY);
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 64), 0);
    CU_ASSERT_EQUAL(list->capacity, 64);
    list->size = 64;
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 32), -1);
    CU_ASSERT_EQUAL(list->capacity, 64);
    list->size = 32;
    CU_ASSERT_EQUAL(dsc_dynamic_list_resize(list, 32), 0);
    CU_ASSERT_EQUAL(list->capacity, 32);
    dsc_dynamic_list_free(list);
}

void test_dynamic_list_insert(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_dynamic_list_t *list = dsc_dynamic_list_create(64, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 0, test_data), 0);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_EQUAL(list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 1, test_data + 1), 0);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_EQUAL(list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(list->data[1], test_data + 1);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 1, test_data + 2), 0);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(list->data[1], test_data + 2);
    CU_ASSERT_EQUAL(list->data[2], test_data + 1);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 4, test_data + 3), -1);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(list->data[1], test_data + 2);
    CU_ASSERT_EQUAL(list->data[2], test_data + 1);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 0, NULL), -1);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(list->data[1], test_data + 2);
    CU_ASSERT_EQUAL(list->data[2], test_data + 1);
    dsc_dynamic_list_free(list);

    list = dsc_dynamic_list_create(0, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    for (int i = 0; i < DSC_DYNAMIC_LIST_INITIAL_CAPACITY + 1; i++) {
        CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, i, test_data + i), 0);
    }
    CU_ASSERT_EQUAL(list->size, DSC_DYNAMIC_LIST_INITIAL_CAPACITY + 1);
    CU_ASSERT_EQUAL(list->capacity, DSC_DYNAMIC_LIST_INITIAL_CAPACITY * 2);
    dsc_dynamic_list_free(list);
}

void test_dynamic_list_remove(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_dynamic_list_t *list = dsc_dynamic_list_create(64, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 0, test_data), 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 1, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 2, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 3, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_dynamic_list_insert(list, 4, test_data + 4), 0);
    CU_ASSERT_EQUAL(list->size, 5);
    CU_ASSERT_NOT_EQUAL(dsc_dynamic_list_remove(list, 0), 0);
    CU_ASSERT_EQUAL(list->size, 4);
    CU_ASSERT_EQUAL(list->data[0], test_data + 1);
    CU_ASSERT_EQUAL(list->data[1], test_data + 2);
    CU_ASSERT_EQUAL(list->data[2], test_data + 3);
    CU_ASSERT_EQUAL(list->data[3], test_data + 4);
    CU_ASSERT_NOT_EQUAL(dsc_dynamic_list_remove(list, 3), 0);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->data[0], test_data + 1);
    CU_ASSERT_EQUAL(list->data[1], test_data + 2);
    CU_ASSERT_EQUAL(list->data[2], test_data + 3);
    CU_ASSERT_NOT_EQUAL(dsc_dynamic_list_remove(list, 1), 0);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_EQUAL(list->data[0], test_data + 1);
    CU_ASSERT_EQUAL(list->data[1], test_data + 3);
    CU_ASSERT_EQUAL(dsc_dynamic_list_remove(list, 2), 0);
    CU_ASSERT_EQUAL(list->size, 2);
    dsc_dynamic_list_free(list);
}

void test_dynamic_list_set(void) {

}

void test_dynamic_list_get(void) {

}