#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "singly_linked_list.h"

/**
 * @file linked_stack.h
 * @brief Linked stack
 * 
 * @details This file contains the linked stack. It is a linked list of nodes. Push and pop
 * operations are O(1).
 * 
 * @author Hasnain Raza
 */

typedef void (*dsc_linked_stack_free_func)(void *); /**< Function pointer to free the data */

typedef dsc_singly_linked_list_t dsc_linked_stack_t; /**< Linked stack */

/**
 * @brief Initialize the linked stack
 * 
 * @details This function initializes the linked stack. If the free_func is NULL, the data is not
 * freed.
 * 
 * @param free_func Function pointer to free the data
 * @return dsc_linked_stack_t* Pointer to the linked stack, NULL on failure
 */
dsc_linked_stack_t *dsc_linked_stack_create(dsc_linked_stack_free_func free_func);
/**
 * @brief Free the linked stack
 * 
 * @details This function frees the linked stack. If the free_func is not NULL, the data is freed.
 * 
 * @param linked_stack Pointer to the linked stack, can not be NULL
 */
void dsc_linked_stack_free(dsc_linked_stack_t *linked_stack);

/**
 * @brief Push a node to the top of the linked stack
 * 
 * @details This function pushes a node to the top of the linked stack. If allocation fails, the
 * linked stack is not modified and the function returns -1. This function is O(1).
 * 
 * @param linked_stack Pointer to the linked stack, can not be NULL
 * @param data Data of the node, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_linked_stack_push(dsc_linked_stack_t *linked_stack, void *data);
/**
 * @brief Pop a node from the top of the linked stack
 * 
 * @details This function pops a node from the top of the linked stack. If the linked stack is empty,
 * the function returns NULL. This function is O(1).
 * 
 * @param linked_stack Pointer to the linked stack, can not be NULL
 * @return void* Pointer to the data of the node, NULL on failure
 */
void *dsc_linked_stack_pop(dsc_linked_stack_t *linked_stack);
/**
 * @brief Peek the top node of the linked stack
 * 
 * @details This function peeks the top node of the linked stack. If the linked stack is empty, the
 * function returns NULL. This function is O(1).
 * 
 * @param linked_stack Pointer to the linked stack, can not be NULL
 * @return void* Pointer to the data of the node, NULL on failure
 */
void *dsc_linked_stack_peek(dsc_linked_stack_t *linked_stack);

#endif