#ifndef DSC_UNORDERED_PRIORITY_QUEUE_H
#define DSC_UNORDERED_PRIORITY_QUEUE_H

#include "singly_linked_list.h"

typedef int (*dsc_unordered_priority_queue_compare_func)(void *, void *);
typedef void (*dsc_unordered_priority_queue_free_func)(void *);

typedef struct {
    dsc_singly_linked_list_t *list;
    dsc_unordered_priority_queue_compare_func compare_func;
} dsc_unordered_priority_queue_t;

dsc_unordered_priority_queue_t *dsc_unordered_priority_queue_create(dsc_unordered_priority_queue_compare_func compare_func, dsc_unordered_priority_queue_free_func free_func);
void dsc_unordered_priority_queue_free(dsc_unordered_priority_queue_t *unordered_priority_queue);

int dsc_unordered_priority_queue_enqueue(dsc_unordered_priority_queue_t *unordered_priority_queue, void *data);
void *dsc_unordered_priority_queue_dequeue(dsc_unordered_priority_queue_t *unordered_priority_queue);
void *dsc_unordered_priority_queue_peek(dsc_unordered_priority_queue_t *unordered_priority_queue);

#endif