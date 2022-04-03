#ifndef TEST_DSC_LINKED_QUEUE_H
#define TEST_DSC_LINKED_QUEUE_H

#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "linked_queue.h"

int init_suite_linked_queue(void);
int clean_suite_linked_queue(void);
CU_ErrorCode prepare_suite_linked_queue();

void test_linked_queue_create(void);
void test_linked_queue_free(void);
void test_linked_queue_enqueue(void);
void test_linked_queue_dequeue(void);
void test_linked_queue_peek(void);

#endif