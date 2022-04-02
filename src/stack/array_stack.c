#include "array_stack.h"

dsc_array_stack_t *dsc_array_stack_create(int capacity, dsc_array_stack_free_func free_func) {
    return dsc_dynamic_list_create(capacity, free_func);
}

void dsc_array_stack_free(dsc_array_stack_t *array_stack) {
    dsc_dynamic_list_free(array_stack);
}

int dsc_array_stack_resize(dsc_array_stack_t *array_stack, int capacity) {
    return dsc_dynamic_list_resize(array_stack, capacity);
}



int dsc_array_stack_push(dsc_array_stack_t *array_stack, void *data) {
    return dsc_dynamic_list_insert(array_stack, array_stack->size, data);
}

void *dsc_array_stack_pop(dsc_array_stack_t *array_stack) {
    return dsc_dynamic_list_remove(array_stack, array_stack->size - 1);
}

void *dsc_array_stack_peek(dsc_array_stack_t *array_stack) {
    return dsc_dynamic_list_get(array_stack, array_stack->size - 1);
}