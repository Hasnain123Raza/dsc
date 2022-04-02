#include "test_linked_stack.h"

int init_suite_linked_stack(void) {
    return 0;
}

int clean_suite_linked_stack(void) {
    return 0;
}

CU_ErrorCode prepare_suite_linked_stack() {
    CU_pSuite linked_stack_suite = CU_add_suite("Linked Stack", init_suite_linked_stack, clean_suite_linked_stack);
    if (linked_stack_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(linked_stack_suite, "dsc_linked_stack_create", test_linked_stack_create) == NULL) ||
        (CU_add_test(linked_stack_suite, "dsc_linked_stack_free", test_linked_stack_free) == NULL) ||
        (CU_add_test(linked_stack_suite, "dsc_linked_stack_push", test_linked_stack_push) == NULL) ||
        (CU_add_test(linked_stack_suite, "dsc_linked_stack_pop", test_linked_stack_pop) == NULL) ||
        (CU_add_test(linked_stack_suite, "dsc_linked_stack_peek", test_linked_stack_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_linked_stack_create(void) {

}

void test_linked_stack_free(void) {

}

void test_linked_stack_push(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_linked_stack_t *stack = dsc_linked_stack_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 4), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, NULL), -1);
    CU_ASSERT_EQUAL(stack->head->data, test_data + 4);
    CU_ASSERT_EQUAL(stack->head->next->data, test_data + 3);
    CU_ASSERT_EQUAL(stack->head->next->next->data, test_data + 2);
    CU_ASSERT_EQUAL(stack->head->next->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(stack->head->next->next->next->next->data, test_data + 0);
    dsc_linked_stack_free(stack);
}

void test_linked_stack_pop(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_linked_stack_t *stack = dsc_linked_stack_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_push(stack, test_data + 4), 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), test_data + 4);
    CU_ASSERT_EQUAL(stack->head->data, test_data + 3);
    CU_ASSERT_EQUAL(stack->head->next->data, test_data + 2);
    CU_ASSERT_EQUAL(stack->head->next->next->data, test_data + 1);
    CU_ASSERT_EQUAL(stack->head->next->next->next->data, test_data + 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), test_data + 3);
    CU_ASSERT_EQUAL(stack->head->data, test_data + 2);
    CU_ASSERT_EQUAL(stack->head->next->data, test_data + 1);
    CU_ASSERT_EQUAL(stack->head->next->next->data, test_data + 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), test_data + 2);
    CU_ASSERT_EQUAL(stack->head->data, test_data + 1);
    CU_ASSERT_EQUAL(stack->head->next->data, test_data + 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), test_data + 1);
    CU_ASSERT_EQUAL(stack->head->data, test_data + 0);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), test_data + 0);
    CU_ASSERT_EQUAL(stack->head->data, NULL);
    CU_ASSERT_EQUAL(dsc_linked_stack_pop(stack), -1);
    dsc_linked_stack_free(stack);
}

void test_linked_stack_peek(void) {

}