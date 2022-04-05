#ifndef TEST_DSC_MULTILEVEL_PRIORITY_QUEUE_H
#define TEST_DSC_MULTILEVEL_PRIORITY_QUEUE_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "multilevel_priority_queue.h"

int init_suite_multilevel_priority_queue(void);
int clean_suite_multilevel_priority_queue(void);
CU_ErrorCode prepare_suite_multilevel_priority_queue(void);

void test_multilevel_priority_queue_create(void);
void test_multilevel_priority_queue_free(void);
void test_multilevel_priority_queue_enqueue(void);
void test_multilevel_priority_queue_dequeue(void);
void test_multilevel_priority_queue_peek(void);

#endif