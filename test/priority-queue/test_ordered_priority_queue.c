#include "test_ordered_priority_queue.h"

int init_suite_ordered_priority_queue(void) {
    return 0;
}

int clean_suite_ordered_priority_queue(void) {
    return 0;
}

CU_ErrorCode prepare_suite_ordered_priority_queue(void) {
    CU_pSuite ordered_priority_queue_suite = CU_add_suite("Ordered Priority Queue", init_suite_ordered_priority_queue, clean_suite_ordered_priority_queue);
    if (ordered_priority_queue_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(ordered_priority_queue_suite, "dsc_ordered_priority_queue_create", test_ordered_priority_queue_create) == NULL) ||
        (CU_add_test(ordered_priority_queue_suite, "dsc_ordered_priority_queue_free", test_ordered_priority_queue_free) == NULL) ||
        (CU_add_test(ordered_priority_queue_suite, "dsc_ordered_priority_queue_enqueue", test_ordered_priority_queue_enqueue) == NULL) ||
        (CU_add_test(ordered_priority_queue_suite, "dsc_ordered_priority_queue_dequeue", test_ordered_priority_queue_dequeue) == NULL) ||
        (CU_add_test(ordered_priority_queue_suite, "dsc_ordered_priority_queue_peek", test_ordered_priority_queue_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_ordered_priority_queue_create(void) {

}

void test_ordered_priority_queue_free(void) {

}

void test_ordered_priority_queue_enqueue(void) {

}

void test_ordered_priority_queue_dequeue(void) {

}

void test_ordered_priority_queue_peek(void) {

}