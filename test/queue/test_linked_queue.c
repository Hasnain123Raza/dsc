#include "test_linked_queue.h"

int init_suite_linked_queue(void) {
    return 0;
}

int clean_suite_linked_queue(void) {
    return 0;
}

CU_ErrorCode prepare_suite_linked_queue() {
    CU_pSuite linked_queue_suite = CU_add_suite("Linked Queue", init_suite_linked_queue, clean_suite_linked_queue);
    if (linked_queue_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(linked_queue_suite, "dsc_linked_queue_create", test_linked_queue_create) == NULL) ||
        (CU_add_test(linked_queue_suite, "dsc_linked_queue_free", test_linked_queue_free) == NULL) ||
        (CU_add_test(linked_queue_suite, "dsc_linked_queue_enqueue", test_linked_queue_enqueue) == NULL) ||
        (CU_add_test(linked_queue_suite, "dsc_linked_queue_dequeue", test_linked_queue_dequeue) == NULL) ||
        (CU_add_test(linked_queue_suite, "dsc_linked_queue_peek", test_linked_queue_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_linked_queue_create(void);
void test_linked_queue_free(void);
void test_linked_queue_enqueue(void);
void test_linked_queue_dequeue(void);
void test_linked_queue_peek(void);