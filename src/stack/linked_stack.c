#include "linked_stack.h"

dsc_linked_stack_t *dsc_linked_stack_create(dsc_linked_stack_free_func free_func) {
    return dsc_singly_linked_list_create(free_func);
}

void dsc_linked_stack_free(dsc_linked_stack_t *linked_stack) {
    dsc_singly_linked_list_free(linked_stack);
}



int dsc_linked_stack_push(dsc_linked_stack_t *linked_stack, void *data) {
    return dsc_singly_linked_list_insert(linked_stack, 0, data);
}

void *dsc_linked_stack_pop(dsc_linked_stack_t *linked_stack) {
    return dsc_singly_linked_list_remove(linked_stack, 0);
}

void *dsc_linked_stack_peek(dsc_linked_stack_t *linked_stack) {
    return dsc_singly_linked_list_get(linked_stack, 0);
}