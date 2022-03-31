#include "singly_linked_list.h"

dsc_singly_linked_list_t *dsc_singly_linked_list_create(dsc_singly_linked_list_free_func free_func) {
    dsc_singly_linked_list_t *singly_linked_list = (dsc_singly_linked_list_t *)malloc(sizeof(dsc_singly_linked_list_t));
    if (singly_linked_list == NULL) {
        return NULL;
    }

    singly_linked_list->free_func = free_func;
    singly_linked_list->size = 0;
    singly_linked_list->head = NULL;
    singly_linked_list->tail = NULL;

    return singly_linked_list;
}

void dsc_singly_linked_list_free(dsc_singly_linked_list_t *singly_linked_list) {
    if (singly_linked_list == NULL) {
        return;
    }

    if (singly_linked_list->free_func != NULL) {
        dsc_singly_linked_list_node_t *node = singly_linked_list->head;
        while (node != NULL) {
            dsc_singly_linked_list_node_t *next = node->next;
            singly_linked_list->free_func(node->data);
            free(node);
            node = next;
        }
    } else {
        dsc_singly_linked_list_node_t *node = singly_linked_list->head;
        while (node != NULL) {
            dsc_singly_linked_list_node_t *next = node->next;
            free(node);
            node = next;
        }
    }

    free(singly_linked_list);
}



int dsc_singly_linked_list_insert(dsc_singly_linked_list_t *singly_linked_list, int index, void *data) {
    if (singly_linked_list == NULL || index < 0 || index > singly_linked_list->size || data == NULL) {
        return -1;
    }

    dsc_singly_linked_list_node_t *node = (dsc_singly_linked_list_node_t *)malloc(sizeof(dsc_singly_linked_list_node_t));
    if (node == NULL) {
        return -1;
    }

    node->data = data;
    node->next = NULL;

    if (singly_linked_list->size == 0) {
        singly_linked_list->head = node;
        singly_linked_list->tail = node;
    } else if (index == 0) {
        node->next = singly_linked_list->head;
        singly_linked_list->head = node;
    } else if (index == singly_linked_list->size) {
        singly_linked_list->tail->next = node;
        singly_linked_list->tail = node;
    } else {
        dsc_singly_linked_list_node_t *prev = singly_linked_list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        node->next = prev->next;
        prev->next = node;
    }

    singly_linked_list->size++;

    return 0;
}

void *dsc_singly_linked_list_remove(dsc_singly_linked_list_t *singly_linked_list, int index) {
    if (singly_linked_list == NULL || index < 0 || index >= singly_linked_list->size) {
        return NULL;
    }

    if (singly_linked_list->size == 1) {
        void *data = singly_linked_list->head->data;
        free(singly_linked_list->head);
        singly_linked_list->head = NULL;
        singly_linked_list->tail = NULL;
        singly_linked_list->size = 0;
        return data;
    }

    if (index == 0) {
        void *data = singly_linked_list->head->data;
        dsc_singly_linked_list_node_t *next = singly_linked_list->head->next;
        free(singly_linked_list->head);
        singly_linked_list->head = next;
        singly_linked_list->size--;
        return data;
    }

    dsc_singly_linked_list_node_t *prev = singly_linked_list->head;
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next;
    }

    dsc_singly_linked_list_node_t *node = prev->next;
    prev->next = node->next;

    void *data = node->data;
    free(node);
    singly_linked_list->size--;

    if (index == singly_linked_list->size) {
        singly_linked_list->tail = prev;
    }

    return data;
}

void *dsc_singly_linked_list_set(dsc_singly_linked_list_t *singly_linked_list, int index, void *data) {
    if (singly_linked_list == NULL || index < 0 || index >= singly_linked_list->size || data == NULL) {
        return NULL;
    }

    dsc_singly_linked_list_node_t *node = singly_linked_list->head;
    if (index == singly_linked_list->size - 1) {
        node = singly_linked_list->tail;
    } else {
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    }

    void *old_data = node->data;
    node->data = data;

    return old_data;
}

void *dsc_singly_linked_list_get(dsc_singly_linked_list_t *singly_linked_list, int index) {
    if (singly_linked_list == NULL || index < 0 || index >= singly_linked_list->size) {
        return NULL;
    }

    dsc_singly_linked_list_node_t *node = singly_linked_list->head;
    if (index == singly_linked_list->size - 1) {
        node = singly_linked_list->tail;
    } else {
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    }

    return node->data;
}