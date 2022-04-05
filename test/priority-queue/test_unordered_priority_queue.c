#include "test_unordered_priority_queue.h"

int init_suite_unordered_priority_queue(void) {
    return 0;
}

int clean_suite_unordered_priority_queue(void) {
    return 0;
}

CU_ErrorCode prepare_suite_unordered_priority_queue(void) {
    CU_pSuite unordered_priority_queue_suite = CU_add_suite("Unordered Priority Queue", init_suite_unordered_priority_queue, clean_suite_unordered_priority_queue);
    if (unordered_priority_queue_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(unordered_priority_queue_suite, "dsc_unordered_priority_queue_create", test_unordered_priority_queue_create) == NULL) ||
        (CU_add_test(unordered_priority_queue_suite, "dsc_unordered_priority_queue_free", test_unordered_priority_queue_free) == NULL) ||
        (CU_add_test(unordered_priority_queue_suite, "dsc_unordered_priority_queue_enqueue", test_unordered_priority_queue_enqueue) == NULL) ||
        (CU_add_test(unordered_priority_queue_suite, "dsc_unordered_priority_queue_dequeue", test_unordered_priority_queue_dequeue) == NULL) ||
        (CU_add_test(unordered_priority_queue_suite, "dsc_unordered_priority_queue_peek", test_unordered_priority_queue_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_unordered_priority_queue_create(void) {

}

void test_unordered_priority_queue_free(void) {

}

void test_unordered_priority_queue_enqueue(void) {

}

void test_unordered_priority_queue_dequeue(void) {

}

void test_unordered_priority_queue_peek(void) {

}