#include "array_queue.h"

dsc_array_queue_t *dsc_array_queue_create(dsc_array_queue_free_func free_func) {
    dsc_dynamic_list_t *list = dsc_dynamic_list_create(0, free_func);
    if (list == NULL) {
        return NULL;
    }

    dsc_array_queue_t *queue = (dsc_array_queue_t *)malloc(sizeof(dsc_array_queue_t));
    if (queue == NULL) {
        dsc_dynamic_list_free(list);
        return NULL;
    }

    queue->list = list;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

void dsc_array_queue_free(dsc_array_queue_t *array_queue) {
    if (array_queue == NULL) {
        return;
    }

    dsc_dynamic_list_free(array_queue->list);
    free(array_queue);
}

int dsc_array_queue_resize(dsc_array_queue_t *array_queue, int capacity) {
    if (capacity < DSC_DYNAMIC_LIST_INITIAL_CAPACITY) {
        capacity = DSC_DYNAMIC_LIST_INITIAL_CAPACITY;
    }

    if (array_queue == NULL || capacity < array_queue->list->size) {
        return -1;
    }

    void **new_data = (void **)malloc(sizeof(void *) * capacity);
    if (new_data == NULL) {
        return -1;
    }

    int old_capacity = array_queue->list->capacity;
    void **old_data = array_queue->list->data;
    int old_index = array_queue->head;
    int new_index = 0;
    while (old_index != array_queue->tail) {
        new_data[new_index] = old_data[old_index];
        old_index = (old_index + 1) % old_capacity;
        new_index++;
    }

    array_queue->list->data = new_data;
    array_queue->list->capacity = capacity;
    array_queue->head = 0;
    array_queue->tail = new_index;

    free(old_data);

    return 0;
}



int dsc_array_queue_enqueue(dsc_array_queue_t *array_queue, void *data) {
    if (array_queue == NULL || data == NULL) {
        return -1;
    }

    if (array_queue->list->size + 1 == array_queue->list->capacity) {
        if (dsc_array_queue_resize(array_queue, array_queue->list->capacity << 1) != 0) {
            return -1;
        }
    }

    array_queue->list->data[array_queue->tail] = data;
    array_queue->tail = (array_queue->tail + 1) % array_queue->list->capacity;
    array_queue->list->size++;

    return 0;
}

void *dsc_array_queue_dequeue(dsc_array_queue_t *array_queue) {
    if (array_queue == NULL || array_queue->list->size == 0) {
        return NULL;
    }

    void *data = array_queue->list->data[array_queue->head];
    array_queue->head = (array_queue->head + 1) % array_queue->list->capacity;
    array_queue->list->size--;

    if (array_queue->list->size < array_queue->list->capacity >> 1 && array_queue->list->capacity > DSC_DYNAMIC_LIST_INITIAL_CAPACITY) {
        dsc_array_queue_resize(array_queue, array_queue->list->capacity >> 1);
    }

    return data;
}

void *dsc_array_queue_peek(dsc_array_queue_t *array_queue) {
    if (array_queue == NULL || array_queue->list->size == 0) {
        return NULL;
    }

    return dsc_dynamic_list_get(array_queue->list, array_queue->head);
}