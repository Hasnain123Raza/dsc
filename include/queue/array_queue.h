#ifndef DSC_ARRAY_QUEUE_H
#define DSC_ARRAY_QUEUE_H

#include "dynamic_list.h"

/**
 * @file array_queue.h
 * @brief Array queue
 * 
 * @details This file contains the array queue. It is an array that can grow and shrink
 * when needed. Enqueue and dequeue operations are O(1).
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_array_queue_free_func)(void *); ///< Function pointer to free the data

/**
 * @brief Array queue structure
 * 
 * @details This structure represents the array queue.
 */
typedef struct {
    dsc_dynamic_list_t *list; /**< Dynamic list */
    int head; /**< Head of the queue */
    int tail; /**< Tail of the queue */
} dsc_array_queue_t;

/**
 * @brief Initialize the array queue
 * 
 * @details This function initializes the array queue. If the free_func is NULL, the data will not be freed.
 * If allocation fails, the function returns NULL.
 * 
 * @param capacity Initial capacity of the queue
 * @param free_func Function pointer to free the data
 * @return dsc_array_queue_t* Pointer to the array queue, NULL on failure
 */
dsc_array_queue_t *dsc_array_queue_create(dsc_array_queue_free_func free_func);
/**
 * @brief Frees the array queue
 * 
 * @details This function frees the array queue. If the free_func is not NULL, the data will be freed.
 * 
 * @param array_queue Pointer to the array queue
 */
void dsc_array_queue_free(dsc_array_queue_t *array_queue);

/**
 * @brief Enqueues the data to the array queue
 * 
 * @details This function enqueues the data to the array queue. If the array queue is full, the queue is resized
 * and the function returns 0. If the allocation fails, the function returns -1 and the queue is not modified.
 * This function is O(1).
 * 
 * @param array_queue Pointer to the array queue, can not be NULL
 * @param data Pointer to the data, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_array_queue_enqueue(dsc_array_queue_t *array_queue, void *data);
/**
 * @brief Dequeues the data from the array queue
 * 
 * @details This function dequeues the data from the array queue. If the array queue is empty, the function returns
 * NULL. The function returns the data popped from the queue. This function is O(1).
 * 
 * @param array_queue Pointer to the array queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_array_queue_dequeue(dsc_array_queue_t *array_queue);
/**
 * @brief Returns the front data from the array queue
 * 
 * @details This function returns the front data from the array queue. If the array queue is empty, the function
 * returns NULL. The function returns the data peeked from the queue. This function is O(1).
 * 
 * @param array_queue Pointer to the array queue, can not be NULL
 * @return void* Pointer to the data, NULL on failure
 */
void *dsc_array_queue_peek(dsc_array_queue_t *array_queue);

#endif