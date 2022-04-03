#ifndef TEST_DSC_SINGLY_LINKED_LIST_H
#define TEST_DSC_SINGLY_LINKED_LIST_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "singly_linked_list.h"

int init_suite_singly_linked_list(void);
int clean_suite_singly_linked_list(void);
CU_ErrorCode prepare_suite_singly_linked_list();

void test_singly_linked_list_create(void);
void test_singly_linked_list_free(void);
void test_singly_linked_list_insert(void);
void test_singly_linked_list_remove(void);
void test_singly_linked_list_set(void);
void test_singly_linked_list_get(void);

#endif