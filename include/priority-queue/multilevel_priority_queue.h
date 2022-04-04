#ifndef DSC_MULTILEVEL_PRIORITY_QUEUE_H
#define DSC_MULTILEVEL_PRIORITY_QUEUE_H

#include "singly_linked_list.h"

typedef int (*dsc_multilevel_priority_queue_compare_func)(void *, void *);
typedef void (*dsc_multilevel_priority_queue_free_func)(void *);

typedef struct {
    dsc_singly_linked_list_t **lists;
    dsc_multilevel_priority_queue_compare_func compare_func;
    int num_levels;
} dsc_multilevel_priority_queue_t;

dsc_multilevel_priority_queue_t *dsc_multilevel_priority_queue_create(int num_levels, dsc_multilevel_priority_queue_compare_func compare_func, dsc_multilevel_priority_queue_free_func free_func);
void dsc_multilevel_priority_queue_free(dsc_multilevel_priority_queue_t *multilevel_priority_queue);

int dsc_multilevel_priority_queue_enqueue(dsc_multilevel_priority_queue_t *multilevel_priority_queue, int level, void *data);
void *dsc_multilevel_priority_queue_dequeue(dsc_multilevel_priority_queue_t *multilevel_priority_queue);
void *dsc_multilevel_priority_queue_peek(dsc_multilevel_priority_queue_t *multilevel_priority_queue);

#endif