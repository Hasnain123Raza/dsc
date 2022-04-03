#include "dynamic_list.h"

dsc_dynamic_list_t *dsc_dynamic_list_create(int capacity, dsc_dynamic_list_free_func free_func) {
    dsc_dynamic_list_t *dynamic_list = (dsc_dynamic_list_t *)malloc(sizeof(dsc_dynamic_list_t));
    if (dynamic_list == NULL) {
        return NULL;
    }

    dynamic_list->capacity = ((capacity < DSC_DYNAMIC_LIST_INITIAL_CAPACITY) ? DSC_DYNAMIC_LIST_INITIAL_CAPACITY : capacity);
    dynamic_list->size = 0;
    dynamic_list->free_func = free_func;

    dynamic_list->data = (void **)malloc(sizeof(void *) * dynamic_list->capacity);
    if (dynamic_list->data == NULL) {
        free(dynamic_list);
        return NULL;
    }

    return dynamic_list;
}

void dsc_dynamic_list_free(dsc_dynamic_list_t *dynamic_list) {
    if (dynamic_list == NULL) {
        return;
    }

    if (dynamic_list->free_func != NULL) {
        for (int i = 0; i < dynamic_list->size; i++) {
            dynamic_list->free_func(dynamic_list->data[i]);
        }
    }

    free(dynamic_list->data);
    free(dynamic_list);
}

int dsc_dynamic_list_resize(dsc_dynamic_list_t *dynamic_list, int capacity) {
    if (capacity < DSC_DYNAMIC_LIST_INITIAL_CAPACITY) {
        capacity = DSC_DYNAMIC_LIST_INITIAL_CAPACITY;
    }

    if (dynamic_list == NULL || capacity < dynamic_list->size) {
        return -1;
    }

    void **data = (void **)realloc(dynamic_list->data, sizeof(void *) * capacity);
    if (data == NULL) {
        return -1;
    }

    dynamic_list->data = data;
    dynamic_list->capacity = capacity;

    return 0;
}



int dsc_dynamic_list_insert(dsc_dynamic_list_t *dynamic_list, int index, void *data) {
    if (dynamic_list == NULL || index < 0 || index > dynamic_list->size || data == NULL) {
        return -1;
    }

    if (dynamic_list->size == dynamic_list->capacity) {
        if (dsc_dynamic_list_resize(dynamic_list, dynamic_list->capacity * 2) < -1) {
            return -1;
        }
    }

    for (int i = dynamic_list->size; i > index; i--) {
        dynamic_list->data[i] = dynamic_list->data[i - 1];
    }

    dynamic_list->data[index] = data;
    dynamic_list->size++;

    return 0;
}

void *dsc_dynamic_list_remove(dsc_dynamic_list_t *dynamic_list, int index) {
    if (dynamic_list == NULL || index < 0 || index >= dynamic_list->size) {
        return NULL;
    }

    void *data = dynamic_list->data[index];

    for (int i = index; i < dynamic_list->size - 1; i++) {
        dynamic_list->data[i] = dynamic_list->data[i + 1];
    }

    dynamic_list->size--;

    if (dynamic_list->size <= (dynamic_list->capacity >> 1) && dynamic_list->capacity > DSC_DYNAMIC_LIST_INITIAL_CAPACITY) {
        dsc_dynamic_list_resize(dynamic_list, dynamic_list->capacity >> 1);
    }

    return data;
}

void *dsc_dynamic_list_set(dsc_dynamic_list_t *dynamic_list, int index, void *data) {
    if (dynamic_list == NULL || index < 0 || index >= dynamic_list->size || data == NULL) {
        return NULL;
    }

    void *old_data = dynamic_list->data[index];
    dynamic_list->data[index] = data;

    return old_data;
}

void *dsc_dynamic_list_get(dsc_dynamic_list_t *dynamic_list, int index) {
    if (dynamic_list == NULL || index < 0 || index >= dynamic_list->size) {
        return NULL;
    }

    return dynamic_list->data[index];
}