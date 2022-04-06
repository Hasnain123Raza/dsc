#ifndef DSC_MULTILEVEL_PRIORITY_QUEUE_H
#define DSC_MULTILEVEL_PRIORITY_QUEUE_H

#include "singly_linked_list.h"

/**
 * @file multilevel_priority_queue.h
 * @brief Multilevel priority queue
 * 
 * @details This file contains the multilevel priority queue. It is a static lis of linked lists that 
 * contains each representing a level and containing elements of a certain priority. The enqueue operation
 * is O(1). The dequeue operation is O(m). The peek operation is O(m). The m is the number of levels.
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_multilevel_priority_queue_free_func)(void *); /**< Function pointer to free the data */

/**
 * @brief Multilevel priority queue structure
 * 
 * @details This structure represents the multilevel priority queue.
 */
typedef struct {
    dsc_singly_linked_list_t **lists; /**< Pointer to the static list of level queues */
    int num_levels; /**< Number of levels */
} dsc_multilevel_priority_queue_t;

/**
 * @brief Creates the multilevel priority queue
 * 
 * @details This function creates the multilevel priority queue. If the free function is NULL, the data
 * is not freed. If allocation fails, the function returns NULL. The number of levels is the number of
 * levels in the multilevel priority queue.
 * 
 * @param num_levels Number of levels, must be greater than 0
 * @param free_func Function pointer to free the data
 * @return dsc_multilevel_priority_queue_t* Pointer to the multilevel priority queue, NULL on failure
 */
dsc_multilevel_priority_queue_t *dsc_multilevel_priority_queue_create(int num_levels, dsc_multilevel_priority_queue_free_func free_func);
/**
 * @brief Destroys the multilevel priority queue
 * 
 * @details This function frees the multilevel priority queue. The data is freed if the free function
 * is not NULL.
 * 
 * @param multilevel_priority_queue Pointer to the multilevel priority queue
 */
void dsc_multilevel_priority_queue_free(dsc_multilevel_priority_queue_t *multilevel_priority_queue);

/**
 * @brief Enqueues the data into the multilevel priority queue
 * 
 * @details This function enqueues the data into the multilevel priority queue. The data is enqueued
 * to the given level. If the multilevel priority queue is NULL, the function returns -1. If the data
 * is NULL, the function returns -1. If the level is out of bounds, the function returns -1.
 * 
 * @param multilevel_priority_queue Pointer to the multilevel priority queue
 * @param level Level to enqueue the data
 * @param data Data to enqueue
 * @return int 0 on success, -1 on failure
 */
int dsc_multilevel_priority_queue_enqueue(dsc_multilevel_priority_queue_t *multilevel_priority_queue, int level, void *data);
/**
 * @brief Dequeues the data from the multilevel priority queue
 * 
 * @details This function dequeues the data from the multilevel priority queue. The data is dequeued
 * from the highest available level. If the multilevel priority queue is NULL, the function returns NULL.
 * 
 * @param multilevel_priority_queue Pointer to the multilevel priority queue
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_multilevel_priority_queue_dequeue(dsc_multilevel_priority_queue_t *multilevel_priority_queue);
/**
 * @brief Peeks the data from the multilevel priority queue
 * 
 * @details This function peeks the data from the multilevel priority queue. The data is peeked from
 * the highest available level. If the multilevel priority queue is NULL, the function returns NULL.
 * 
 * @param multilevel_priority_queue Pointer to the multilevel priority queue
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_multilevel_priority_queue_peek(dsc_multilevel_priority_queue_t *multilevel_priority_queue);

#endif