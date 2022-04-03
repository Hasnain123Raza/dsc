#include "test_singly_linked_list.h"

int init_suite_singly_linked_list(void) {
    return 0;
}

int clean_suite_singly_linked_list(void) {
    return 0;
}

CU_ErrorCode prepare_suite_singly_linked_list() {
    CU_pSuite singly_linked_list_suite = CU_add_suite("Singly Linked List", init_suite_singly_linked_list, clean_suite_singly_linked_list);
    if (singly_linked_list_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_create", test_singly_linked_list_create) == NULL) ||
        (CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_free", test_singly_linked_list_free) == NULL) ||
        (CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_insert", test_singly_linked_list_insert) == NULL) ||
        (CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_remove", test_singly_linked_list_remove) == NULL) ||
        (CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_set", test_singly_linked_list_set) == NULL) ||
        (CU_add_test(singly_linked_list_suite, "dsc_singly_linked_list_get", test_singly_linked_list_get) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_singly_linked_list_create(void) {
    dsc_singly_linked_list_t *list = dsc_singly_linked_list_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_PTR_NULL(list->head);
    CU_ASSERT_PTR_NULL(list->tail);
    CU_ASSERT_EQUAL(list->size, 0);
    dsc_singly_linked_list_free(list);
}

void test_singly_linked_list_free(void) {
    dsc_singly_linked_list_t *list = dsc_singly_linked_list_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    dsc_singly_linked_list_free(list);
}

void test_singly_linked_list_insert(void) {
    int test_data[5] = {};

    dsc_singly_linked_list_t *list = dsc_singly_linked_list_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 0, test_data), 0);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_EQUAL(list->head, list->tail);
    CU_ASSERT_EQUAL(list->head->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 1, test_data + 1), 0);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_NOT_EQUAL(list->head, list->tail);
    CU_ASSERT_EQUAL(list->head->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 2, test_data + 2), 0);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->head->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 0, test_data + 3), 0);
    CU_ASSERT_EQUAL(list->size, 4);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 2, test_data + 4), 0);
    CU_ASSERT_EQUAL(list->size, 5);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 4);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 6, test_data), -1);
    CU_ASSERT_EQUAL(list->size, 5);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 4);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, -1, test_data), -1);
    CU_ASSERT_EQUAL(list->size, 5);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 4);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->next, NULL);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 6, NULL), -1);
    CU_ASSERT_EQUAL(list->size, 5);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 4);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->next->next->next, NULL);
    dsc_singly_linked_list_free(list);
}

void test_singly_linked_list_remove(void) {
    int test_data[5] = {};

    dsc_singly_linked_list_t *list = dsc_singly_linked_list_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(list);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 0, test_data), 0);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 1, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 2, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 3, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_insert(list, 4, test_data + 4), 0);
    CU_ASSERT_NOT_EQUAL(dsc_singly_linked_list_remove(list, 0), 0);
    CU_ASSERT_EQUAL(list->size, 4);
    CU_ASSERT_EQUAL(list->head->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->next->next->data, test_data + 4);
    CU_ASSERT_EQUAL(list->head->next->next->next->next, NULL);
    CU_ASSERT_NOT_EQUAL(dsc_singly_linked_list_remove(list, 3), 0);
    CU_ASSERT_EQUAL(list->size, 3);
    CU_ASSERT_EQUAL(list->head->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 2);
    CU_ASSERT_EQUAL(list->head->next->next->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->next->next, NULL);
    CU_ASSERT_NOT_EQUAL(dsc_singly_linked_list_remove(list, 1), 0);
    CU_ASSERT_EQUAL(list->size, 2);
    CU_ASSERT_EQUAL(list->head->data, test_data + 1);
    CU_ASSERT_EQUAL(list->head->next->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next->next, NULL);
    CU_ASSERT_NOT_EQUAL(dsc_singly_linked_list_remove(list, 0), 0);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next, NULL);
    CU_ASSERT_EQUAL(list->head, list->tail);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_remove(list, -1), 0);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next, NULL);
    CU_ASSERT_EQUAL(list->head, list->tail);
    CU_ASSERT_EQUAL(dsc_singly_linked_list_remove(list, 1), 0);
    CU_ASSERT_EQUAL(list->size, 1);
    CU_ASSERT_EQUAL(list->head->data, test_data + 3);
    CU_ASSERT_EQUAL(list->head->next, NULL);
    CU_ASSERT_EQUAL(list->head, list->tail);
    CU_ASSERT_NOT_EQUAL(dsc_singly_linked_list_remove(list, 0), 0);
    CU_ASSERT_EQUAL(list->size, 0);
    CU_ASSERT_EQUAL(list->head, NULL);
    CU_ASSERT_EQUAL(list->tail, NULL);
    dsc_singly_linked_list_free(list);
}

void test_singly_linked_list_set(void) {

}

void test_singly_linked_list_get(void) {

}