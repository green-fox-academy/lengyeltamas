#ifndef INC_01_LINKED_LIST_LINKED_LIST_H
#define INC_01_LINKED_LIST_LINKED_LIST_H

typedef struct linked_list_node
{
    int value;
    struct linked_list_node *next;
} linked_list_node_t;

linked_list_node_t *create();

void linked_list_push_back(linked_list_node_t *linked_list, int value);

#endif //INC_01_LINKED_LIST_LINKED_LIST_H