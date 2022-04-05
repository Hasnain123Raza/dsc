#ifndef TEST_DSC_ARRAY_STACK_H
#define TEST_DSC_ARRAY_STACK_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "array_stack.h"

int init_suite_array_stack(void);
int clean_suite_array_stack(void);
CU_ErrorCode prepare_suite_array_stack(void);

void test_array_stack_create(void);
void test_array_stack_free(void);
void test_array_stack_resize(void);
void test_array_stack_push(void);
void test_array_stack_pop(void);
void test_array_stack_peek(void);

#endif