#include "test_multilevel_priority_queue.h"

int init_suite_multilevel_priority_queue(void) {
    return 0;
}

int clean_suite_multilevel_priority_queue(void) {
    return 0;
}

CU_ErrorCode prepare_suite_multilevel_priority_queue(void) {
    CU_pSuite multilevel_priority_queue_suite = CU_add_suite("Multilevel Priority Queue", init_suite_multilevel_priority_queue, clean_suite_multilevel_priority_queue);
    if (multilevel_priority_queue_suite == NULL) {
        return CU_get_error();
    }

    if ((CU_add_test(multilevel_priority_queue_suite, "dsc_multilevel_priority_queue_create", test_multilevel_priority_queue_create) == NULL) ||
        (CU_add_test(multilevel_priority_queue_suite, "dsc_multilevel_priority_queue_free", test_multilevel_priority_queue_free) == NULL) ||
        (CU_add_test(multilevel_priority_queue_suite, "dsc_multilevel_priority_queue_enqueue", test_multilevel_priority_queue_enqueue) == NULL) ||
        (CU_add_test(multilevel_priority_queue_suite, "dsc_multilevel_priority_queue_dequeue", test_multilevel_priority_queue_dequeue) == NULL) ||
        (CU_add_test(multilevel_priority_queue_suite, "dsc_multilevel_priority_queue_peek", test_multilevel_priority_queue_peek) == NULL)) {
        return CU_get_error();
    }

    return CUE_SUCCESS;
}



void test_multilevel_priority_queue_create(void) {

}

void test_multilevel_priority_queue_free(void) {

}

void test_multilevel_priority_queue_enqueue(void) {

}

void test_multilevel_priority_queue_dequeue(void) {

}

void test_multilevel_priority_queue_peek(void) {

}