#ifndef INC_01_LINKED_LIST_LINKED_LIST_H
#define INC_01_LINKED_LIST_LINKED_LIST_H

typedef struct linked_list_node
{
    int value;
    struct linked_list_node *next;
} linked_list_node_t;

linked_list_node_t *create();

void linked_list_push_back(linked_list_node_t *linked_list, int value);

void linked_list_print(linked_list_node_t *lined_list);

linked_list_node_t* linked_list_insert_to_beginning(linked_list_node_t *linked_list, int value);

linked_list_node_t *insert_after(linked_list_node_t*, int value);

void linked_list_dealloc(linked_list_node_t *linked_list);

#endif //INC_01_LINKED_LIST_LINKED_LIST_H