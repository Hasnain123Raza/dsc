include_HEADERS = \
    include/list/dynamic_list.h \
    include/list/singly_linked_list.h \
    include/stack/array_stack.h \
    include/stack/linked_stack.h \
    include/queue/array_queue.h \
    include/queue/linked_queue.h \
    #include/priority-queue/unordered_priority_queue.h \
    include/priority-queue/ordered_priority_queue.h \
    include/priority-queue/multilevel_priority_queue.h

lib_LIBRARIES = libdsc.a
libdsc_a_CPPFLAGS = \
    -I$(top_srcdir)/include/list \
    -I$(top_srcdir)/include/stack \
    -I$(top_srcdir)/include/queue \
    -I$(top_srcdir)/include/priority-queue
libdsc_a_SOURCES = \
    src/list/dynamic_list.c \
    src/list/singly_linked_list.c \
    src/stack/array_stack.c \
    src/stack/linked_stack.c \
    src/queue/array_queue.c \
    src/queue/linked_queue.c \
    #src/priority-queue/unordered_priority_queue.c \
    src/priority-queue/ordered_priority_queue.c \
    src/priority-queue/multilevel_priority_queue.c

check_PROGRAMS = test/driver
test_driver_SOURCES = test/driver.c \
    test/list/test_dynamic_list.h \
    test/list/test_dynamic_list.c \
    test/list/test_singly_linked_list.h \
    test/list/test_singly_linked_list.c \
    test/stack/test_array_stack.h \
    test/stack/test_array_stack.c \
    test/stack/test_linked_stack.h \
    test/stack/test_linked_stack.c \
    test/queue/test_array_queue.h \
    test/queue/test_array_queue.c \
    test/queue/test_linked_queue.h \
    test/queue/test_linked_queue.c \
    #test/priority-queue/test_unordered_priority_queue.h \
    test/priority-queue/test_unordered_priority_queue.c \
    test/priority-queue/test_ordered_priority_queue.h \
    test/priority-queue/test_ordered_priority_queue.c \
    test/priority-queue/test_multilevel_priority_queue.h \
    test/priority-queue/test_multilevel_priority_queue.c
test_driver_CPPFLAGS = \
    -I$(top_srcdir)/include/list \
    -I$(top_srcdir)/include/stack \
    -I$(top_srcdir)/include/queue \
    -I$(top_srcdir)/include/priority-queue \
    -I$(top_srcdir)/test/list \
    -I$(top_srcdir)/test/stack \
    -I$(top_srcdir)/test/queue \
    -I$(top_srcdir)/test/priority-queue
test_driver_LDADD = libdsc.a -lbcunit

TESTS = test/driver
LOG_DRIVER = test/driver