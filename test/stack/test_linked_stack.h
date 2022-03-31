#ifndef TEST_LINKED_STACK_H
#define TEST_LINKED_STACK_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "linked_stack.h"

int init_suite_linked_stack(void);
int clean_suite_linked_stack(void);
CU_ErrorCode prepare_suite_linked_stack();

void test_linked_stack_create(void);
void test_linked_stack_free(void);
void test_linked_stack_push(void);
void test_linked_stack_pop(void);
void test_linked_stack_peek(void);

#endif