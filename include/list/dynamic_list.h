#ifndef DSC_DYNAMIC_LIST_H
#define DSC_DYNAMIC_LIST_H

#include <stdlib.h>

/**
 * @file dynamic_list.h
 * @brief Dynamic list
 * 
 * @details This file contains the dynamic list. It is an array that can grow and shrink
 * when needed. Insert and remove operations are O(n).
 * 
 * @author Hasnain Raza
 */

#define DSC_DYNAMIC_LIST_INITIAL_CAPACITY 16 /**< Initial capacity of the list */

typedef void (*dsc_dynamic_list_free_func)(void *); /**< Function pointer to free the data */

/**
 * @brief Dynamic list structure
 * 
 * @details This structure represents the dynamic list.
 */
typedef struct {
    void **data; /**< Array of data */
    dsc_dynamic_list_free_func free_func; /**< Function pointer to free the data */
    int size; /**< Size of the list */
    int capacity; /**< Capacity of the list */
} dsc_dynamic_list_t;

/**
 * @brief Initialize the dynamic list
 * 
 * @details This function initializes the dynamic list. Capacity can't be less than
 * DSC_DYNAMIC_LIST_INITIAL_CAPACITY. If the capacity is less than DSC_DYNAMIC_LIST_INITIAL_CAPACITY,
 * it is set to DSC_DYNAMIC_LIST_INITIAL_CAPACITY. If the free_func is NULL, the data is not freed.
 * If allocation fails, the function returns NULL.
 * 
 * @param capacity Initial capacity of the list, can not be less than DSC_DYNAMIC_LIST_INITIAL_CAPACITY
 * @param free_func Function pointer to free the data
 * @return dsc_dynamic_list_t* Pointer to the dynamic list, NULL on failure
 */
dsc_dynamic_list_t *dsc_dynamic_list_create(int capacity, dsc_dynamic_list_free_func free_func);
/**
 * @brief Free the dynamic list
 * 
 * @details This function frees the dynamic list. If the free_func is not NULL, the data is freed.
 * Sets the data pointer to NULL.
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 */
void dsc_dynamic_list_free(dsc_dynamic_list_t *dynamic_list);
/**
 * @brief Resizes the dynamic list
 * 
 * @details This function resizes the dynamic list. If the new capacity is less than the current
 * size of the list, the list is not modified and the function returns -1. If the new capacity is
 * greater than the current capacity, the list is resized and the function returns 0. If the new
 * capacity is less than the DSC_DYNAMIC_LIST_INITIAL_CAPACITY, the list is resized to
 * DSC_DYNAMIC_LIST_INITIAL_CAPACITY and the function returns 0. If the allocation fails, the
 * function returns -1 and the list is not modified.
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 * @param capacity New capacity of the list, can not be less than the current size of the list
 * @return int 0 on success, -1 on failure
 */
int dsc_dynamic_list_resize(dsc_dynamic_list_t *dynamic_list, int capacity);

/**
 * @brief Inserts an element at the specified index
 * 
 * @details This function inserts an element at the specified index. If the index is out of bounds,
 * the function returns -1 and the list is not modified. If the index is equal to the size of the
 * list, the element is appended to the list. If the index is less than the size of the list, the
 * element is inserted at the specified index. If the list is full, the list is resized and the
 * function returns 0. If allocation fails, the function returns -1 and the list is not modified. This
 * function is O(n).
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 * @param index Index at which the element is to be inserted, must be within the bounds of the list
 * @param data Data to be inserted, can not be NULL
 * @return int 0 on success, -1 on failure
 */
int dsc_dynamic_list_insert(dsc_dynamic_list_t *dynamic_list, int index, void *data);
/**
 * @brief Removes the element at the specified index
 * 
 * @details This function removes the element at the specified index. If the index is out of bounds,
 * the function returns -1 and the list is not modified. If the index is less than the size of the
 * list, the element is removed from the specified index. If the list is half full, the list is
 * resized and the function returns 0. If the capacity is less than DSC_DYNAMIC_LIST_INITIAL_CAPACITY,
 * the list is not resized to a smaller size. The function is not affected by the failure of allocation.
 * This function is O(n).
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 * @param index Index at which the element is to be removed, must be within the bounds of the list
 * @return void* Data at the specified index, NULL on failure
 */
void *dsc_dynamic_list_remove(dsc_dynamic_list_t *dynamic_list, int index);
/**
 * @brief Gets the element at the specified index
 * 
 * @details This function gets the element at the specified index. If the index is out of bounds,
 * the function returns NULL. This function is O(1).
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 * @param index Index at which the element is to be removed, must be within the bounds of the list
 * @param data Data at the specified index, can not be NULL
 * @return void* Data at the specified index, NULL on failure
 */
void *dsc_dynamic_list_set(dsc_dynamic_list_t *dynamic_list, int index, void *data);
/**
 * @brief Gets the element at the specified index
 * 
 * @details This function gets the element at the specified index. If the index is out of bounds,
 * the function returns NULL. This function is O(1).
 * 
 * @param dynamic_list Pointer to the dynamic list, can not be NULL
 * @param index Index at which the element is to be removed, must be within the bounds of the list
 * @return void* Data at the specified index, NULL on failure
 */
void *dsc_dynamic_list_get(dsc_dynamic_list_t *dynamic_list, int index);

#endif