#ifndef TEST_DSC_UNORDERED_PRIORITY_QUEUE_H
#define TEST_DSC_UNORDERED_PRIORITY_QUEUE_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "unordered_priority_queue.h"

int init_suite_unordered_priority_queue(void);
int clean_suite_unordered_priority_queue(void);
CU_ErrorCode prepare_suite_unordered_priority_queue(void);

void test_unordered_priority_queue_create(void);
void test_unordered_priority_queue_free(void);
void test_unordered_priority_queue_enqueue(void);
void test_unordered_priority_queue_dequeue(void);
void test_unordered_priority_queue_peek(void);

#endif