#include <stdio.h>
#include <BCUnit/BCUnit.h>
#include <BCUnit/Basic.h>

#include "test_dynamic_list.h"
#include "test_singly_linked_list.h"
#include "test_array_stack.h"
#include "test_linked_stack.h"
#include "test_array_queue.h"
#include "test_linked_queue.h"
// #include "test_unordered_priority_queue.h"
// #include "test_ordered_priority_queue.h"
// #include "test_multilevel_priority_queue.h"

int main(int argc, char* argv[]) {
    FILE *fp = fopen("test/driver.trs", "w");
    fclose(fp);
    fp = fopen("test/driver.log", "a");
    fclose(fp);

    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    if ((prepare_suite_dynamic_list() != CUE_SUCCESS) ||
        (prepare_suite_singly_linked_list() != CUE_SUCCESS) ||
        (prepare_suite_array_stack() != CUE_SUCCESS) ||
        (prepare_suite_linked_stack() != CUE_SUCCESS) ||
        (prepare_suite_array_queue() != CUE_SUCCESS) ||
        (prepare_suite_linked_queue() != CUE_SUCCESS) // ||
        // (prepare_suite_unordered_priority_queue() != CUE_SUCCESS) ||
        // (prepare_suite_ordered_priority_queue() != CUE_SUCCESS) ||
        // (prepare_suite_multilevel_priority_queue() != CUE_SUCCESS)
        ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}