#ifndef TEST_DSC_ARRAY_QUEUE_H
#define TEST_DSC_ARRAY_QUEUE_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "array_queue.h"

int init_suite_array_queue(void);
int clean_suite_array_queue(void);
CU_ErrorCode prepare_suite_array_queue(void);

void test_array_queue_create(void);
void test_array_queue_free(void);
void test_array_queue_resize(void);
void test_array_queue_enqueue(void);
void test_array_queue_dequeue(void);
void test_array_queue_peek(void);

#endif