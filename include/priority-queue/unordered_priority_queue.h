#ifndef DSC_UNORDERED_PRIORITY_QUEUE_H
#define DSC_UNORDERED_PRIORITY_QUEUE_H

#include "singly_linked_list.h"

/**
 * @file unordered_priority_queue.h
 * @brief Unordered priority queue
 * 
 * @details This file contains the unordered priority queue. It is a singly linked list
 * that contains the unordered elements. The enqueue operation is O(1). The dequeue operation
 * is O(n). The peek operation is O(n).
 * 
 * @author Hasnain Raza
 */

typedef int (*dsc_unordered_priority_queue_compare_func)(void *, void *); /**< Function pointer to compare the data */
typedef void (*dsc_unordered_priority_queue_free_func)(void *); /**< Function pointer to free the data */

/**
 * @brief Unordered priority queue structure
 * 
 * @details This structure represents the unordered priority queue.
 */
typedef struct {
    dsc_singly_linked_list_t *list; /**< Singly linked list */
    dsc_unordered_priority_queue_compare_func compare_func; /**< Function pointer to compare the data */
} dsc_unordered_priority_queue_t;

/**
 * @brief Creates the unordered priority queue
 * 
 * @details This function creates the unordered priority queue. The compare function is used to
 * prioritize the elements. The compare function should return 0 if the two elements have the same
 * priority. The compare function should return a negative number if the first element has a lower
 * priority than the second element. The compare function should return a positive number if the
 * first element has a higher priority than the second element. If the compare function is NULL, the
 * function returns NULL. If the free function is NULL, the data is not freed. If allocation fails,
 * the function returns NULL.
 * 
 * @param compare_func Function pointer to compare the data, can not be NULL
 * @param free_func Function pointer to free the data
 * @return dsc_unordered_priority_queue_t* Pointer to the unordered priority queue, NULL on failure
 */
dsc_unordered_priority_queue_t *dsc_unordered_priority_queue_create(dsc_unordered_priority_queue_compare_func compare_func, dsc_unordered_priority_queue_free_func free_func);
/**
 * @brief Frees the unordered priority queue
 * 
 * @details This function frees the unordered priority queue. If the free function is not NULL, the
 * data is freed.
 * 
 * @param unordered_priority_queue Pointer to the unordered priority queue, can not be NULL
 */
void dsc_unordered_priority_queue_free(dsc_unordered_priority_queue_t *unordered_priority_queue);

/**
 * @brief Enqueues the data to the unordered priority queue
 * 
 * @details This function enqueues the data to the unordered priority queue. If the data is NULL, the
 * function returns -1. If two elements have the same priority, the data is enqueued to the end of
 * the list. If allocation fails, the function returns -1. Otherwise, the function returns 0.
 * This function is O(1).
 * 
 * @param unordered_priority_queue Pointer to the unordered priority queue, can not be NULL
 * @param data Pointer to the data, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_unordered_priority_queue_enqueue(dsc_unordered_priority_queue_t *unordered_priority_queue, void *data);
/**
 * @brief Dequeues the data from the unordered priority queue
 * 
 * @details This function dequeues the data from the unordered priority queue. If the unordered
 * priority queue is empty, the function returns NULL. Otherwise the function returns the data.
 * This function is O(n).
 * 
 * @param unordered_priority_queue Pointer to the unordered priority queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_unordered_priority_queue_dequeue(dsc_unordered_priority_queue_t *unordered_priority_queue);
/**
 * @brief Peeks the data from the unordered priority queue
 * 
 * @details This function peeks the data from the unordered priority queue. If the unordered
 * priority queue is empty, the function returns NULL. Otherwise the function returns the data.
 * This function is O(n).
 * 
 * @param unordered_priority_queue Pointer to the unordered priority queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_unordered_priority_queue_peek(dsc_unordered_priority_queue_t *unordered_priority_queue);

#endif