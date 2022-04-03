#ifndef DSC_ARRAY_STACK_H
#define DSC_ARRAY_STACK_H

#include "dynamic_list.h"

/**
 * @file array_stack.h
 * @brief Array stack
 * 
 * @details This file contains the array stack. It is an array that can grow and shrink
 * when needed. Push and pop operations are O(1).
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_array_stack_free_func)(void *); /**< Function pointer to free the data */

typedef dsc_dynamic_list_t dsc_array_stack_t; /**< Array stack */

/**
 * @brief Initialize the array stack
 * 
 * @details This function initializes the array stack. Capacity can't be less than
 * DSC_DYNAMIC_LIST_INITIAL_CAPACITY. If the capacity is less than DSC_DYNAMIC_LIST_INITIAL_CAPACITY,
 * it is set to DSC_DYNAMIC_LIST_INITIAL_CAPACITY. If the free_func is NULL, the data is not freed.
 * If allocation fails, the function returns NULL.
 * 
 * @param capacity Initial capacity of the stack
 * @param free_func Function pointer to free the data
 * @return dsc_array_stack_t* Pointer to the array stack, NULL on failure
 */
dsc_array_stack_t *dsc_array_stack_create(int capacity, dsc_array_stack_free_func free_func);
/**
 * @brief Free the array stack
 * 
 * @details This function frees the array stack. If the free_func is not NULL, the data is freed.
 * 
 * @param array_stack Pointer to the array stack, can not be NULL
 */
void dsc_array_stack_free(dsc_array_stack_t *array_stack);
/**
 * @brief Resizes the array stack
 * 
 * @details This function resizes the array stack. If the new capacity is less than the current
 * size of the stack, the stack is not modified and the function returns -1. If the new capacity is
 * greater than the current capacity, the stack is resized and the function returns 0. If the new capacity
 * is less than DSC_DYNAMIC_LIST_INITIAL_CAPACITY, the stack is resized to DSC_DYNAMIC_LIST_INITIAL_CAPACITY
 * and the function returns 0. If the allocation fails, the function returns -1 and the stack is not
 * modified.
 * 
 * @param array_stack Pointer to the array stack, can not be NULL
 * @param capacity New capacity of the stack, can not be less than the current size of the stack
 * @return int 0 on success, -1 on failure
 */
int dsc_array_stack_resize(dsc_array_stack_t *array_stack, int capacity);

/**
 * @brief Push data to the array stack
 * 
 * @details This function pushes data to the array stack. If the array stack is full, the stack is
 * resized. The function returns 0 on success and -1 on failure. Failure can occur if the allocation
 * fails. This function is O(1).
 * 
 * @param array_stack Pointer to the array stack, can not be NULL
 * @param data Pointer to the data to be pushed, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_array_stack_push(dsc_array_stack_t *array_stack, void *data);
/**
 * @brief Pop data from the array stack
 * 
 * @details This function pops data from the array stack. If the array stack is empty, the function
 * returns NULL. The function returns the data popped from the stack. This function is O(1).
 * 
 * @param array_stack Pointer to the array stack, can not be NULL
 * @return void* Pointer to the data popped from the stack, NULL on failure
 */
void *dsc_array_stack_pop(dsc_array_stack_t *array_stack);
/**
 * @brief Peek data from the array stack
 * 
 * @details This function peeks data from the array stack. If the array stack is empty, the function
 * returns NULL. The function returns the data peeked from the stack. This function is O(1).
 * 
 * @param array_stack Pointer to the array stack, can not be NULL
 * @return void* Pointer to the data peeked from the stack, NULL on failure
 */
void *dsc_array_stack_peek(dsc_array_stack_t *array_stack);

#endif