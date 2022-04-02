#include "test_array_stack.h"

int init_suite_array_stack(void) {
    return 0;
}

int clean_suite_array_stack(void) {
    return 0;
}

CU_ErrorCode prepare_suite_array_stack() {
    CU_pSuite array_stack_suite = CU_add_suite("Array Stack", init_suite_array_stack, clean_suite_array_stack);
    if (array_stack_suite == NULL) {
        return CU_get_error();
    }
    
    if ((CU_add_test(array_stack_suite, "dsc_array_stack_create", test_array_stack_create) == NULL) ||
        (CU_add_test(array_stack_suite, "dsc_array_stack_free", test_array_stack_free) == NULL) ||
        (CU_add_test(array_stack_suite, "dsc_array_stack_resize", test_array_stack_resize) == NULL) ||
        (CU_add_test(array_stack_suite, "dsc_array_stack_push", test_array_stack_push) == NULL) ||
        (CU_add_test(array_stack_suite, "dsc_array_stack_pop", test_array_stack_pop) == NULL) ||
        (CU_add_test(array_stack_suite, "dsc_array_stack_peek", test_array_stack_peek) == NULL)) {
        return CU_get_error();
    }
    
    return CUE_SUCCESS;
}



void test_array_stack_create(void) {

}

void test_array_stack_free(void) {

}

void test_array_stack_resize(void) {
    
}

void test_array_stack_push(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_array_stack_t *stack = dsc_array_stack_create(0, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 4), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, NULL), -1);
    CU_ASSERT_EQUAL(stack->data[0], test_data + 0);
    CU_ASSERT_EQUAL(stack->data[1], test_data + 1);
    CU_ASSERT_EQUAL(stack->data[2], test_data + 2);
    CU_ASSERT_EQUAL(stack->data[3], test_data + 3);
    CU_ASSERT_EQUAL(stack->data[4], test_data + 4);
    dsc_array_stack_free(stack);
}

void test_array_stack_pop(void) {
    int test_data[] = {0, 1, 2, 3, 4};

    dsc_array_stack_t *stack = dsc_array_stack_create(0, NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(stack);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_push(stack, test_data + 4), 0);
    CU_ASSERT_EQUAL(dsc_array_stack_pop(stack), test_data + 4);
    CU_ASSERT_EQUAL(stack->data[0], test_data + 0);
    CU_ASSERT_EQUAL(stack->data[1], test_data + 1);
    CU_ASSERT_EQUAL(stack->data[2], test_data + 2);
    CU_ASSERT_EQUAL(stack->data[3], test_data + 3);
    CU_ASSERT_EQUAL(dsc_array_stack_pop(stack), test_data + 3);
    CU_ASSERT_EQUAL(stack->data[0], test_data + 0);
    CU_ASSERT_EQUAL(stack->data[1], test_data + 1);
    CU_ASSERT_EQUAL(stack->data[2], test_data + 2);
    CU_ASSERT_EQUAL(dsc_array_stack_pop(stack), test_data + 2);
    CU_ASSERT_EQUAL(stack->data[0], test_data + 0);
    CU_ASSERT_EQUAL(stack->data[1], test_data + 1);
    CU_ASSERT_EQUAL(dsc_array_stack_pop(stack), test_data + 1);
    CU_ASSERT_EQUAL(stack->data[0], test_data + 0);
    CU_ASSERT_EQUAL(dsc_array_stack_pop(stack), test_data + 0);
    CU_ASSERT_PTR_NULL(dsc_array_stack_pop(stack));
    dsc_array_stack_free(stack);
}

void test_array_stack_peek(void) {

}