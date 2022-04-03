#ifndef DSC_SINGLY_LINKED_LIST_H
#define DSC_SINGLY_LINKED_LIST_H

#include <stdlib.h>

/**
 * @file singly_linked_list.h
 * @brief Singly linked list
 * 
 * @details This file contains the singly linked list. It is a linked list of nodes. Insert and
 * remove operations are O(n).
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_singly_linked_list_free_func)(void *); /**< Function pointer to free the data */

/**
 * @brief Singly linked list node structure
 * 
 * @details This structure represents the singly linked list node.
 */
typedef struct dsc_singly_linked_list_node_t {
    void *data; /**< Data of the node */
    struct dsc_singly_linked_list_node_t *next; /**< Pointer to the next node */
} dsc_singly_linked_list_node_t;

/**
 * @brief Singly linked list structure
 * 
 * @details This structure represents the singly linked list.
 */
typedef struct {
    dsc_singly_linked_list_node_t *head; /**< Pointer to the head node */
    dsc_singly_linked_list_node_t *tail; /**< Pointer to the tail node */
    dsc_singly_linked_list_free_func free_func; /**< Function pointer to free the data */
    int size; /**< Size of the list */
} dsc_singly_linked_list_t;

/**
 * @brief Initialize the singly linked list
 * 
 * @details This function initializes the singly linked list. If the free_func is NULL, the data is
 * not freed.
 * 
 * @param free_func Function pointer to free the data
 * @return dsc_singly_linked_list_t* Pointer to the singly linked list, NULL on failure
 */
dsc_singly_linked_list_t *dsc_singly_linked_list_create(dsc_singly_linked_list_free_func free_func);
/**
 * @brief Free the singly linked list
 * 
 * @details This function frees the singly linked list. If the free_func is not NULL, the data is
 * freed.
 * 
 * @param singly_linked_list Pointer to the singly linked list, can not be NULL
 */
void dsc_singly_linked_list_free(dsc_singly_linked_list_t *singly_linked_list);

/**
 * @brief Insert a node at the specified index of the singly linked list
 * 
 * @details This function inserts a node at the specified index of the singly linked list. If the
 * index is out of bounds, the function returns -1. If allocation fails, the function returns -1 and
 * the singly linked list is not modified. This function is O(n).
 * 
 * @param singly_linked_list Pointer to the singly linked list, can not be NULL
 * @param index Index of the node to insert, can not be less than 0
 * @param data Data of the node to insert, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_singly_linked_list_insert(dsc_singly_linked_list_t *singly_linked_list, int index, void *data);
/**
 * @brief Remove a node at the specified index of the singly linked list
 * 
 * @details This function removes a node at the specified index of the singly linked list. If the
 * index is out of bounds, the function returns NULL. This function is O(n).
 * 
 * @param singly_linked_list Pointer to the singly linked list, can not be NULL
 * @param index Index of the node to remove, can not be less than 0
 * @return void* Data of the removed node, NULL on failure
 */
void *dsc_singly_linked_list_remove(dsc_singly_linked_list_t *singly_linked_list, int index);
/**
 * @brief Set the data at the specified index of the singly linked list
 * 
 * @details This function sets the data at the specified index of the singly linked list. If the
 * index is out of bounds, the function returns NULL. This function is O(n).
 * 
 * @param singly_linked_list Pointer to the singly linked list, can not be NULL
 * @param index Index of the node to set, can not be out of bounds
 * @param data Data of the node to set, can not be NULL
 * @return void* Data of the node, NULL on failure
 */
void *dsc_singly_linked_list_set(dsc_singly_linked_list_t *singly_linked_list, int index, void *data);
/**
 * @brief Get the data at the specified index of the singly linked list
 * 
 * @details This function gets the data at the specified index of the singly linked list. If the
 * index is out of bounds, the function returns NULL. This function is O(n).
 * 
 * @param singly_linked_list Pointer to the singly linked list, can not be NULL
 * @param index Index of the node to get, can not be out of bounds
 * @return void* Data of the node, NULL on failure
 */
void *dsc_singly_linked_list_get(dsc_singly_linked_list_t *singly_linked_list, int index);

#endif