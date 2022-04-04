#include "test_array_queue.h"

int dsc_array_queue_resize(dsc_array_queue_t *array_queue, int capacity);

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



void test_array_queue_create(void) {

}

void test_array_queue_free(void) {

}

void test_array_queue_resize(void) {
    int test_data[31] = {};

    dsc_array_queue_t *queue = dsc_array_queue_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(queue);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 0);
    CU_ASSERT_EQUAL(queue->list->size, 0);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
    for (int i = 0; i < 15; i++) {
        CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + i), 0);
    }
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 15);
    CU_ASSERT_EQUAL(queue->list->size, 15);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
    for (int i = 0; i < 8; i++) {
        CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + i);
    }
    CU_ASSERT_EQUAL(queue->head, 8);
    CU_ASSERT_EQUAL(queue->tail, 15);
    CU_ASSERT_EQUAL(queue->list->size, 7);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
    for (int i = 0; i < 8; i++) {
        CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + i), 0);
    }
    CU_ASSERT_EQUAL(queue->head, 8);
    CU_ASSERT_EQUAL(queue->tail, 7);
    CU_ASSERT_EQUAL(queue->list->size, 15);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 15), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 16);
    CU_ASSERT_EQUAL(queue->list->size, 16);
    CU_ASSERT_EQUAL(queue->list->capacity, 32);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 8);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 15);
    CU_ASSERT_EQUAL(queue->list->size, 15);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 16), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 16);
    CU_ASSERT_EQUAL(queue->list->size, 16);
    CU_ASSERT_EQUAL(queue->list->capacity, 32);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 17), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 17);
    CU_ASSERT_EQUAL(queue->list->size, 17);
    CU_ASSERT_EQUAL(queue->list->capacity, 32);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 9);
    CU_ASSERT_EQUAL(queue->head, 1);
    CU_ASSERT_EQUAL(queue->tail, 17);
    CU_ASSERT_EQUAL(queue->list->size, 16);
    CU_ASSERT_EQUAL(queue->list->capacity, 32);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 10);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 15);
    CU_ASSERT_EQUAL(queue->list->size, 15);
    CU_ASSERT_EQUAL(queue->list->capacity, 16);
}

void test_array_queue_enqueue(void) {
    int test_data[5] = {};

    dsc_array_queue_t *queue = dsc_array_queue_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(queue);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 0), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 1);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 1), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 2);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 2), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 3);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 3), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 4);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 4), 0);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 5);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, NULL), -1);
    CU_ASSERT_EQUAL(queue->head, 0);
    CU_ASSERT_EQUAL(queue->tail, 5);
    CU_ASSERT_EQUAL(queue->list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(queue->list->data[1], test_data + 1);
    CU_ASSERT_EQUAL(queue->list->data[2], test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[3], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    dsc_array_queue_free(queue);
}

void test_array_queue_dequeue(void) {
    int test_data[5] = {};

    dsc_array_queue_t *queue = dsc_array_queue_create(NULL);
    CU_ASSERT_PTR_NOT_NULL_FATAL(queue);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 0), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 4), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 0);
    CU_ASSERT_EQUAL(queue->list->data[1], test_data + 1);
    CU_ASSERT_EQUAL(queue->list->data[2], test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[3], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 1);
    CU_ASSERT_EQUAL(queue->list->data[2], test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[3], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[3], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_dequeue(queue), test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 0), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 1), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 2), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 3), 0);
    CU_ASSERT_EQUAL(dsc_array_queue_enqueue(queue, test_data + 4), 0);
    CU_ASSERT_EQUAL(queue->list->data[5], test_data + 0);
    CU_ASSERT_EQUAL(queue->list->data[6], test_data + 1);
    CU_ASSERT_EQUAL(queue->list->data[7], test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[8], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[9], test_data + 4);
    CU_ASSERT_EQUAL(dsc_array_queue_resize(queue, 0), 0);
    CU_ASSERT_EQUAL(queue->list->data[0], test_data + 0);
    CU_ASSERT_EQUAL(queue->list->data[1], test_data + 1);
    CU_ASSERT_EQUAL(queue->list->data[2], test_data + 2);
    CU_ASSERT_EQUAL(queue->list->data[3], test_data + 3);
    CU_ASSERT_EQUAL(queue->list->data[4], test_data + 4);
    dsc_array_queue_free(queue);
}

void test_array_queue_peek(void) {

}