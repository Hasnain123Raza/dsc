#include "test_array_queue.h"

int init_suite_array_queue(void) {
    return 0;
}

int clean_suite_array_queue(void) {
    return 0;
}

CU_ErrorCode prepare_suite_array_queue() {
    CU_pSuite array_queue_suite = CU_add_suite("Array Queue", init_suite_array_queue, clean_suite_array_queue);
    if (array_queue_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(array_queue_suite, "dsc_array_queue_create", test_array_queue_create) == NULL) ||
        (CU_add_test(array_queue_suite, "dsc_array_queue_free", test_array_queue_free) == NULL) ||
        (CU_add_test(array_queue_suite, "dsc_array_queue_resize", test_array_queue_resize) == NULL) ||
        (CU_add_test(array_queue_suite, "dsc_array_queue_enqueue", test_array_queue_enqueue) == NULL) ||
        (CU_add_test(array_queue_suite, "dsc_array_queue_dequeue", test_array_queue_dequeue) == NULL) ||
        (CU_add_test(array_queue_suite, "dsc_array_queue_peek", test_array_queue_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_array_queue_create(void);
void test_array_queue_free(void);
void test_array_queue_resize(void);
void test_array_queue_enqueue(void);
void test_array_queue_dequeue(void);
void test_array_queue_peek(void);