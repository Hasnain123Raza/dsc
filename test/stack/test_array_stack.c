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



void test_array_stack_create(void);
void test_array_stack_free(void);
void test_array_stack_resize(void);
void test_array_stack_push(void);
void test_array_stack_pop(void);
void test_array_stack_peek(void);