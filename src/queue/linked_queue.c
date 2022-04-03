#include "linked_queue.h"

dsc_linked_queue_t *dsc_linked_queue_create(dsc_linked_queue_free_func free_func) {
    return dsc_singly_linked_list_create(free_func);
}

void dsc_linked_queue_free(dsc_linked_queue_t *linked_queue) {
    dsc_singly_linked_list_free(linked_queue);
}



int dsc_linked_queue_enqueue(dsc_linked_queue_t *linked_queue, void *data) {
    return dsc_singly_linked_list_insert(linked_queue, linked_queue->size, data);
}

void *dsc_linked_queue_dequeue(dsc_linked_queue_t *linked_queue) {
    return dsc_singly_linked_list_remove(linked_queue, 0);
}

void *dsc_linked_queue_peek(dsc_linked_queue_t *linked_queue) {
    return dsc_singly_linked_list_get(linked_queue, 0);
}