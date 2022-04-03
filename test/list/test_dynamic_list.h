#ifndef TEST_DSC_DYNAMIC_LIST_H
#define TEST_DSC_DYNAMIC_LIST_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "dynamic_list.h"

int init_suite_dynamic_list(void);
int clean_suite_dynamic_list(void);
CU_ErrorCode prepare_suite_dynamic_list();

void test_dynamic_list_create(void);
void test_dynamic_list_free(void);
void test_dynamic_list_resize(void);
void test_dynamic_list_insert(void);
void test_dynamic_list_remove(void);
void test_dynamic_list_set(void);
void test_dynamic_list_get(void);

#endif