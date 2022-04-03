#ifndef DSC_LINKED_QUEUE_H
#define DSC_LINKED_QUEUE_H

#include "singly_linked_list.h"

/**
 * @file linked_queue.h
 * @brief Linked queue
 * 
 * @details This file contains the linked queue. It is a linked list of nodes. Enqueue
 * and dequeue operations are O(1).
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_linked_queue_free_func)(void *); /**< Function pointer to free the data */

typedef dsc_singly_linked_list_t dsc_linked_queue_t; /**< Linked queue */

/**
 * @brief Initialize the linked queue
 * 
 * @details This function initializes the linked queue. If the free_func is NULL, the data is not
 * freed. The function returns NULL if allocation fails.
 * 
 * @param free_func Function pointer to free the data
 * @return dsc_linked_queue_t* Pointer to the linked queue, NULL on failure
 */
dsc_linked_queue_t *dsc_linked_queue_create(dsc_linked_queue_free_func free_func);
/**
 * @brief Free the linked queue
 * 
 * @details This function frees the linked queue. If the free_func is not NULL, the data is freed.
 * 
 * @param linked_queue Pointer to the linked queue, can not be NULL
 */
void dsc_linked_queue_free(dsc_linked_queue_t *linked_queue);

/**
 * @brief Enqueue a node to the linked queue
 * 
 * @details This function enqueues a node to the linked queue. If allocation fails, the function
 * returns -1. This function is O(1).
 * 
 * @param linked_queue Pointer to the linked queue, can not be NULL
 * @param data Pointer to the data to be enqueued, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_linked_queue_enqueue(dsc_linked_queue_t *linked_queue, void *data);
/**
 * @brief Dequeue a node from the linked queue
 * 
 * @details This function dequeues a node from the linked queue. If the linked queue is empty, the
 * function returns NULL. This function is O(1).
 * 
 * @param linked_queue Pointer to the linked queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_linked_queue_dequeue(dsc_linked_queue_t *linked_queue);
/**
 * @brief Peek the front node from the linked queue
 * 
 * @details This function peeks the front node from the linked queue. If the linked queue is empty,
 * the function returns NULL. This function is O(1).
 * 
 * @param linked_queue Pointer to the linked queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_linked_queue_peek(dsc_linked_queue_t *linked_queue);

#endif