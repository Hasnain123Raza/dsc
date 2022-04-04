#ifndef DSC_ORDERED_PRIORITY_QUEUE_H
#define DSC_ORDERED_PRIORITY_QUEUE_H

#include "dynamic_list.h"

typedef int (*dsc_ordered_priority_queue_compare_func)(void *, void *);
typedef void (*dsc_ordered_priority_queue_free_func)(void *);

typedef struct {
    dsc_dynamic_list_t *list;
    dsc_ordered_priority_queue_compare_func compare_func;
} dsc_ordered_priority_queue_t;

dsc_ordered_priority_queue_t *dsc_ordered_priority_queue_create(dsc_ordered_priority_queue_compare_func compare_func, dsc_ordered_priority_queue_free_func free_func);
void dsc_ordered_priority_queue_free(dsc_ordered_priority_queue_t *ordered_priority_queue);

int dsc_ordered_priority_queue_enqueue(dsc_ordered_priority_queue_t *ordered_priority_queue, void *data);
void *dsc_ordered_priority_queue_dequeue(dsc_ordered_priority_queue_t *ordered_priority_queue);
void *dsc_ordered_priority_queue_peek(dsc_ordered_priority_queue_t *ordered_priority_queue);

#endif