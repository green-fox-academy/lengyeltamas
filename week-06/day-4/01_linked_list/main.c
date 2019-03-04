#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_node_t *test_list = create();

    for (int i = 1; i <= 10; ++i) {
        linked_list_push_back(test_list, (i * 2));
    }
    linked_list_print(test_list);

    test_list = linked_list_insert_to_beginning(test_list, 9);

    linked_list_print(test_list);

    test_list = linked_list_insert_to_beginning(test_list, 10000);

    linked_list_print(test_list);

    linked_list_dealloc(test_list);

    return 0;
}